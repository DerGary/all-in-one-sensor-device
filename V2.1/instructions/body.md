## 🔢 Steps

1. Source all the parts from the shopping list
1. Print the enclosure
1. Solder all sensors to the esp
1. Flash the ESP with the software and verify that all sensors work (connect it to your Home Assistant instance to monitor them).
1. Assemble the sensors and ESP into the enclosure.
1. Place the device in its designated spot.
1. After a few minutes, calibrate the sensors and re-flash the software.
1. Create your Home Assistant automations using the sensors.

### 🛒 Shopping List

You can also buy the parts from other sites. If you don’t mind waiting, AliExpress is usually cheaper. I’ve listed the exact products I used because I can confirm they worked for me.

| Name | Hint | Link |
| ----- | ------ | ------ |
| ESP32 | This case features several variants that fit different ESP form factors. <br> I would recommend the D1 Mini or Super Mini Variants | D1 Mini [Amazon](https://www.amazon.de/dp/B0FP2N2YNL) <br> D1 Mini [AliExpress](https://de.aliexpress.com/item/1005006414001036.html?spm=a2g0o.order_list.order_list_main.27.2d3b5c5fHxAbjl&gatewayAdapt=glo2deu) <br> ESP32 Large [Amazon](https://www.amazon.de/dp/B0D9BSKR16?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2&th=1) <br> ESP32 C6 Super Mini [Aliexpress](https://de.aliexpress.com/item/1005009089500839.html?spm=a2g0o.order_list.order_list_main.11.1ab05c5f8xuanX&gatewayAdapt=glo2deu) (you need to choose the correct version manually) |
| Power Supply (PSU) | Any low-power PSU you already have should work. Otherwise, buy a simple one. | [Amazon](https://www.amazon.de/dp/B0D7MD5BJ3?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) |
| Temperatur Sensor BME280 or BME680 | BME680 air quality readings may not be reliable (see Disclaimer). | [BME280](https://amzn.eu/d/06HNHzUl) <br> [BME680](https://www.amazon.de/dp/B0CYH34X3P?ref=ppx_yo2ov_dt_b_fed_asin_title) |
| Screws | <ul><li>BME280/BME680 = 1x M2.5x3mm</li><li>Presence Sensor Shield = 3x M2x3mm</li><li>Motion Sensor HC-SR501 = 2x M2x3mm</li><li>Brightness Sensor BH170 = 2x M2x3mm</li></ul><br>You can try to use M2 for all the sensors but the BME280 sensor cutouts are too big for M2 head and might fall through. | [Amazon](https://www.amazon.de/dp/B0CZNT5YXV?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)|
| Brightness Sensor BH1750 | Works flawlessly for me, no hints necessary. | [Amazon](https://www.amazon.de/dp/B0D3WN41FS?ref=ppx_yo2ov_dt_b_fed_asin_title)|
| Motion Sensor HC-SR501 | The sensor case is specifically designed for a motion sensor with this form factor. I know they are not the best, but they are reasonably cheap, see Disclaimer for more details | [Amazon](https://www.amazon.de/dp/B0939XMBXJ?ref=ppx_yo2ov_dt_b_fed_asin_title) |
| Presence Sensor LD2410B | <ul><li>The sensor case is specifically designed for a presence sensor with this form factor. I experienced that they are not the best, but they are reasonably cheap, see Disclaimer for more details. </li><li>I recommend buying the sensor with pins and also buy the appropriate cable with it. Soldering these small pins is extremely hard and can even damage the sensor. Therefore I recommend attaching the cable using the plug and soldering only the side that must be attached to the ESP.</li></ul> | [Aliexpress](https://de.aliexpress.com/item/1005004920357733.html?spm=a2g0o.order_list.order_list_main.232.23775c5f0Fhk0S&gatewayAdapt=glo2deu) |
| LED | One segment of a WS2812 5V RGB LED. If you are like me you may have them already lying around at home 😄. | [Amazon](https://amzn.eu/d/0iexLtnJ) |
| Cables | I used 22 AWG wire | [Aliexpress](https://de.aliexpress.com/item/1005007671008743.html?spm=a2g0o.order_list.order_list_main.227.23775c5f0Fhk0S&gatewayAdapt=glo2deu) |
| Long USB Cable | Choose length to fit your setup. | [Aliexpress](https://de.aliexpress.com/item/1005007053181899.html?spm=a2g0o.order_list.order_list_main.262.23775c5fsHIXLm&gatewayAdapt=glo2deu) |
| Filament | I printed my case in Kingroon White PLA and with Kingroon White PETG. You can use bambu labs filament of course. I printed the brightness sensor cover out of translucent PLA/PETG. | [Kingroon White PLA](https://de.aliexpress.com/item/1005007226921275.html?spm=a2g0o.order_list.order_list_main.29.51fa5c5fMbjQzg&gatewayAdapt=glo2deu) <br> [Elegoo Transparent PLA](https://www.amazon.de/dp/B0CD7BS7B1?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_8) |
| Cable Distribution (Proto Boards) | I broke something off proto boards that I got lying around and used that to distribute the cables which needed to go to multiple sensors. I added a link to something similar. You can try a different approach. Don't try to solder every cable from every sensor directly to the ESP as this will be a mess 😅 | [Aliexpress](https://de.aliexpress.com/item/1005006236993083.html?spm=a2g0o.productlist.main.53.59ba6ef0R2AfKV&algo_pvid=fdf3a000-9cfe-46b8-8db1-369f4ad17722&algo_exp_id=fdf3a000-9cfe-46b8-8db1-369f4ad17722-52&pdp_ext_f=%7B%22order%22%3A%22124%22%2C%22eval%22%3A%221%22%7D&pdp_npi=6%40dis%21EUR%212.59%212.59%21%21%212.95%212.95%21%402103868817563684986428248ea8fb%2112000036410088438%21sea%21DE%216147561042%21X%211%210%21n_tag%3A-29919%3Bd%3A856b28b5%3Bm03_new_user%3A-29895&curPageLogUid=e0I1agpXpJrw&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006236993083%7C_p_origin_prod%3A) |

You also need:

- A soldering iron (and soldering skills)
- Solder
- Wire stripping tool
- Side cutters to trim the cables
- Screwdriver
- Pliers
- Desoldering pump (optional)
- Multimeter (optional if you trust your soldering skills)

### 🔢 Assembly Instructions

1. If you are using the ESP32 Large version you need to desolder the pins
    - Cut the black spacers into chunks of 4–5 pins and remove them with pliers.
    - Clamp the ESP in a vise [(I use a printable vise from Thingiverse)](https://www.thingiverse.com/thing:4764937).
    - Desolder the pins and pull them out with pliers. It’s also possible to heat the solder and pull the pins with pliers **without** a desoldering pump.
1. **Desolder Motion sensor (HC-SR501) pins:**
    - Remove the pin spacers with pliers.
    - Clamp the motion sensor in a vise.
    - Desolder and remove the pins. It’s also possible to heat the solder and pull the pins with pliers without a desoldering pump.
1. Break a **2×4** *(2x5 for Super Mini)* matrix from the proto board — for **motion** and **presence** sensors.
1. Break a **4×3** matrix from the proto board — for **brightness** and **temperature** sensors.
1. Cut wires to length. I wrote the length of the cables in mm into the connection drawings below. I show the two distribution boards separately to make things easier to follow. (There are further steps below on soldering order.) Pick the Connection Drawing that matches the ESP32 Version that you are using. The cable lengths and pinout slightly differs depending on the version.
    - I only a limited number of different colored cables. In the connection drawings I used the following colors:
        - red = 3.3V (BME/BH1750)
        - white/grey 5V(LD2410/HC-SR501/LED)
        - black = Ground
        - Green = I2C SCL/UART (If you have more colors you can use different colors for UART and I2C)
        - Blue = I2C SDA/UART (If you have more colors you can use different colors for UART and I2C)
        - Yellow = Motion Out
    - In the photos below I also used red for 5V, but make sure you don't mix 5V and 3.3V.

   #### D1 Mini

    ![D1 Mini Pinout](images/D1MiniPinout.png)

   #### ESP32 Large

    ![Large Pinout](images/LargePinout.png)

   #### Super Mini

    The Ground of the two distribution boards are connected as the board only has one ground pin
    ![Super Mini Pinout](images/SuperMiniPinout.png)

1. Make sure to tin the wire ends
1. Solder **one end** of each wire to the **sensors** as described in the Connection Drawings from Step 4

    | Motion Sensor | Presence Sensor | Brightness Sensor | Temperature Sensor | LED |
    | ---- | ---- | ---- | ---- | ---- |
    | ![Motion Sensor](images/HC-SR501.jpg) | ![Presence Sensor](images/LD2410.jpg) | ![Brightness Sensor](images/BH1750.jpg) | ![Temperature Sensor](images/BME680.jpg) | ![LED](images/LEDInPlace.jpg) |

1. Solder the **other end** of the wires to the **distribution proto boards and ESP respectively. Connect wires of the same color together**. If you used a proto board where the lines are already connected via the board you don't need to do any extra step. My proto board has separated solder points so I had to bridge them.

    - The 4x3 pin distribution board is connected to the brightness and temperature sensors.
    - The 2x4(2x5) pin distribution board is connected to the motion, presence sensors and LED.

    |4x3|2x4(2x5)|
    |---|---|
    | <img src="images/DistroBoards-1.jpg" height="400" alt="4x3 pin distribution board"> | <img src="images/DistroBoards-2.jpg" height="400" alt="2x3 pin distribution board"> |

1. **Solder the wires to the ESP pins** as described in the connection drawings above. You need to attach the cables from the back side (because the wifi antenna is on the front and we want that to be facing away from the motion sensor) — attach them as shown in the photos.

    | Large | D1 Mini |
    | --- | --- |
    | <img src="images/LargeWiresSoldered.jpg" height="400" alt="ESP Soldered Wires example"> | <img src="images/D1MiniWiresSoldered.jpg" height="400" alt="ESP Soldered Wires example"> |

1. Use a **multimeter** to verify that solder joints of different colors do not bridge. Any short can damage components and may cause smoke or even fire.
1. Now it's time to check whether all the soldering has worked out. Flash the software onto the ESP. It can be found in the software section. Verify that all sensors are detected and reporting, then return here to complete assembly.
1. Screw all the sensors in place using M2x3mm screws

    <img src="images/SensorsInPlace.jpg" height="400" alt="sensors in place">

1. Screw the temperature sensor in place. For the BME680 There is already a cone protruding from the wall that holds the sensor in place on the lower screw hole. (1x M2.5x3mm)

    <img src="images/TemperatureSensorInPlace.jpg" height="400" alt="temperature sensors in place">

1. Slide the **divider wall** into place. It shields the temperature sensor from ESP board heat. It won’t eliminate the effect entirely, but it’s an improvement.

    <img src="images/DividerWall.jpg" height="400" alt="Divider Wall">

1. Attach the **ball head** to the back of the enclosure.

    <img src="images/BallHeadBack.jpg" height="400" alt="Ball Head Back">

1. It might be a good idea to hide the ESP integrated status led with some electrical tape, depending on the brightness of the led. I got some really bright D1 Mini variants where the LED is disturbing.

    <img src="images/LEDElectricalTape.jpg" height="400" alt="Ball Head Back">

1. Slide the ESP32 into the rails on the backplate. And attach the USB cable.

    | D1 Mini | Super Mini |
    | --- | --- |
    | <img src="images/D1MiniRails.jpg" height="250" alt="D1 Mini Rails"> | <img src="images/SuperMiniRails.jpg" height="250" alt="Super Mini Rails"> |

1. Slide the distribution boards into the rails on the backplate.

    | D1 Mini | Large |
    | --- | --- |
    | <img src="images/DistributionBoardRails.jpg" height="400" alt="Distribution Board Rails"> | <img src="images/LargeDistributionBoardRails.jpg" height="400" alt="Distribution Board Rails"> |

1. Close the lid — it **snaps** into place.

    <img src="images/ClosedCase.jpg" height="400" alt="Closed Case">

**Congratulations — you’re done!** 🥳🎉

Post a picture and a comment to this model — I’d love to see your results 🤗

### 💾 Software

This project uses [ESPHome](https://esphome.io/) as the underlying software. It’s easy to set up and flash. It uses YAML files that define the sensors connected to the device and their properties. You can either checkout my code and compile it yourself or you can pick one of my precompiled firmware binaries and flash it. I won’t provide general ESPHome compilation instructions — the official documentation is excellent:
Guide: <https://esphome.io/guides/installing_esphome/>

#### Flash my precompiled binaries

##### Initial installation

1. Navigate to [my Github](https://github.com/DerGary/all-in-one-sensor-device/releases?q=v2.1&expanded=true) and find the latest Release.
1. In the assets section find the binary that fits your setup. The variations are:
    - variant = ``esp32``/`esp32c6`
    - language = `de`/`en`
    - temperature sensor: `bme280`/`bme680`
    - Pick the `factory` version for initial setup.
1. Navigate to [web.esphome.io](https://web.esphome.io/).
1. Connect the esp to your computer.
1. Click connect and choose the Serial Port (probably there is only one).
1. Click install, choose the `factory` binary file that you downloaded earlier
1. Click install and wait.
1. The LED will flash green after a successful install.
1. Open the Home Assistant app on your smartphone. Make sure that Bluetooth is turned on.
1. Open the ``integration and devices`` view. Home Assistant should pick up the sensor and you can click add.
1. Define WiFi Credentials and click ok.
1. After that you can add the ESPHome integration. Check your router for the ip address of the sensor.
1. Once deployed in its final location, proceed with calibration.

##### Update

1. Navigate to [my Github](https://github.com/DerGary/all-in-one-sensor-device/releases?q=v2.1&expanded=true) and find the latest Release.
1. In the assets section find the binary that fits your setup. The variations are:
    - variant = ``esp32``/`esp32c6`
    - language = `de`/`en`
    - temperature sensor: `bme280`/`bme680`
    - Pick the ``ota`` version to update an existing sensor.
1. Navigate to the web page of the sensor by typing its IP address in your browser.
1. At the bottom of the page you will find the OTA update section.
1. Choose the previously downloaded file and click update.

#### Flash code directly

1. Install esphome
1. Checkout my [Github Repository](https://github.com/DerGary/all-in-one-sensor-device)
1. Navigate into the V2.1 folder in a terminal
1. execute `esphome -s variant esp32 -s temp bme280 -s lang de run device.yaml`
    - You can change ``esp32`` to any esphome compatible esp variant. Although you have to adhere to the **super mini** pinout when anything other than `esp32` is chosen here.
    - For ``temp`` you can choose between ``bme280`` and ``bme680``
    - For ``lang`` you can choose between ``de`` and ``en``
1. After flashing proceed with adding the sensor to your home assistant instance as described in [initial installation](#initial-installation) section above.

#### OpenThread (instead of WiFi)

As an alternative to WiFi, the device can connect via **OpenThread** — useful if you already run a Thread border router (e.g. via Home Assistant's OTBR add-on) and want to keep the sensor off your WiFi network. OpenThread requires the **esp32c6** variant, since it needs its 802.15.4 radio — the plain `esp32` variant cannot use it.

> **⚠️ There are no precompiled OpenThread binaries.** A Thread network's credentials (the "dataset") must be compiled directly into the firmware — unlike WiFi, there is no equivalent of Improv BLE to provide them after flashing. This means every Thread-connected device needs its own custom build with its own dataset baked in. Our CI only ever compiles the OpenThread variant as a build check with a placeholder dataset (`CHANGEME`) and never publishes it as a release asset, so downloading a `thread` binary from GitHub is not possible — you must build it yourself.

To build and flash with OpenThread:

1. Get your Thread dataset TLV from Home Assistant: **Settings → Devices & Services → Thread** integration → **Configure** → select your preferred network → click the info (ⓘ) icon → copy the **Dataset TLVs** value.
1. Install esphome and checkout the [Github Repository](https://github.com/DerGary/all-in-one-sensor-device) as described in [Flash code directly](#flash-code-directly) above.
1. Navigate into the `V2.1` folder in a terminal.
1. execute `esphome -s variant esp32c6 -s temp bme280 -s lang de -s connectivity thread -s openthread_tlv <your-tlv> run device.yaml`, replacing `<your-tlv>` with the dataset TLV from step 1.
1. Once flashed, the device joins your Thread network directly — no WiFi pairing step is needed. Add it to Home Assistant the same way as any other Thread/Matter-adjacent ESPHome device on your network.

Switching back to WiFi later requires reflashing with `-s connectivity wifi_improv` (the default).

#### Status LED

| Color | Pattern | Meaning |
| --- | --- | --- |
| Green | Fast Pulse | Sensor is waiting to be paired via Improv BLE |
| Pink | Fast Pulse | Sensor is not connected to wifi or home assistant |
| Warm White | Steady | When the occupancy automation is enabled, indicates that the area is occupied. |
| Orange | Slow Pulse | When the air quality automation is enabled, indicates that the air quality level is warning. |
| Red | Slow Pulse | When the air quality automation is enabled, indicates that the air quality level is critical. |

### 🎯 Calibration

Calibration is **non-trivial** and may take time and multiple iterations. I mainly use **offset calibration**, which is the easiest approach, though there are more accurate methods also available.

#### BME680 / BME280

I only calibrated **temperature** and **humidity**. I don’t use air pressure, and air quality is meant to auto-calibrate.

1. Let the device sit in its final location for **5–10 minutes** to saturate with heat from the ESP.
1. Place a **trusted temperature & humidity sensor** nearby.
1. Calibrate humidity and temperature using the input components **Temperature Offset** and **Humidity Offset** directly in Home Assistant.

#### Motion Sensor

The motion sensor has a jumper that defines the mode of the sensor.

- H (Repeat Trigger / Retriggerable mode)
  - As long as motion is detected, the output stays **HIGH**.
Example: If the delay time is set to 10 s and motion is detected again after 5 s, the timer resets and the output remains HIGH continuously until no more motion is detected.
- L (Single Trigger / Non-Retriggerable mode)
  - When motion is detected, the output goes **HIGH** for the set delay time, then returns to LOW — even if motion is still happening during that period. Only after the delay finishes and the sensor is ready again can it trigger once more.

The default seems to be **L**, while I use **H**.

The sensor has **two potentiometers**: one for **trigger time** and one for **sensitivity**. Looking from the back, the **left** is sensitivity and the **right** is time delay (I always mix them up 😅).

1. Set the **time delay** long enough that the presence sensor has already triggered, but short enough to release in a timely manner when a person leaves. This makes automations easier.
1. Set **sensitivity** just high enough to trigger where needed, but as low as possible to reduce false positives.
I set it to about there:

    <img src="images/HC-SR501Knobs.jpg" height="300" alt="HC-SR501 Knobs">
    <img src="images/HC-SR501Settings.jpg" height="300" alt="HC-SR501 Knobs">

#### Presence Sensor

This sensor is the most challenging to calibrate. The g0-g8 values depict the different distances from the sensor.

1. **Enable Engineering Mode**
1. Ensure **no one is in the room** while calibrating.
1. Let the sensor sit for **10 minutes** while Home Assistant gathers **g0–g8 move/still** energy values.
1. Review the history of each **g0–g8** value in Home Assistant. Find the **highest** value each.
1. Set the **g0–g8 still thresholds** to **10 % higher** than the highest observed value for this distance.
1. Set the **g0–g8 move thresholds** to **20 % higher** than the highest observed value for this distance.
1. **Disable engineering mode**

### 🚫 Don'ts

1. Don’t mount the device **too high**. Hot air rises and will skew and destabilize temperature readings; it may also affect the motion sensor.
1. Don’t place the device **near a heater** — it reduces temperature accuracy and can trigger the motion sensor.
1. Don’t place it directly in strong airflow (e.g., when airing the room), as the motion sensor detects rapid heat changes.

### 📢 Tips

- You can use the [underware collection](https://makerworld.com/de/models/783010-underware-2-0-infinite-cable-management?from=search#profileId-1504508) to route your cables.
- You can use [**my cable clamps**](https://makerworld.com/de/models/1744421-adhesive-cable-clamp-for-usb-cables-4mm-3mm#profileId-1853998) to route USB cables. They fit the cables linked here, use minimal filament, and can be attached with double-sided tape.
- You can use [my collection of ball head mounts](https://makerworld.com/de/collections/9129741-ball-head-mounts) to mount the device to cabinets, tubes, walls, desks etc.
- It’s preferable to position the device **facing the area where you stay** rather than just facing the door. The motion sensor has a wide field of view and covers most of the room, while the presence sensor works best when pointed directly at the target.
- You can test all sensors with **jumper wires** before committing to soldering.
