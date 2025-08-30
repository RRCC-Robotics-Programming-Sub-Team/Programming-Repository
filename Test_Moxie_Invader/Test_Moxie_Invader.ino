#include "UltrasonicSensor.h"
#include "PIDController.h" // Ensure this library is installed for PID control
//#include <PID_v1.h> // Ensure this library is installed for PID control
#include "MotorAndESC.h"
#include "Encoder.h" // Include your encoder library if needed

// Define the pins
const int MOTOR_PIN = 7; // Pin for the motor control
const int ULTRASONIC_TRIGGER_PIN = 3; // Trigger Pin for HC-SR04
const int ULTRASONIC_ECHO_PIN = 4; // Echo Pin for HC-SR04
const int Encoder = 2; // Encoder Pin

// PID parameters (Tune these based on your system's response)
double Setpoint, Input, Output;
double Kp=2.0, Ki=5.0, Kd=1.0;

// Initialize ultrasonic sensor
UltrasonicSensor sensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);

// Initialize the motor and ESC
MotorAndESC motorControl(MOTOR_PIN, 2000, 1000); // Assuming this class handles the ESC signal

// Initialize PID Controller
PIDController myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, PIDController::DIRECT);

void setup() {
  Serial.begin(9600);

  // Setup for encoder (If your encoder setup is complex, you may need additional initialization here)
  pinMode(Encoder, INPUT);
  // Initialize PID controller
  Setpoint = 20; // Example setpoint: aiming for a 20 cm distance from an obstacle
  PIDController myPID(Kp, Ki, Kd, Setpoint);
  myPID.setMode(PIDController::AUTOMATIC); // Turn the PID on
  myPID.setDirection(PIDController::DIRECT); // Optional if you want to change it dynamically
}

void loop() {
  float distance = sensor.getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  Input = distance;
  myPID.calculate(Input); // PID computation to adjust motor speed based on distance
  
  // Use the PID Output to adjust motor speed
  motorControl.Motor(Output); // You'll need to map or scale Output to your motor's speed range if necessary

  // Example encoder usage (adjust according to your encoder's specific library/method)
  float angle = encoder.readAngle(); 
  // Serial.print("Encoder Angle: ");
  // Serial.println(angle);

  if (myPID.Compute()) {
        // If PID computation was performed
        motorControl.Motor(Output);  // Use the PID output to control the motor
    }

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
