#include <Arduino.h>
#line 1 "C:\\Users\\dell\\Documents\\Arduino Robotics Code\\GitHub Repo Clone\\Programming-Repository\\Test_Moxie_Invader\\Test_Moxie_Invader.ino"
#include "UltrasonicSensor.h"
#include "MotorAndESC.h"
#include "Encoder.h"

// Define the pins
const int MOTOR_PIN = 5; // Pin for the motor control
const int ULTRASONIC_TRIGGER_PIN = 2; // Trigger Pin for HC-SR04
const int ULTRASONIC_ECHO_PIN = 3; // Echo Pin for HC-SR04

// Initialize ultrasonic sensor
UltrasonicSensor sensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);

// Initialize the motor and ESC
MotorAndESC motorControl(MOTOR_PIN, 2000, 1000); // Assuming this class handles the ESC signal

// Encoder pin (SPI pins will be used for AS5048A, adjust based on your setup)
Encoder encoder(10); // Example pin for chip select (CS), adjust as needed

void setup() {
  Serial.begin(9600);
  // Any necessary initializations for encoder or other components
}

void loop() {
  float distance = sensor.getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  // Basic logic to control motor based on distance reading
  if (distance < 20) {
    // If an obstacle is closer than 20 cm, stop or slow down the motor
    motorControl.Motor(0); // Assuming 0 stops the motor, adjust as necessary
  } else {
    // Otherwise, run the motor at a specified speed
    motorControl.Motor(1500); // Example signal value for running speed, adjust as needed
  }

  // Example of reading from the encoder (Adjust based on your encoder library/methods)
  float angle = encoder.getAngle(); // Placeholder function - replace with actual function to read encoder value
  Serial.print("Encoder Angle: ");
  Serial.println(angle);

  delay(100);
}



/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Editor:           Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */
