# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

This repo is a DIY "All-In-One Smart Home Sensor" — an ESP32 + [ESPHome](https://esphome.io/) firmware combined with a 3D-printed enclosure, designed for Home Assistant integration. It has gone through multiple hardware/software revisions, each living in its own top-level folder:

- `V1/` — oldest revision, BME280/BME680 only, self-contained (not actively developed).
- `V2/` — uses its own `common.yaml` and `secrets.yaml`-based config (legacy, not shared with the rest of the tree).
- `V2.1/` — current "All-In-One Sensor", entry point `V2.1/device.yaml`. Shares the root `common.yaml`/`sensors/`/`lang/`/`automations/`.
- `Ultimate/` — newest/most actively developed revision, entry point `Ultimate/device.yaml`. Adds LD2450 + C4001 dual presence sensing, status LED, more env sensors. Also shares the root `common.yaml`/`sensors/`/`lang/`/`automations/`.

When asked to make changes, check which revision(s) are affected — most active work targets `Ultimate/`. Changes to `sensors/`, `lang/`, `automations/`, or `common.yaml` affect both `V2.1` and `Ultimate` (and CI for both will run), so verify nothing breaks for either.

## Architecture: ESPHome packages

Each device's `device.yaml` is a thin composition root that pulls in reusable pieces via ESPHome's `packages:` + `!include` with `vars:`. There is no real templating/looping in ESPHome YAML — repetition (e.g. 3 LD2450 zones, 3 LD2450 targets) is written out by hand.

- `common.yaml` (root) — shared base: `esphome:`/`esp32:` block, BLE tracker, bluetooth proxy, `api:`, `ota:`, `wifi:`, `esp32_improv` (BLE provisioning, no captive portal/secrets.yaml in V2.1/Ultimate), uptime/free-memory/wifi-signal diagnostics, temperature/humidity offset numbers, restart button.
- `lang/{de,en}.yaml` — all user-facing entity name strings live here as substitution variables (`label_*`). Sensor/automation YAML files reference `${label_foo}` rather than hardcoding text, so the same YAML works in both languages. When adding a new entity, add the label to **both** `lang/de.yaml` and `lang/en.yaml` — don't hardcode names in `sensors/`/`automations/` files. Remove labels that become unused (grep first to confirm no other file uses them).
- `sensors/*.yaml` — one file per physical sensor/peripheral (`bh1750.yaml`, `sht4x.yaml`, `scd4x.yaml`, `sgp30.yaml`, `c4001.yaml`, `ld2450.yaml`, `ekmc_motion.yaml`, `ws2812.yaml`, etc.). Each typically takes `vars:` for pin assignment and defines its own `binary_sensor:`/`sensor:`/`number:`/etc. blocks. Cross-file references use fixed `id:`s (e.g. `id(temperature)`, `id(motion)`, `id(presence)`), so renaming an id requires checking all consumers.
- `automations/*.yaml` — cross-sensor logic: `status_led.yaml` (LED color/effect state machine, occupancy template binary sensor combining motion + presence), `set_air_quality_status_*.yaml` (thresholds on CO2/TVOC → "critical"/"warning"/"" state), `control_leds*.yaml`.
- `components/c4001/` — a custom external ESPHome component (C++ + Python `__init__.py`), loaded via `external_components: source: {type: local, path: ...}` from `sensors/c4001.yaml`.
- `Ultimate/instructions/` (and similarly `V2.1/instructions/`) — markdown source split into `intro.md` / `changelog.md` / `body.md` / `disclaimer.md`, concatenated and rendered to PDF via `renderPdf.sh` (uses `md-to-pdf`). The PDF itself (`*.pdf`) is gitignored/build-only — **only edit the `.md` sources**, never hand-edit the PDF. `README.md` in each device folder uses Obsidian-style `![[./instructions/intro]]` transclusion syntax (this is for the Makerworld page renderer, not GitHub).

### Entity naming / web UI conventions (Ultimate, and similar elsewhere)

- Entities are grouped in the built-in `web_server` (v3) UI via `sorting_groups` (e.g. `ld2450_group`, `c4001_group`) — new entities for a sensor should set `web_server.sorting_group_id` accordingly.
- Most diagnostic/per-target sensors are `disabled_by_default: true` to avoid flooding the HA entity list and recorder; only the entities someone actually needs by default (e.g. overall presence, key config numbers) are enabled.
- Names are built from `${label_*}` substitutions, generally `"<SENSOR> ${label_x} ${label_y}..."`.

### Working with external ESPHome components (important gotcha)

Several sensors (`c4001`, `ld2450`) rely on external components rather than ESPHome core. When wiring up a third-party external component:

- Check it actually compiles against the currently pinned ESPHome version before assuming a tagged release works — components can lag behind ESPHome core API changes (this has happened with the LD2450 component: see the comment block at the top of `sensors/ld2450.yaml` for a concrete example of pinning to a contributor's fix branch instead of the official tag, and why).
- Some components have validation-ordering bugs where a "duplicate entity name" check runs against the *raw* user-provided name before the component's own auto-naming/prefixing logic mutates it — i.e. giving two sibling entities the same literal `name:` string can fail even if the component would have produced unique final names. If you hit unexplained "Duplicate entity" errors from an external component, try omitting `name:` and letting the component's own default-naming apply, or give each raw name a unique literal value, rather than trusting the documented auto-naming/prefixing behavior to also avoid the duplicate check.
- Always validate changes with `esphome config <file>` and a full `esphome compile <file>` (see below) — don't assume a YAML change is correct just because it parses.
- When verifying entity names from `esphome config` output with `lang: de`, German umlauts (ö, ü, ä) cause grep to treat the stream as binary and silently drop matching lines. Pipe through `tr -cd '[:print:]\n'` before grepping, or use `-c` (count) to confirm the expected number of matches.
- The cached C++ source for external components lives under `.esphome/external_components/<hash>/components/`. Reading it directly is the fastest way to verify actual runtime behavior (e.g. what a component publishes to sensors under edge-case conditions) rather than guessing from the YAML schema.

## Commands

ESPHome must be installed (`pip install esphome`); no other build tooling is required for firmware work.

```sh
# Validate a config without compiling (fast)
esphome config Ultimate/device.yaml

# Full compile (slow, ~1-2 min) - the real correctness check, since `config` alone
# won't catch C++ codegen/compilation errors in external components or lambdas
esphome compile Ultimate/device.yaml

# Flash + view logs against a real device, with substitution overrides
esphome -s lang en -s temp sht4x run Ultimate/device.yaml
esphome -s lang en -s temp sht4x run Ultimate/device.yaml --device <ip-or-port>

# Same pattern for V2.1 (note the extra `variant` substitution: esp32 | esp32c6)
esphome -s lang de -s temp bme680 -s variant esp32 run V2.1/device.yaml
```

Substitutions available per device (see each `device.yaml`'s `packages:` vars and CI matrix for the full set):
- `Ultimate/device.yaml`: `lang` (`de`|`en`), `temp` (`sht4x`|`bme280`).
- `V2.1/device.yaml`: `lang` (`de`|`en`), `temp` (`bme680`|`bme280`), `variant` (`esp32`|`esp32c6`).

`<device>/compileAndUpdate.sh` files are local, gitignored scripts with hardcoded per-room device IPs for `esphome run --device <ip>` OTA updates — not committed source, don't rely on them existing or being accurate.

To rebuild the instructions PDF locally after editing markdown:

```sh
cd Ultimate/instructions && bash renderPdf.sh   # or V2.1/instructions
```

(Requires `md-to-pdf` installed globally: `npm i -g md-to-pdf`, plus a Chromium install — this matches what CI does.)

## Planned work

See `TODO.md` for tracked follow-ups (currently: changelog cleanup, adding OpenThread as a connectivity alternative to WiFi for V2.1/Ultimate).

## CI

GitHub Actions workflows (`.github/workflows/{ultimate-ci,v2-1-ci,v2-0-ci}.yaml`) trigger on PRs touching their device folder (plus the shared `sensors/`, `lang/`, `automations/`, `components/` for Ultimate/V2.1) and on version-prefixed tag pushes (`ultimate*`, `v2.1*`, `v2.0*`). Each compiles the full build matrix (language × temperature sensor × board variant, where applicable) using the `esphome/esphome:stable` container image, renders the instructions PDF, and on a tag push attaches binaries + the PDF to a GitHub Release. There is no separate lint/test step — successful `esphome compile` across the matrix *is* the correctness check.
