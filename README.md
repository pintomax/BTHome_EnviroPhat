# This is Python virtual env folder for latest ESPHome version 2026.1.5, Home Assistant version 2026.1.2

# Use Espressif ESP32 WROOM-32

# Ubuntu 24 LTS

# 1 create virtual env (venv)

python3 -m venv ./venv

# 2 activate it
source venv/bin/activate

# 3 connect PiMoroni EnviroPiHat (it uses I2C)

I2C Device ESP32 NodeMCU 32S
- SDA (default is GPIO 21)
- SCL (default is GPIO 22)

PiMoroni EnviroPiHat pins are same as Raspberry PI 3 HAT connections
- SDA is GPIO2 (physical pin #3)
- SCL is GPIO3 (physical pin #5)

Connect +3.3V, 5V and GND

# 5 compile and upload via USB

esphome run blebthome.yaml

# 6 Make sure BTHome integration exists in Home Assistant

# 7 check Home Assistant for a new BTHome device and connect by using the encryption key in blebthome.yaml

# 8 Some measurements are send one after the other as per BTHome specs: ex temperature and Color Temperature
Color Channel % as humidity measurements; rearrange entities, names and icon in Home Assistant

See PNG file for and example
~                                                                                                             
