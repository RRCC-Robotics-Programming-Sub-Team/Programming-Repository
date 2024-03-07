//TODO: recreate the PID (Proportional Integral Derivative) control class for calculating control steps.
#include "PIDController.h"
#include <iostream>

// Constructor to initialize PID gains (kp, ki, kd), target value, integral term, and previous error
// where Kp = proportional gain, Ki = integral gain, and Kd = derivative gain.
PIDController::PIDController(double kp, double ki, double kd, double target)
    : kp(kp), ki(ki), kd(kd), target(target), integral(0), prev_error(0) {}

// Function to calculate control signal based on the measured value
double PIDController::calculate(double measured_value) {
    double error = target - measured_value; // Calculate the error between target and measured value
    integral += error; // Update the integral term
    double derivative = error - prev_error; // Calculate the derivative term
    prev_error = error; // Update the previous error
    double control_signal = kp * error + ki * integral + kd * derivative; // Calculate the control signal using PID formula
    return control_signal; // Return the control signal
}

// Function to set a new target value
void PIDController::setTarget(double newTarget) {
    target = newTarget; // Update the target with the new value
}

// Function to reset integral and derivative terms
void PIDController::reset() {
    integral = 0;
    prev_error = 0;
}
