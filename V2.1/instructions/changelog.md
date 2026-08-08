## 🆕 Changelog

### V2.1.4

1. Add a Firmware version diagnostic sensor, showing the flashed release version in Home Assistant
1. Add OpenThread as a connectivity alternative to WiFi (esp32c6 variant, requires a local build with your own OTBR TLV)
1. Update ESPHome to 2026.7

### V2.1.3

1. Occupancy LED color adjusted to a lighter, more neutral warm white
1. The Occupied sensor now turns back on if presence is detected within 10 seconds of it turning off
1. Update ESPHome to 2026.6
1. BME680 air quality status now uses translated labels ("Good", "Warning", "Critical") instead of hardcoded English strings

### V2.1.2

1. Air quality state is now always visible in Home Assistant (no longer hidden by default)
1. Air quality state now shows translated values ("Good", "Warning", "Critical") instead of internal strings
1. Air quality state and occupancy no longer show "unknown" after the device boots — they start at "Good" and "not occupied" immediately
1. Humidity is now clamped to 0–100% so offset calibration can never push the value out of range
1. All Home Assistant entities now have icons

### V2.1.1

1. Changed LD2410B seat to reduce reflections.
    - If you had any problems with the ld2410b detecting very high values while no one is in the room, this will fix it.
    - I now got idle values of 3-5%.
    - It makes such a huge difference, that I even upgraded all fronts of my sensors to this new version
2. Changed LED automation colors slightly
    - Color for occupancy is now warm white
    - effect of occupancy is now explicitly "none"
3. Updated Instructions accordingly

### V2.1.0

1. Add an LED to show status for e.g. Improv BLE
1. Smaller Enclosure for the ESP32 Large variant
1. Software changes
    - Precompiled binaries
    - Add Improv BLE instead of captive Portal
    - No need to change any secrets or variables
    - An optional occupancy automation which shows the occupancy status via the status led
    - An optional air quality automation which shows the air quality status via the status led

### V2.0.0

1. 3 different versions for different boards
    - Version for the ESP32 D1 Mini (no need to desolder the pins anymore 🥳).
    - Version for the ESP32 Super Mini (it should work with ESP32 C3/C6/S3, but i only tested it with the C6)
    - Version for the ESP32 Large Version
1. No need for jumper headers and wires / everything is soldered so it is a more secure connection
1. Separated wifi antenna and motion sensor farther apart to reduce false positive detections
1. Incorporate the ball head mount into the design, which is fully printable now and does not need a screw anymore.
1. The brightness sensor shield is now a solid part of the body. To print it you need an AMS or you have to remove that part before printing.
1. Tweaked the software
    - easier calibration experience
    - use of esp-idf framework which results in way less memory usage, so more features can be activated
    - added captive portal out of the box
    - german and english variant
    - used other uart pins, because using the uart0 will hinder from flashing the device via usb
