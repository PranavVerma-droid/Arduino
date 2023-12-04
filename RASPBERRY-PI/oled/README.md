# Using a 128 x 32 SSD1302 Screen with Raspberry Pi 4

This directory uses python3 to show some basic stats to a 0.91 inch OLED Screen (128 x 32)

To Start, Run the Following Commands:

`sudo apt-get update`
`sudo apt-get full-upgrade`
`sudo reboot`
`sudo apt-get install python3-pip`
`sudo pip3 install --upgrade setuptools`

`sudo pip3 install --upgrade adafruit-python-shell`
`sudo python3 raspi-blinka.py`
`sudo i2cdetect -y 1`

If it hasn’t shown up then either I2C communication isn’t turned on, which can be done through the configuration utility, or your wiring is not correct. If you get a table full of characters (all addresses shown) then you’ve probably made a wiring mistake as this happens if SDA is shorted to ground. Go back and re-check your connections to your Pi and display and re-check that you’ve got I2C communication enabled after a reboot.

To enable I2C communication, use the configuration utility by entering:

`sudo raspi-config`

`sudo pip3 install adafruit-circuitpython-ssd1306`
`sudo apt-get install python3-pil`

Thats it! Now run python3 uptime.py to see the Uptime of the Machine & CPU and RAM!


