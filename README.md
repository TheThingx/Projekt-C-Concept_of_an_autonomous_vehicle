## Projekt-C-Concept_of_an_autonomous_vehicle

## Team members
- Tomáš Bukva (HC04_Sensor_library, text editing)
- Jakub Plachtička (Car_library, Main code)
- Denis Knap (HC04_Sensor_library, text editing)
- Marek Karlíček (Car_library, Main code)
  
## Hardware description
 ![schematic](images/schematic.png)

---
### IR sensor TCRT50000
Is a infrared receiver and transmiter unit with tunable detection range. We use two of these sensors in our car concept installed under the front bumper. Both of them are used for surface change detection to keep the car following the line on the ground (in our case, the line has been made from a black electric tape).

**Features:**
1. Operating Voltage: 3,3 - 5 V DC
2. Current consumption (5 V): 43 mA
3. Detection range: 0 - 3 cm

**Working principle**
1. IR transmitter LED emits light continuously
2. If object/different surface is placed in front of the sensor, emited IR reflects back to the reciever
3. The comparator circuit in the unit receives a signal from the reciever
4. The comparator processes the signal and sends it to the OUT pin

 **Pinout Description:**
 1. VCC: 5 V power supply
 2. GND: ground pin
 3. OUT: pin A1 for the left unit, pin A0 for the right unit
 
 ---
 ### HC-SR04
 Is a popular ultrasonic distance sensor for measuring distances. It operates by emitting ultrasonic waves and measuring the time it takes for the sound waves to bounce back after hitting an obstacle.
 
 **Features:**
1.  Operating Voltage: 5 V DC.
2.  Measuring Range: 2 cm to 400 cm.
3.  Accuracy: ±3 mm.
4.  Signal Pins:
    - Trig Pin: Trigger input to send the ultrasonic signal.
    -  Echo Pin: Output signal for measuring the duration of the reflected pulse.
5.  Ultrasound Frequency: 40 kHz.

**Working Principle:**
1.  The sensor emits a short ultrasonic burst when a signal is sent to the  **Triger Pin**.
2.  This burst travels through the air and reflects off an object.
3.  The  **Echo Pin**  generates a signal based on the time it takes for the sound to return.
4.  Using the formula: Distance=Time×Speed of Sound/2. The speed of sound in air is approx. 343 m/s.

 **Pinout Description:**
1.  VCC:  Connects to a 5V power supply.
2.  GND:  Ground pin.
3.  Trig:  Trigger pin for sending pulses.
4.  Echo:  Echo pin for receiving the reflected pulse.
---

### OLED display
An generic I2C OLED display is used to indicate measured distance from the HC-SR04 ultrasound sensor. The display was also used during the process of coding for troubleshooting.

**Features:**
1.  Operating Voltage: 3,3 - 5 V DC.
2.  Low consumption
3.  Resolution of 128x64 pixels
4.  Communication by I2C protocol

**Pinout Description:**
1.  VCC:  Connects to a 5V power supply
2.  GND:  Ground pin
3.  SCK:  Pin A5
4.  SDA:  Pin A4
---
### Step-down converter
A step-down converter was used to bring the voltage from the used battery down to 5 V to provide for the Arduino board. 

---
We also used a servo motor (already mounted in the car) for steering the car that was plugged to pin D5, 5 V DC and GND as well as the two drivers for both rear BLDC motors connected to D9 pin and direct power supply from the battery. 

## Software description
### Flow chart diagram
Here is simple flow chart diagram of the code we have used in our car.
 ![flowchart_code](images/flowchart.svg)


### Doplnit car library
---
### HC-SR04
The  **HC-SR04 library**  uses two pins for operation: one for the  **Trigger**  (output) and one for the  **Echo**  (input). Additionally, it relies on  **Timer0**  of the microcontroller for time measurement.

1.  **Operation Process:**
    
    -   The microcontroller sends a trigger pulse to the sensor via the trigger pin. This initiates an ultrasonic burst.
    -   Afterward, the microcontroller monitors the echo pin, waiting for the response signal.
    -   Once the echo pin goes HIGH, the timer starts counting. The signal's HIGH duration is proportional to the distance of the detected object.
    -   The microcontroller calculates the distance in millimeters based on the measured time.
2.  **Limitations:**
    
    -   Due to the limited resolution of  **Timer0**  (8 bits), the measurement precision is approximately  **±4 mm**.
    -   The maximum measurable distance is around  **600 mm**  because of the timer's overflow at 8 bits.

## Instructions and photos

**Distance Measurment:**
 ![distance_mes](images/IMG_3246%202.JPG)
 
**Messy Testing Assembly:**
 ![distance_mes](images/rotated_assemly.JPG)

**TCRT5000 IR Sensor:**
![TCRT5000 IR sensor](https://img.gme.cz/detail/400/400/eshop_data/eshop_data/11/775-141/pctdetail.775-141.1.webp)

**HC_SR04 Sensor:**
![HC-SR04](https://img.gkbcdn.com/p/2015-12-17/hc-sr04-ultrasonic-sensor-distance-measuring-module-3-3v---5v-compatible-for-arduino-nodemcu-1571976572471._w500_.jpg)


## References and tools
**Visual studio code - PlatformIO**

nevim externí knihovny a tak asi...
