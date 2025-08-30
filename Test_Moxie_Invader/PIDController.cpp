//TODO: recreate the PID (Proportional Integral Derivative) control class for calculating control steps.
//finito
#include "PIDController.h"
//#include <PID_v1.h> // Ensure this library is installed for PID control
#include "Arduino.h"
//#include <iostream> //(#include <iostream> is removed; not needed for Arduino)

// Constructor to initialize PID gains (kp, ki, kd), target value, integral term, and previous error
// where Kp = proportional gain, Ki = integral gain, and Kd = derivative gain.
PIDController::PIDController(double kp, double ki, double kd, double target, int controllerDirection)
    : kp(kp), ki(ki), kd(kd), target(target), integral(0), prev_error(0) direction(controllerDirection) {}

// Function to calculate control signal based on the measured value
double PIDController::calculate(double measured_value) {
    double error = target - measured_value; // Calculate the error between target and measured value
    integral += error; // Update the integral term
    double derivative = error - prev_error; // Calculate the derivative term
    prev_error = error; // Update the previous error
    double control_signal = kp * error + ki * integral + kd * derivative; // Calculate the control signal using PID formula
    
    // Check direction for control signal inversion
    if (direction == REVERSE) {
        control_signal = -control_signal;
    }
    
    return control_signal; // Return the control signal
}

void PIDController::setMode(int mode) {
    this->mode = mode;
}

bool PIDController::Compute() {
    if (mode == AUTOMATIC) {
        // Perform PID calculation and update output
        return true; // Return true if the PID was computed
    }
    return false; // Return false if in manual mode, hence no compute
}

// Function to set a new target value
void PIDController::setTarget(double newTarget) {
    target = newTarget; // Update the target with the new value
}

void PIDController::setDirection(int dir) {
    direction = dir;
}

// Function to reset integral and derivative terms
void PIDController::reset() {
    integral = 0;
    prev_error = 0;
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
