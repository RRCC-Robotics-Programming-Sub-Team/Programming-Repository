Moxie-Invader (2023–24)

Closed-loop robot drive stack for the RRCC Space Grant Robotics team.
Arduino-based control with encoder feedback, PID control, ultrasonic ranging, and ESC motor drive.

Season

2023–24 academic year (archival snapshot of the competition code and docs).

Features

PID speed/position control with encoder feedback

Ultrasonic distance sensing for basic obstacle awareness

ESC/PWM motor control (Servo-style pulses)

Modular C++ classes for sensor/actuator layers

Hardware (typical)

Arduino-compatible MCU (e.g., Uno/Nano; 5V logic)

ESC + DC/BLDC motor

Rotary encoder (SPI; CS wired to your chosen pin)

HC-SR04-style ultrasonic sensor

5–12V power per motor/ESC spec, common ground

Default pins (adjust in code)
// Moxie_Invader.ino (defaults from the 2023–24 season)
const int MOTOR_PIN = 11;       // ESC PWM
const int ENCODER_PIN = 2;      // encoder CS (SPI used under the hood)
const int TRIGGER_PIN = 9;      // ultrasonic trigger
const int ECHO_PIN = 10;        // ultrasonic echo

Repo structure
Moxie_Invader.ino                  # main sketch: setup/loop, control flow
Encoder.h / Encoder.cpp            # SPI encoder interface
MotorAndESC.h / MotorAndESC.cpp    # ESC PWM output (Servo library)
UltrasonicSensor.h / UltrasonicSensor.cpp  # distance sensing
PIDController.h / PID.cpp          # PID implementation
PIDMainSimulationFunction*.cpp     # desktop-only PID demo (not for Arduino)

Build & upload

Arduino IDE

Open Moxie_Invader.ino.

Select your board/port.

Sketch → Verify / Upload.

PlatformIO (optional)

pio run           # build
pio run -t upload # flash
pio device monitor

Tuning & operation

Power the ESC/motor per vendor specs (common ground with MCU).

In Moxie_Invader.ino, set initial PID gains:

PIDController pid(0.5, 0.1, 0.2, 100); // Kp, Ki, Kd, target


Use the serial monitor to observe distance/encoder output.

Tune Kp → Ki → Kd (small steps). Re-verify motor direction and encoder sign.

Safety

Remove wheels/prop before first power-up.

Use a current-limited bench supply where possible.

Double-check ground is shared across ESC, sensors, and MCU.

Documentation

A detailed walk-through of each module (files, roles, and data flow) is provided in the team’s PDF documentation. 

Credits

Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia

Editor: Ronald Chu

For per-file headers, append this footer to your C/C++ sources:

/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Editor:           Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */


And (recommended) add an SPDX line at the very top of each source file:

/* SPDX-License-Identifier: Apache-2.0 */

License

Source code: Apache-2.0 (see LICENSE)

Documentation & images: CC BY 4.0 (see LICENSE-docs)
© 2025 RRCC Space Grant Robotics Team — Bradley T. Harz (Lead), Zacaryas Dana, Jacob Mejia; Editor: Ronald Chu

Acknowledgments

RRCC Space Grant program, mentors, and peers who supported the 2023–24 season.
