### ⚠️ Disclaimer

This project is **not easy**: you have to solder a lot. You have been warned — but I’d love to see people try it 😊

The finished product is not perfect — that’s why the title is not *“Ultimate Smart Home Sensor Device”* 😅. I plan to release a revised version with other sensors when I have time and when the sensors I want become more accessible. Since I don’t know when that will be, I’m sharing this version for now.

**Things that bug me on the current version:**

1. **(This got a lot better on the V2 version, to a point where its not really an issue anymore, but it might happen and therefore is still listed here)** The motion sensor is very cheap and sometimes triggers when no one is in the room. (This can be minimized by **reducing the ESP’s Wi-Fi signal strength**, as cheap motion sensors are prone to misfire due to Wi-Fi interference.)
    - My latest firmware contains an optional slider to set the max wifi power. I recommend using the lowest value possible that still enables a stable wifi connection.
1. The motion sensor can trigger when you **air the room**, as it detects heat changes.
1. The presence sensor uses **24 GHz**. While it can detect mostly stationary humans, it cannot detect **very small movements** or someone under a blanket. (This mostly applies to my girlfriend — somehow I am tracked a bit better 😅).
1. The presence sensor is **extremely hard to solder**. I actually broke a sensor by accidentally desoldering the resistor right next to the pins. That is why I recommend using the separately available cable for it.
