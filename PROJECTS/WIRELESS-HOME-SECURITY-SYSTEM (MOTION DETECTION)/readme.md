# Wireless Home Secutiry
This File is to make a Wireless Home security system with a PIR motion detection Sensor.

Made by Pranav Verma.

Components Required:
1. Arduino Uno/Nano/Pro Mini - x1
2. NodeMCU - x2
3. OLED Screen 128x64 - x1
4. Power Adapter - x1
5. USB A Cable - x1
5. 9v Battery - x1
6. Jumper Wires - x?

Xtra Things Needed:
1. Strong 2.4 GHZ Wifi Connection
2. Arduino IDE
3. Breadboard (Optional)

Procedure:
Take the Arduino Uno/Nano/Pro Mini, and program the MICROCONTROLLER_ATTACHED_TO_SERVER.ino file given in the folder. Then, take one NodeMCU and program the NODEMCU_SERVER.ino file given in the folder. Connections as Follows:

For Server (UNO, NODEMCU, PIR MOTION SENSOR):
VIN (UNO) -> VIN (NODEMCU)
GND (UNO) -> GND (NODEMCU)
D1 (NODEMCU) -> D3 (UNO)
OUT (SENSOR) -> D8 (UNO) 
GND (SENSOR) -> GND (UNO)
VIN (SENSOR) -> 5V (UNO)

For Client (NODEMCU, OLED SCREEN):
GND (OLED) -> GND (NODEMCU)
VDD (OLED) -> 3.3V (NODEMCU)
SCK (OLED) -> D1 (NODEMCU)
SDA (OLED) -> D2 (NODEMCU)

Also, inside both the server and client NodeMCU, replace the ssid and password inside the code with your wifi connection
name and password.

Done!

By - Pranav Verma
