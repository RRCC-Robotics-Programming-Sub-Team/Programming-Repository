#include "UltrasonicSensor.h"
#include "PIDController.h" // Ensure this library is installed for PID control
#include "MotorAndESC.h"
#include "Encoder.h" // Include your encoder library if needed

// Define the pins
const int MOTOR_PIN = 5; // Pin for the motor control
const int ULTRASONIC_TRIGGER_PIN = 2; // Trigger Pin for HC-SR04
const int ULTRASONIC_ECHO_PIN = 3; // Echo Pin for HC-SR04

// PID parameters (Tune these based on your system's response)
double Setpoint, Input, Output;
double Kp=2.0, Ki=5.0, Kd=1.0;

// Initialize ultrasonic sensor
UltrasonicSensor sensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);

// Initialize the motor and ESC
MotorAndESC motorControl(MOTOR_PIN, 2000, 1000); // Assuming this class handles the ESC signal

// Initialize PID Controller
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  Serial.begin(9600);

  // Setup for encoder (If your encoder setup is complex, you may need additional initialization here)

  // Initialize PID controller
  Setpoint = 20; // Example setpoint: aiming for a 20 cm distance from an obstacle
  myPID.SetMode(AUTOMATIC); // Turn the PID on
}

void loop() {
  float distance = sensor.getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  Input = distance;
  myPID.Compute(); // PID computation to adjust motor speed based on distance
  
  // Use the PID Output to adjust motor speed
  motorControl.Motor(Output); // You'll need to map or scale Output to your motor's speed range if necessary

  // Example encoder usage (adjust according to your encoder's specific library/method)
  // float angle = encoder.getAngle(); 
  // Serial.print("Encoder Angle: ");
  // Serial.println(angle);

  delay(100);
}