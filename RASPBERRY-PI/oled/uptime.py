# Created by: Michael Klements
# For Raspberry Pi Desktop Case with OLED Stats Display
# Base on Adafruit CircuitPython & SSD1306 Libraries
# Installation & Setup Instructions - https://www.the-diy-life.com/add-an-oled-stats-display-to-raspberry-pi-os-bullseye/
import time
import board
import busio
import digitalio

from PIL import Image, ImageDraw, ImageFont
import adafruit_ssd1306

import subprocess
import socket
import shutil


# Define the Reset Pin
oled_reset = digitalio.DigitalInOut(board.D4)

# Display Parameters
WIDTH = 128
HEIGHT = 32  # Adjusted for a 128x32 screen
BORDER = 5

# Display Refresh
LOOPTIME = 1.0

# Use for I2C.
i2c = board.I2C()
oled = adafruit_ssd1306.SSD1306_I2C(WIDTH, HEIGHT, i2c, addr=0x3C, reset=oled_reset)

# Clear display.
oled.fill(0)
oled.show()

# Create blank image for drawing.
# Make sure to create image with mode '1' for 1-bit color.
width = oled.width
height = oled.height
image = Image.new('1', (width, height))

# Get drawing object to draw on image.
draw = ImageDraw.Draw(image)

# Draw a black filled box to clear the image.
draw.rectangle((0, 0, width, height), outline=0, fill=0)

# Draw some shapes.
# First define some constants to allow easy resizing of shapes.
padding = -2
top = padding
bottom = height - padding
# Move left to right keeping track of the current x position for drawing shapes.
x = 0

# Load default font.
font = ImageFont.load_default()

# Alternatively load a TTF font.  Make sure the .ttf font file is in the same directory as the python script!
# Some other nice fonts to try: http://www.dafont.com/bitmap.php
# Icons website: https://icons8.com/line-awesome
font = ImageFont.truetype('/home/pi/oled/PixelOperator.ttf', 15)
icon_font = ImageFont.truetype('/home/pi/oled/lineawesome-webfont.ttf', 18)

while True:
    # Draw a black filled box to clear the image.
    draw.rectangle((0, 0, width, height), outline=0, fill=0)

    # Shell scripts for system monitoring from here: https://unix.stackexchange.com/questions/119126/command-to-display-memory-usage-disk-usage-and-cpu-load
    cmd_uptime = "uptime -p"
    uptime = subprocess.check_output(cmd_uptime, shell=True)

    cmd_cpu = "top -bn1 | grep load | awk '{printf \"%.2f%%\", $(NF-2)}'"
    cpu_percentage = subprocess.check_output(cmd_cpu, shell=True)

    cmd_ram = "free -m | awk 'NR==2{printf \"%.2f%%\", $3*100/$2 }'"
    ram_percentage = subprocess.check_output(cmd_ram, shell=True)

    disk_usage = shutil.disk_usage("/")
    temperature = subprocess.check_output("vcgencmd measure_temp", shell=True).decode("utf-8").strip()


    # Text
    # Text Uptime
    draw.text((0, 0), "Uptime: " + str(uptime, 'utf-8'), font=font, fill=255)
    # Text CPU and RAM percentage
    draw.text((0, 13), "CPU: " + str(cpu_percentage, 'utf-8') + " RAM: " + str(ram_percentage, 'utf-8'), font=font, fill=255)

    draw.text((0, 2 * 13), f"Disk: {disk_usage.used / 32GB Temp: {temperature}", font=font, fill=255)
    # Display image.
    oled.image(image)
    oled.show()
    time.sleep(LOOPTIME)

