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
