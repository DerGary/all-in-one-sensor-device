# All-In-One Smart Home Sensor Case V2

[Makerworld](https://makerworld.com/de/models/2180710-all-in-one-smart-home-sensor-case-v2#profileId-2381634)

## Please read the disclaimer at the bottom before printing

Hello everyone 👋, this has been one of my biggest projects so far. If you have any questions about the project please ask them in the comments then I can answer them and everyone can learn from that.

When I started building my smart home, I realized that most devices only cover very specific use cases. To get full functionality in each room, you usually need to buy multiple different devices.

My goal with this project was to create **the ultimate DIY smart home sensor device** that integrates all the essential sensors needed to achieve the following:

## 🎯 Goals

1. Control the lighting in a room by turning it on when motion is detected and keeping it on as long as someone is present (even if the person is not moving).
1. Monitor the brightness in the room and only turn lights on if needed (and off again when no longer required).
1. Measure air quality, humidity, and temperature.
1. Use Bluetooth to track a person’s smartphone and thereby determine which room they are in, so the smart home can react accordingly.
1. Keep the footprint as small as possible.
1. Powered by a single cable. USB-C in particular.
1. Ensure the design is unobtrusive and blends seamlessly into the living room.
1. Integrate with Home Assistant.
1. No cloud dependency.

## 🖨️ Print Instructions

- **Material:** PLA/PETG
- **Layer Height:** 0.20 mm
- **Nozzle:** 0.4 mm
- **Infill:** 15 %
- **Walls:** 2
- **Divider:** print **upright** with a **brim**, flat side on the build plate. If you orient it differently, it won’t print correctly.
- **Brightness sensor shield:** print with **transparent** material, or omit it entirely. It’s not required but hides the sensor a bit and improves the look.

## 🛠️ Assembly Instructions

1. Download the V2 assembly instructions PDF from below
2. Follow the assembly instructions in the PDF file

## 🆕 Changelog

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

### ⚠️ Disclaimer

This project is **not easy**: you have to solder a lot, including **very small** pins. You have been warned — but I’d love to see people try it 😊

The finished product is not perfect — that’s why the title is not *“Ultimate Smart Home Sensor Device”* 😅. I plan to release a revised version with other sensors when I have time and when the sensors I want become more accessible. Since I don’t know when that will be, I’m sharing this version for now.

**Things that bug me on the current version:**

1. **(This got a lot better on the V2 version, to a point where its not really an issue anymore, but it might happen and therefore is still listed here)** The motion sensor is very cheap and sometimes triggers when no one is in the room. (This can be minimized by **reducing the ESP’s Wi-Fi signal strength**, as cheap motion sensors are prone to misfire due to Wi-Fi interference.)
1. The motion sensor can trigger when you **air the room**, as it detects heat changes.
1. The presence sensor uses **24 GHz**. While it can detect mostly stationary humans, it cannot detect **very small movements** or someone under a blanket. (This mostly applies to my girlfriend — somehow I am tracked a bit better 😅).
1. The presence sensor is **extremely hard to solder**. I actually broke a sensor by accidentally desoldering the resistor right next to the pins. I now solder the wires directly to the pins which is janky but it works and is a lot easier.
