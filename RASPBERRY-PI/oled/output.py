import time
import subprocess
import board
import busio
import digitalio
from PIL import Image, ImageDraw, ImageFont
import adafruit_ssd1306

# OLED Setup
oled_reset = digitalio.DigitalInOut(board.D4)
WIDTH = 128
HEIGHT = 32
BORDER = 5
i2c = board.I2C()
oled = adafruit_ssd1306.SSD1306_I2C(WIDTH, HEIGHT, i2c, addr=0x3C, reset=oled_reset)

# Font Setup
font = ImageFont.load_default()

def update_screen():
    # Create a draw object
    draw = ImageDraw.Draw(oled.image)
    
    # Clear the display.
    oled.fill(0)

    # Run the tail command and capture the output.
    log_command = "stdbuf -oL tail -n {} /var/log/pwnagotchi.log".format(HEIGHT // 8)
    tail_process = subprocess.Popen(log_command, shell=True, stdout=subprocess.PIPE, text=True, bufsize=1)

    try:
        # Display each line on the OLED screen.
        for i in range(HEIGHT // 8):
            line = tail_process.stdout.readline().strip()
            if not line:
                break
            draw.text((0, i * 8), line[:WIDTH], font=font, fill=255)

        # Update the OLED screen.
        oled.show()

    except KeyboardInterrupt:
        # Handle Ctrl+C to exit gracefully.
        pass
    finally:
        # Close the tail process when done.
        tail_process.terminate()

# Main loop
while True:
    update_screen()
    time.sleep(5)  # Adjust the sleep duration as needed

