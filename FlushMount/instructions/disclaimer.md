### ⚠️ Disclaimer

**Mains voltage:** this device contains a power supply that is connected to 230 V inside the wall box. Only a qualified electrician may connect it to mains. Switch off and verify the circuit before working on the wall box. I share this design as it is, without any warranty — you build and install it at your own risk.

This project is **not easy**: you have to solder a lot, in a very small space. You have been warned — but I’d love to see people try it 😊

**Things to keep in mind:**

1. The motion sensor can trigger when you **air the room**, as it detects heat changes.
1. The presence sensor uses **24 GHz**. While it can detect mostly stationary humans, it cannot detect **very small movements** or someone under a blanket.
1. The presence sensor is **extremely hard to solder**. I actually broke a sensor by accidentally desoldering the resistor right next to the pins. That is why I recommend using the separately available cable for it.
1. A sensor in the wall measures the temperature of the wall box a bit. The power supply and the ESP are separated from the temperature sensor, but you still need to calibrate the temperature offset.
