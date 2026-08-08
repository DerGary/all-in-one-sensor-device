# TODO

## Calibration

- Add gain (multiplier) number entities for temperature and humidity alongside the existing offset entities, enabling proper linear calibration (`raw × gain + offset`). A pure offset assumes a constant error across the full range; gain+offset handles sensors whose error scales with the measured value. Both entities would be runtime-configurable from HA (default gain: 1.0, no reflashing needed). Requires two reference measurements at different values to derive both parameters.
