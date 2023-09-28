# ESP32 Cam Folder

This Folder has all the files to Upload Code to the AI-Thinker ESP32 CAM Module.

P.S. Here is how to upload code to it without a USB to TTL Programmer:

## ESP32 CAM Pin Layout
<img src="https://www.circuitschools.com/wp-content/uploads/2020/06/esp32-cam-module-pinout-diagram.webp">

## Add External Antenna to ESP32 CAM

<img src="https://www.circuitschools.com/wp-content/uploads/2021/11/how-to-attach-external-antenna-to-ESP32-CAM-board.webp">

To attach an external antenna first desolder the resister carefully as it is very small and resolder it in the opposite position as in the above image. If you feel soldering the resistor again is hard then just connect the points with solder without resistor. It works as long as the points are connected.

## Circuit Diagram to interface ESP32CAM with Arduino UNO

<img src="https://www.circuitschools.com/wp-content/uploads/2021/12/Interfacing-Esp32-CAM-with-arduino-uno-to-upload-the-code.webp">

From the above schematic diagram you can see that there are two jumper cables connected one is for ESP32CAM connected between GND and IO0, and another is for Arduino UNO GND and RESET pins. ESP32CAM module is powered from the Arduino UNO 5v and GND pins connected to same on ESPCAM. The data transfer pins UOT and UOR from the ESP32CAM are connected to TX and RX pins of Arduino respectively.

Thats it for connections now you can connect the Arduino UNO board to PC and follow the below steps to upload the code.

### Setting up Arduino IDE.
Add ESP32 board manager by opening File -> Preferences and paste the below URL in the Additional boards manager URLs field.

https://dl.espressif.com/dl/package_esp32_index.json

### Uploading the code: ESP32CAM webserver

After clicking on upload icon you can see the connecting dots as the above image, when you see them press the RST(Reset button) on the board which leads to code upload, with in few seconds you will see the message “Done uploading” on status bar of Arduino IDE means code uploaded successfully.

Now remove the jumper connection between GPIO1(IO0) and GND on ESP32 CAM module. (Dont Remove Reset and Ground on Arduino.) Open serial monitor and set the baud rate to the value which we mentioned in the code and press RST button on the ESP cam board.