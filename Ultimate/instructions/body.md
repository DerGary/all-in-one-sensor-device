
## 🔢 Steps

1. Source all the parts from the shopping list
1. Print the enclosure
1. Solder and wire all sensors to the distribution boards and ESP
1. Flash the ESP with the software and verify that all sensors work (connect it to your Home Assistant instance to monitor them).
1. Assemble the sensors and ESP into the enclosure.
1. Place the device in its designated spot.
1. After a few minutes, calibrate the sensors and re-flash the software.
1. Create your Home Assistant automations using the sensors.

### 🛒 Shopping List

You can also buy the parts from other sites. If you don’t mind waiting, AliExpress is usually cheaper. I’ve listed the exact products I used because I can confirm they worked for me.

| Name | Hint | Link |
| ----- | ------ | ------ |
| ESP32 Super Mini | My prebuilt binaries use the C6, you can also use other variants if you build it yourself. | [DFRobot ESP32-C6](https://www.berrybase.de/en/dfrobot-beetle-esp32-c6-wifi-6-bluetooth-5-zigbee-3.0-thread-risc-v-13-io-ports-3.3v) <br> [ESP32-C6 Super Mini](https://de.aliexpress.com/item/1005009089500839.html?spm=a2g0o.order_list.order_list_main.17.51e45c5fZesJEf&gatewayAdapt=glo2deu) (you must choose the correct variant, as the link does not include the choice) |
| Power Supply (PSU) | Any low-power PSU you already have should work. Otherwise, buy a simple one. | [Amazon](https://www.amazon.de/dp/B0D7MD5BJ3?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) |
| Temperature Sensor SHT4x or BME280 | I decided to use the SHT41 as its temperature sensor is more accurate. <br> The BME280 is also supported when you need to measure air pressure. | [BME280](https://amzn.eu/d/04BAvHum) <br> [SHT4x](https://de.aliexpress.com/item/1005008518326181.html?spm=a2g0o.order_list.order_list_main.29.51e45c5fZesJEf&gatewayAdapt=glo2deu) |
| Screws | 8x M2x3mm | [Amazon](https://www.amazon.de/dp/B0CZNT5YXV?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) |
| Brightness Sensor BH1750 | Worked flawlessly for me in V1 and V2 so it is back in the Ultimate | [Amazon](https://www.amazon.de/dp/B0D3WN41FS?ref=ppx_yo2ov_dt_b_fed_asin_title) |
| CO2 Sensor SCD4x | Measures actual CO2 concentration. Both SCD40 and SCD41 are supported. | [Aliexpress](https://de.aliexpress.com/item/1005008696769890.html?spm=a2g0o.order_list.order_list_main.29.24765c5fbAhbJz&gatewayAdapt=glo2deu) |
| VOC Sensor SGP30 | Measures volatile organic compounds (air quality). I am using the blue module also called GY-SGP30. | [Aliexpress](https://de.aliexpress.com/item/1005012034193686.html?spm=a2g0o.productlist.main.4.1c1aSxPKSxPKMY&aem_p4p_detail=20260613002921441686255127900000780498&algo_pvid=7f56b5d1-73c5-410d-8384-c001793e7138&algo_exp_id=7f56b5d1-73c5-410d-8384-c001793e7138-3&pdp_ext_f=%7B%22order%22%3A%2215%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%215.72%214.29%21%21%216.46%214.84%21%40211b81a317813357609628201e5315%2112000057352428823%21sea%21DE%216147561042%21X%211%210%21n_tag%3A-29919%3Bd%3A856b28b5%3Bm03_new_user%3A-29895&curPageLogUid=rZAOF2Lp1cfd&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012034193686%7C_p_origin_prod%3A&search_p4p_id=20260613002921441686255127900000780498_1) |
| Motion Sensor Panasonic EKMC 1603111 | Theoretically other Panasonic PIRs would be also compatible if they have the same form factor. | [Aliexpress](https://de.aliexpress.com/item/1005006704410099.html?spm=a2g0o.order_list.order_list_main.11.51e45c5fZesJEf&gatewayAdapt=glo2deu) |
| Presence Sensor LD2450 | Handles multi-person, zone-based tracking. Pay attention that the one you buy includes the cable as it is easier to work with. | [Amazon](https://www.amazon.de/dp/B0FMRQ6DWJ?ref_=ppx_hzod_title_dt_b_fed_asin_title_0_0) |
| Presence Sensor C4001 | Handles still-presence detection (detecting a stationary person). Both sensors are needed; they complement each other. Unfortunately this sensor is hard to source — import taxes may apply depending on the supplier. | [DigiKey](https://www.digikey.de/de/products/detail/dfrobot/SEN0609/23028638) <br> [RobotShop](https://eu.robotshop.com/de/products/dfrobot-mmwave-c4001-24ghz-sensor-zur-erkennung-menschlicher-prasenz-25-meter-uart) <br> [Mouser](https://www.mouser.de/ProductDetail/DFRobot/SEN0609?qs=HFfMDpzxxd21aKNJkzimmg%3D%3D) <br> [OpenELAB](https://openelab.io/de/products/dfrobot-mmwavec400124ghz-humanpresencedetectionsensor-25meters) <br> [DFRobot](https://www.dfrobot.com/product-2793.html) |
| Cables | I used 22 AWG wire | [Aliexpress](https://de.aliexpress.com/item/1005007671008743.html?spm=a2g0o.order_list.order_list_main.227.23775c5f0Fhk0S&gatewayAdapt=glo2deu)<br>[Amazon](https://www.amazon.de/dp/B0FDKT9XPV?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1&th=1) |
| Long USB Cable | Choose length to fit your setup. | [Aliexpress](https://de.aliexpress.com/item/1005007053181899.html?spm=a2g0o.order_list.order_list_main.262.23775c5fsHIXLm&gatewayAdapt=glo2deu) |
| Filament | I printed my case in Kingroon White PLA and with Kingroon White PETG. You can use bambu labs filament of course. I printed the brightness sensor cover out of translucent PLA/PETG. | [Kingroon Filament](https://de.aliexpress.com/item/1005007226921275.html?spm=a2g0o.order_list.order_list_main.29.51fa5c5fMbjQzg&gatewayAdapt=glo2deu)<br>[Elegoo Transparent PLA](https://www.amazon.de/dp/B0CD7BS7B1?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_8)<br>[eSUN Clear PETG](https://www.3djake.de/esun/petg-clear-5) |
| Cable Distribution (Proto Boards) | I broke something off proto boards and used that to distribute the cables which needed to go to multiple sensors. | [Amazon](https://amzn.eu/d/0a2D7E1M) |
| Status LED | I used an LED from leftovers of a WS2812 LED strip with 5V that I got lying around | [Amazon](https://amzn.eu/d/04rXpC34) |
| 100µF 16V Electrolytic Capacitor<br>100nF (104) Ceramic Capacitor | The capacitors are used to suppress interferences that may be injected by the ESP32 into the power rails.<br> This measure was taken to improve the reliability of the PIR sensor and remove false positives as much as possible. It is recommended by Panasonic to do so. I got pretty good results without them but I wanted the best possible experience and your mileage may vary if you omit them. | [Amazon](https://www.amazon.de/dp/B0DXC7MX53) |

You also need:

- A soldering iron (and soldering skills)
- Solder
- Wire stripping tool
- Side cutters to trim the cables
- Screwdriver
- Pliers
- Desoldering pump (optional)
- Multimeter (optional if you trust your soldering skills)
- Electrical tape (optional, to cover LEDs on the C4001 and ESP)

### 🔢 Assembly Instructions

1. Desolder all the pin headers if there are any on your purchased sensors
    - Remove the pin spacers with pliers.
    - Clamp the sensor in a vise.
    - Desolder and remove the pins. It’s also possible to heat the solder and pull the pins with pliers without a desoldering pump.
1. Break a **7x4** matrix from the proto board
    I used a carpet knife to cut around the matrix on the proto board on both sides and used pliers to carefully break the proto board at the cut.

    <img src="images/BreakoutBoard1.jpg" width="33%">
    <img src="images/BreakoutBoard2.jpg" width="33%">
    <img src="images/BreakoutBoard3.jpg" width="33%">
    <img src="images/BreakoutBoard4.jpg" width="33%">
    <img src="images/BreakoutBoard5.jpg" width="33%">
    <img src="images/BreakoutBoard6.jpg" height="300">

1. Break a **5×2** matrix from the proto board
    Using the same technique as above.
1. Cut wires to length. I wrote the length of the cables in mm into the connection drawings. I show the two distribution boards separately to make things easier to follow. (There are further steps below on soldering order.) For the generic ESP32-C6 Super Mini the wiring differs in one aspect from the DFRobot Beetle as it only has one ground pin.
    - I only had 5 colors of wire
        - red = Voltage (If you have more colors use different colors for 3.3V (BME280/BH1750/SGP4x/SHT4x/SCD4x/PIR) and 5V(LD2450/C4001/LED), It is important to never mix them up)
        - black = Ground
        - Green = I2C SCL/UART (If you have more colors you can use different colors for UART and I2C)
        - Blue = I2C SDA/UART (If you have more colors you can use different colors for UART and I2C)
        - Yellow = Motion Out / Status LED Data In
    - **DFRobot Beetle ESP32-C6**
        <img src="images/ConnectionDrawingBeetle.jpg" width="100%">
    - **Generic ESP32-C6 Super Mini**
        <img src="images/ConnectionDrawingC6.jpg" width="100%">

    **Pin Reference**

    | Sensor / Function | GPIO |
    | --- | --- |
    | PIR Motion Out | GPIO7 |
    | I2C SDA (BH1750 / SHT4x / SGP30 / SCD4x) | GPIO19 |
    | I2C SCL (BH1750 / SHT4x / SGP30 / SCD4x) | GPIO20 |
    | WS2812 LED Data | GPIO21 |
    | LD2450 TX (ESP→Sensor) | GPIO16 |
    | LD2450 RX (Sensor→ESP) | GPIO17 |
    | C4001 TX (ESP→Sensor) | GPIO22 |
    | C4001 RX (Sensor→ESP) | GPIO23 |

1. Make sure to tin the wire ends
1. Solder one end of each wire to the sensors as described in the Connection Drawings from Step 4
    - PIR Sensor:
        - First place the printed round PIR bracket on the sensor as this can't be done when the sensor is already soldered together
        - The middle pin is the data pin
        - also solder the 100nF ceramic capacitor between the ground and the voltage pin
    - Presence Sensor LD2450:
        - **The colors of the included cable are different to the drawings. The cable may have different colors on your version. Pay attention to correctly wire every pin to the correct location. The pins are labeled on the board.**

    | PIR Sensor | Presence Sensors | BH1750 |
    | ---------- | ---------------- | ------ |
    | <img src="images/PIR.jpg" height="200"> | <img src="images/Presence.jpg" height="200"> | <img src="images/bh1750.jpg" height="200"> |

    | SHT41 | SCD41 | SGP30 |
    | ----- | ----- | ----- |
    | <img src="images/SHT41.jpg" height="200"> | <img src="images/SCD41.jpg" height="200"> | <img src="images/SGP.jpg" height="200"> |

1. Solder the **other end** of the wires to the **distribution proto boards and ESP respectively. Connect wires of the same color together.** If you used a proto board where the lines are already connected via the board you don't need to do any extra step. My proto board has separated solder points so I had to bridge them.

    <img src="images/8x4_1.jpg" width="33%">
    <img src="images/8x4_2.jpg" width="33%">
    <img src="images/8x4_3.jpg" width="33%"><br>
    <img src="images/4x2_1.jpg" width="33%">
    <img src="images/4x2_2.jpg" width="33%">
    <img src="images/4x2_3.jpg" width="33%">

    Also solder the **100µF electrolytic capacitor** across the 3.3V and GND rails on the distribution proto board, as shown in the Connection Drawings above. Observe polarity — the negative lead (shorter leg / marked stripe) connects to GND.

1. **Solder the wires to the ESP pins** as described in the connection drawings above. You need to attach the cables from the back side (because the wifi antenna is on the front and we want that to be facing away from the motion sensor) — attach them as shown in the photos.

    <img src="images/ESP_1.jpg" width="33%">
    <img src="images/ESP_2.jpg" width="33%">
    <img src="images/ESP_3.jpg" width="33%">

1. Use a **multimeter** to verify that solder joints of different colors do not bridge. Any short can damage components and may cause smoke or even fire.
1. Now it's time to check whether all the soldering has worked out. Flash the software onto the ESP. It can be found in the software section. Verify that all sensors are detected and reporting, then return here to complete assembly.
1. Optionally cover the LEDs on the **C4001** and the **ESP** with a small piece of electrical tape to prevent them from lighting up inside the enclosure.

    <img src="images/C4001_LED_Blackout.jpg" width="33%">
    <img src="images/ESP_LED_Blackout.jpg" width="33%">

1. Attach the ball head mount to the back of the case

    <img src="images/BackBallHead_1.jpg" width="45%">
    <img src="images/BackBallHead_2.jpg" width="25%">
    <img src="images/BackBallHead_3.jpg" width="25%">

1. Place all the sensors, boards and ESP in place using M2x3mm screws
    The order does not really matter but it is easiest to do it in the order depicted in the photos here:

    <img src="images/Assembly_1.jpg" width="25%">
    <img src="images/Assembly_2.jpg" width="25%">
    <img src="images/Assembly_3.jpg" width="45%">
    <img src="images/Assembly_4.jpg" width="33%">
    <img src="images/Assembly_5.jpg" width="33%">
    <img src="images/Assembly_6.jpg" width="33%">
    <img src="images/Assembly_7.jpg" width="45%">
    <img src="images/Assembly_8.jpg" width="45%">
    <img src="images/Assembly_9.jpg" width="45%">
1. The case for the temperature sensor is used to hold it in place as well as shield it a bit from the heat produced by the other components
1. The SGP30 and SCD4X sensors do have shields that slide on to secure them in place
1. Attach the USB cable.
1. Close the lid — it **snaps** into place.

**Congratulations — you’re done!** 🥳🎉
Post a picture and a comment to this model — I’d love to see your results 🤗

### 💾 Software

This project uses [ESPHome](https://esphome.io/) as the underlying software. It's easy to set up and flash. It uses YAML files that define the sensors connected to the device and their properties. You can either checkout my code and compile it yourself or you can pick one of my precompiled firmware binaries and flash it. I won't provide general ESPHome compilation instructions — the official documentation is excellent:
Guide: <https://esphome.io/guides/installing_esphome/>

#### Flash my precompiled binaries

##### Initial installation

1. Navigate to [my Github](https://github.com/DerGary/all-in-one-sensor-device/releases?q=ultimate&expanded=true) and find the latest Release.
1. In the assets section find the binary that fits your setup. The variations are:
    - language = `de`/`en`
    - temperature sensor: `sht4x`/`bme280`
    - Pick the `factory` version for initial setup.
1. Navigate to [web.esphome.io](https://web.esphome.io/).
1. Connect the ESP to your computer.
    > **Troubleshooting: Factory-fresh boards cannot be flashed via web.esphome.io**
    > Factory-fresh ESP32-C6 boards bootloop out of the box and web.esphome.io cannot reliably connect to them. Use esptool or the ESPHome CLI instead:
    >
    > **Option 1 — esptool** (run repeatedly until it catches the device between reboots):
>
    > ```
    > esptool --chip esp32c6 --port COM3 write_flash 0x0 firmware.factory.bin
    >    ```
>
    > Replace `COM3` with your actual port number and `firmware.factory.bin` with the file you downloaded.
    >
    > **Option 2 — ESPHome CLI** (as described in the [Flash code directly](#flash-code-directly) section below):
    > Run the command repeatedly — it will catch the device in the brief window between reboots.

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

1. Navigate to [my Github](https://github.com/DerGary/all-in-one-sensor-device/releases?q=ultimate&expanded=true) and find the latest Release.
1. In the assets section find the binary that fits your setup. The variations are:
    - language = `de`/`en`
    - temperature sensor: `sht4x`/`bme280`
    - Pick the ``ota`` version to update an existing sensor.
1. Navigate to the web page of the sensor by typing its IP address in your browser.
1. At the bottom of the page you will find the OTA update section.
1. Choose the previously downloaded file and click update.

#### Flash code directly

1. Install esphome
1. Checkout my [Github Repository](https://github.com/DerGary/all-in-one-sensor-device)
1. Navigate into the Ultimate folder in a terminal
1. execute `esphome -s lang en -s temp sht4x run device.yaml`
    - For ``temp`` you can choose between ``sht4x`` and ``bme280``
    - For ``lang`` you can choose between ``de`` and ``en``
1. After flashing proceed with adding the sensor to your home assistant instance as described in [initial installation](#initial-installation) section above.

### 🎯 Calibration

Calibration is **non-trivial** and may take time and multiple iterations. I mainly use **offset calibration**, which is the easiest approach, though there are more accurate methods also available. If you mount the sensor high in the room (which improves presence detection) it will decrease the accuracy of the temperature sensor as hot air rises up. When you mount it high in the room you should use linear calibration to calibrate the temperature sensor.

**BME280 / SHT4X**:

Only **temperature** and **humidity** calibration is covered here. Air pressure calibration is not required for typical smart home use.

Let the device sit for **5–10 minutes** to heat-soak.

Place a trusted sensor nearby.

Calibrate humidity and temperature using the input components **Temperature Offset** and **Humidity Offset** directly in Home Assistant.

**LD2450 Presence Sensor:**

The LD2450 itself can't be calibrated, and the main presence detection (used by the device's overall presence/occupancy sensor) works out of the box — it reports a person as present anywhere within the sensor's range, whether or not they're standing inside a configured zone.

Zones are a separate, optional feature on top of that: they let you trigger automations based on a person being in a *specific* part of the room (e.g. "at the desk" or "on the couch"), rather than just "somewhere in range". You don't need to configure any zones for general presence detection to work. Zones are fully configurable from Home Assistant — no app and no reflashing required.

*Coordinate system*

- The sensor sits at the origin (`X = 0`, `Y = 0`).
- `Y` is the distance straight out in front of the sensor, in meters.
- `X` is the distance to the side, in meters — negative is to the left of the sensor, positive is to the right (as seen from behind the sensor, facing the same direction it does).

*Finding coordinates*

1. On the device page of your sensor in Home Assistant, enable the disabled-by-default entities **LD2450 Target-1 X Position** and **LD2450 Target-1 Y Position** (find the entity → click the cog icon → enable).
1. Walk to each corner of the area you want to outline as a zone and note the `X`/`Y` values these entities report while you stand there.
1. Once you have the coordinates you need, you can disable the target entities again — they update every second and add unnecessary load to the Home Assistant recorder, and aren't required for zone-based presence detection.

*Setting up a zone*

The firmware exposes 3 zones (`LD2450 Zone-1`, `LD2450 Zone-2`, `LD2450 Zone-3`). Each zone's shape is entered as a single text entity, e.g. `LD2450 Zone-1 Polygon`, found under the "Configuration" category. This means a zone isn't limited to a rectangle or a fixed number of corners — it can be any polygon, with as many corners as you need.

1. Pick one of the 3 zones.
1. In its `Polygon` text field, enter the corner coordinates you noted earlier as `x1,y1;x2,y2;x3,y3;...` — comma between X and Y of a point, semicolon between points, no spaces. Decimal values are supported using a **dot** as the decimal separator (e.g. `1.5`, never `1,5` — the comma is already the X/Y separator). Negative X values are valid and simply mean the point is to the left of the sensor (e.g. `-1.5,2` is 1.5 m to the left, 2 m in front). For example, a 3×4m rectangle starting at the sensor would be `0,0;0,4;3,4;3,0`, a narrower 1.5×3m zone offset to the right would be `0.5,0;0.5,3;2,3;2,0`, and a zone centered on the sensor spanning 2 m either side would be `-2,0;-2,4;2,4;2,0`.
1. Use at least 3 points, and go around the shape in order (clockwise or counter-clockwise, doesn't matter — just don't skip across the shape) so the points form a simple, non-self-intersecting polygon.
1. The shape must stay convex — picture a rectangle, a trapezoid, a diamond, or a hexagon, not a star, an arrow, or an L-shape. If you enter an invalid (too short, unparsable, self-intersecting, or non-convex) polygon, the sensor silently ignores the change and keeps the last valid shape, so you can't break anything by typing a half-finished value.
1. Repeat for additional zones if you want to track multiple areas — see the tips below for ideas on using more than one zone.

Zone polygons are re-evaluated every 30 seconds, so after editing the text field you may need to wait up to half a minute before the zone boundary takes effect. Once the new polygon is applied, the zone's target count will change from `unavailable` to `0` (or the current number of people inside). Note that entering an invalid polygon does not reset a zone — the previous valid shape stays active until a new valid one is accepted. To fully disable a zone, clear its text field to empty and reboot the sensor; the zone will then remain inactive until a valid polygon is entered again.

*Reading zone state*

- `LD2450 Zone-1`/`2`/`3` (binary sensor): on while at least one target is detected inside that zone. Use this in automations that should only react to a person being in that specific area.
- `LD2450 Zone-1`/`2`/`3` (sensor): number of targets currently tracked inside that zone.
- Both entities share the same default name and are only distinguished by their entity type (binary sensor vs. sensor) — rename them in the entity settings if you'd like clearer labels on your dashboard, e.g. "Zone 1 Occupancy" / "Zone 1 Target Count".
- `LD2450 Presence` (binary sensor, disabled by default) and the main combined presence/occupancy sensor of the device are **not** affected by zones — they're on whenever any target is detected anywhere in range. Zones only add the extra, location-specific binary sensors described above.

*Tips*

- Zones are most useful for "only do X when someone is in this particular spot" automations — e.g. dim a light only when someone is at the desk, regardless of whether someone else is also present elsewhere in the room.
- If you do want a stricter "anyone in the room" signal than the sensor's raw range provides (e.g. to ignore detections through a doorway into a neighboring room), you can create a zone outlining your room's walls and use its occupancy sensor in your own automations instead of the default presence sensor.
- Zones can overlap, so the whole-room zone above can coexist with smaller, specific zones.
- If you need more than 3 zones, edit `sensors/ld2450.yaml` and reflash — 3 already covers most use cases.

**C4001 Presence Sensor:**

The C4001 Sensor got a couple of settings that can be changed. You can find the settings in the config section in Home Assistant. The main settings to calibrate are:

- Sustain / Trigger Sensitivity
  - The C4001 millimeter wave proximity sensor has two sensitivities: trigger sensitivity and hold sensitivity. Trigger sensitivity refers to the ease of triggering the sensor when entering the sensing area. Hold sensitivity refers to the sensitivity of continuous detection of the target after the sensor is triggered. Both trigger and hold sensitivities have 10 levels, with higher numbers indicating higher sensitivity and lower numbers indicating lower sensitivity. The default sensitivity value is 7
  - Note: Please configure the sensitivity according to the actual usage environment and requirements. Lower sensitivity requires larger movement amplitude and closer distance of the target to be detected. Higher sensitivity requires a higher demand for environmental interference. If there are interferences, it is more prone to false alarms. Setting the trigger sensitivity to 8 or 9 may cause a certain probability of false alarms, and it is mainly used in scenarios where false alarms are not sensitive. Generally, it is recommended to configure the trigger sensitivity between 2 and 6, with a value range of 0 to 9.
- Min / Max Distance
  - 0.6-25 meters
- Trigger Distance
  - The trigger distance of the C4001 millimeter wave presence sensor refers to the distance at which it can trigger from no one to someone. For example, if the maximum detection distance is configured as 10 meters, and the trigger distance is set to 6 meters, the sensor will only display "someone" when someone is within 6 meters. If someone is between 6-10 meters, it will not be triggered as "someone". The trigger distance can be set within the range of 0-25m, with a default of 6m.
  - Note: Configuring the trigger distance can optimize the problem of false triggering caused by slight movements at the edge. The smaller the trigger distance, the closer you need to be to the center axis of the sensor to trigger it. The trigger distance value cannot be greater than the difference between the maximum and minimum detection distances

### 🎯 Placement Considerations

1. When you mount the sensor high in the room it will improve presence sensing, but decrease temperature readings. Hot air rises and will skew and destabilize temperature readings.
1. Don’t place the device near a heater — it reduces temperature accuracy and can trigger the motion sensor.
1. Don’t place it directly in strong airflow (e.g., when airing the room), as the motion sensor detects rapid heat changes.

### 📢 Tips

- You can use the [underware collection](https://makerworld.com/de/models/783010-underware-2-0-infinite-cable-management?from=search#profileId-1504508) to route your cables.
- You can use [my cable clamps](https://makerworld.com/de/models/1744421-adhesive-cable-clamp-for-usb-cables-4mm-3mm#profileId-1853998) to route USB cables. They fit the cables linked here, use minimal filament, and can be attached with double-sided tape.
- You can use [my collection of ball head mounts](https://makerworld.com/de/collections/9129741-ball-head-mounts) to mount the device to cabinets, tubes, walls, desks etc.
- It’s preferable to position the device **facing the area where you stay** rather than just facing the door. The motion sensor has a wide field of view and covers most of the room, while the presence sensor works best when pointed directly at the target.
