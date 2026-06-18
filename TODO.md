# TODO

## Changelog

- Create a changelog file in V2 (old version) and reference/include it from the V2.1 changelog
- Add a V2 changelog entry documenting TheDiffi's OpenThread support contribution (#6)

## OpenThread Support

- Adapt V2.1 to support OpenThread as a connectivity alternative (in the style of TheDiffi's PR #6 for V2):
  - Extract WiFi + BLE/BT proxy into `connectivity/wifi.yaml` (already exists from #6)
  - Ensure `connectivity/thread.yaml` works for the esp32c6 variant in V2.1
  - Note: V2.1 uses `esp32_improv` (BLE provisioning) instead of secrets.yaml + captive portal — `wifi.yaml` for V2.1 will look different from the V2 version
- Adapt Ultimate to support OpenThread as a connectivity alternative (same approach as V2.1)

## Calibration

- Add gain (multiplier) number entities for temperature and humidity alongside the existing offset entities, enabling proper linear calibration (`raw × gain + offset`). A pure offset assumes a constant error across the full range; gain+offset handles sensors whose error scales with the measured value. Both entities would be runtime-configurable from HA (default gain: 1.0, no reflashing needed). Requires two reference measurements at different values to derive both parameters.
