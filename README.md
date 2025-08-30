# Moxie-Invader (2023–24)

Closed-loop robot drive stack for the RRCC Space Grant Robotics team.  
Arduino-based control with encoder feedback, PID control, ultrasonic ranging, and ESC motor drive.

## Season
2023–24 academic year (archival snapshot of the competition code and docs).

## Features
- PID speed/position control with encoder feedback  
- Ultrasonic distance sensing for basic obstacle awareness  
- ESC/PWM motor control (Servo-style pulses)  
- Modular C++ classes for sensor/actuator layers

## Hardware (typical)
- Arduino-compatible MCU (e.g., Uno/Nano; 5V logic)
- ESC + DC/BLDC motor
- Rotary encoder (SPI; CS wired to your chosen pin)
- HC-SR04-style ultrasonic sensor
- 5–12V power per motor/ESC spec, **common ground**

## Default pins (adjust in code)
```cpp
// Moxie_Invader.ino (defaults from the 2023–24 season)
const int MOTOR_PIN   = 11; // ESC PWM
const int ENCODER_PIN = 2;  // encoder CS (SPI used under the hood)
const int TRIGGER_PIN = 9;  // ultrasonic trigger
const int ECHO_PIN    = 10; // ultrasonic echo
