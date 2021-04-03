# ArduinoDatalogger
Arduino Datalogger to monitor voltage, current, temperature - save to SD card with RTC timestamp and display on TFT monitor.

## Components:
Arduino Uno  
Adafruit Datalogging Shield  
Adafruit SHT40 I2C Temperature and Humidity Sensor  
1.44" TFT LCD Module  
Voltage Divider / Current Measurement circuit  
Relay Shutoff

## Current Status
- Serial Monitor 
- Write/Error LEDs
- RTC reporting

## Roadmap
- TFT Config / show Serial Monitor 
- SD Card File creation (increment)
- SD Card Write
- Temperature Read
- Temp Write to SD
- Read Voltage
- Voltage Write to SD
- Read Current
- Current Write to SD
- Temp Check against overTemp
- If OverTemp - Relay Shutdown
