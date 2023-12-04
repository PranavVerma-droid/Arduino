import smbus

def scan_i2c():
    bus = smbus.SMBus(1)  # Change the bus number if your Raspberry Pi is using a different one

    print("Scanning for I2C devices...")
    for address in range(0, 128):
        try:
            bus.read_byte(address)
            print(f"I2C device found at address 0x{address:02X}")
        except:
            pass

if __name__ == "__main__":
    scan_i2c()

