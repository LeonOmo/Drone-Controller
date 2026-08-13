# Custom DIY Drone Controller

A custom ESP32-based drone remote controller designed from scratch.

## Features
- ESP32 Wroom: Microcontroller
- ExpressLRS / CRSF Protocol: Serial communication (420 kbaud) via RadioMaster RP1 module.
- Live OLED Telemetry: signal strength, battery status, altitude and speed
- Custom Control Inputs:
  - 2x Dual-axis Joysticks (Roll, Pitch, Yaw, Throttle)
  - 5x Toggle Switches (Arm, Flight Mode, Buzzer, Landing Gear, Folding Arms)
  - 3x Potentiometers (Motor Caps & 1/2 & 3/4 Motor Cap)
  - Hardware Status LEDs (Arm, Landing Gear, Link Status)

## CAD Model
- Designed from scratch in Onshape.
<img width="503" height="538" alt="Screenshot 2026-08-10 184236" src="https://github.com/user-attachments/assets/4b860eff-2314-4c8d-bb37-55fe5dfbd541" />

## PCB & Schematic
- Designed in KiCad.
<img width="559" height="437" alt="Screenshot 2026-08-10 184313" src="https://github.com/user-attachments/assets/28f8af46-0532-4528-bb45-701e5edfd93e" />
<img width="456" height="545" alt="Screenshot 2026-08-10 184337" src="https://github.com/user-attachments/assets/aac84dc7-bd6e-4cac-bc6f-5d33df1790b9" />

## BOM
- ESP32-WROOM-32E Modul
- Voltage Regulator: AMS1117-3.3
- USB Connector: 16-Pin Female USB-C Receptacle
- RadioMaster RP1 ELRS Transmitter/Receiver Module
- 0.96" SSD1306 I2C OLED Display
- 2x PS2 Joysticks
- 5x MTS-102-A2 Toggle Switches
- 3x R-0904N-L-25KS Potentiometers
- 3x LEDs
- 1x Custom 3D Printed Enclosure
- 8x Resisitor (3x 220, 6x 10k, 2x 5,1k)
- 3x Capacitor (2x 100nF, 1x 10uF)
- Male Pin Headers (2.54 mm Pitch: 1x 1x4 Pin, 2x 1x5 Pin)
- Female Pin Headers (2.54 mm: 1x 1x4)

## Firmware Setup
Built with PlatformIO in Visual Studio Code.

## Extra Stuff
Please tell me if my funding request is too high i think i asked for too much.