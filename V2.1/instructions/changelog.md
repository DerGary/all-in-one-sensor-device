## 🆕 Changelog

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
