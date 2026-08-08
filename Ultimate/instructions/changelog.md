
## 🆕 Changelog

### v1.0.4

1. Update ESPHome to 2026.7

### v1.0.3

1. Add OpenThread as a connectivity alternative to WiFi (esp32c6 variant, requires a local build with your own OTBR TLV)

### v1.0.2

1. Add a Firmware version diagnostic sensor, showing the flashed release version in Home Assistant

### v1.0.1

1. Occupancy LED color adjusted to a lighter, more neutral warm white
1. The Occupied sensor now turns back on if presence is detected within 10 seconds of it turning off
1. Update ESPHome to 2026.6

### What it does better than the All-In-One Smart Home Sensor Case V2

1. Multi-person, zone-based presence tracking: The LD2450 allows tracking multiple people simultaneously and triggering automations based on their position within defined room zones.
1. Improved still-presence detection: The C4001 sensor provides significantly more reliable detection of stationary occupants, even at greater distances.
1. Reduced false positives: The Panasonic PIR sensor is substantially less prone to false triggers compared to the PIR used in the previous version.
1. True CO₂ measurements: The SCD40 measures actual CO₂ concentration. In contrast, the BME680 used previously only estimated CO₂ based on VOC readings and responded more slowly to changes.
1. More capable MCU: The ESP32-C6 adds Wi‑Fi 6 support and integrated Zigbee hardware (Zigbee is not yet enabled in software).
1. Status LED integration: A built-in status LED can be used, for example, to provide immediate visual feedback when indoor air quality degrades.
1. Higher accuracy and stability for environmental sensing: The SHT41 (temperature & humidity) and SGP30 (VOC) replace the BME680 to achieve faster response times, better long-term stability, and more reliable measurements.

### What it does worse than the All-In-One Smart Home Sensor Case V2

1. Slightly larger physical footprint.
1. Higher overall cost (approximately €60-70 for the sensors excluding shipping).
1. Increased power consumption.
1. Greater assembly complexity due to a higher number of sensors and solder joints.
1. Limited board compatibility: only ESP32 Super Mini and DFRobot Beetle are supported (no D1 Mini or ESP32 Large variants).
