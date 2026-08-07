# TODO

## General

- Add a Text Sensor which gets feed from substitutions that always show the current Version of the Sensor

## Changelog

- Create a changelog file in V2 (old version) and reference/include it from the V2.1 changelog
- Add a V2 changelog entry documenting TheDiffi's OpenThread support contribution (#6)

## Calibration

- Add gain (multiplier) number entities for temperature and humidity alongside the existing offset entities, enabling proper linear calibration (`raw × gain + offset`). A pure offset assumes a constant error across the full range; gain+offset handles sensors whose error scales with the measured value. Both entities would be runtime-configurable from HA (default gain: 1.0, no reflashing needed). Requires two reference measurements at different values to derive both parameters.
