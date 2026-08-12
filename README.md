# Custom DIY Drone Controller

A custom ESP32-based drone remote controller designed from scratch.

## Features
- ESP32 Wroom: Microcontroller
- ExpressLRS / CRSF Protocol: Serial communication (420 kbaud) via RadioMaster RP1 module.
- Live OLED Telemetry: signal strength, battery status, altitude and speed
- Custom Control Inputs:
  - 2x Dual-axis Joysticks (Roll, Pitch, Yaw, Throttle)
  - 5x Toggle Switches (Arm, Flight Mode, Buzzer, Landing Gear, Folding Arms)
  - 3x Potentiometers (Motor Caps & Master Cap)
  - Hardware Status LEDs (Arm, Landing Gear, Link Status)

## CAD Model
- Designed from scratch in Onshape.
<img width="503" height="538" alt="Screenshot 2026-08-10 184236" src="https://github.com/user-attachments/assets/4b860eff-2314-4c8d-bb37-55fe5dfbd541" />

## PCB & Schematic
- Designed in KiCad.
<img width="559" height="437" alt="Screenshot 2026-08-10 184313" src="https://github.com/user-attachments/assets/28f8af46-0532-4528-bb45-701e5edfd93e" />
<img width="456" height="545" alt="Screenshot 2026-08-10 184337" src="https://github.com/user-attachments/assets/aac84dc7-bd6e-4cac-bc6f-5d33df1790b9" />

## BOM
- ESP32 WROOM-32 Development Board
- RadioMaster RP1 ELRS Transmitter/Receiver Module
- 0.96" SSD1306 I2C OLED Display
- 2x PS2 Joysticks
- 5x MTS-102-A2 Toggle Switches
- 3x R-0904N-L-25KS Potentiometers
- 3x LEDs
- 1x Custom 3D Printed Enclosure

## Firmware Setup
Built with PlatformIO in Visual Studio Code.

## Extra Stuff
I HATE MY DESIGN
