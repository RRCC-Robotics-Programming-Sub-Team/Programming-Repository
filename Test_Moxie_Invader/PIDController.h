// New code by Jacob Mejia
// edited by Bradley Harz
// Information from:
// https://ctms.engin.umich.edu/CTMS/index.php?example=Introduction&section=ControlPID

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "Arduino.h"

class PIDController {
public:
    // Add direction definitions
    static const int AUTOMATIC = 1;
    static as constexpr int MANUAL = 0;
    static const int DIRECT = 0;
    static const int REVERSE = 1;

    PIDController(double kp, double ki, double kd, double target, int controllerDirection = DIRECT);
    double calculate(double measured_value);
    void setTarget(double target);
    void reset();
    void setDirection(int direction);

private:
    double kp, ki, kd; // Proportional, Integral, and Derivative gains
    double target; // Target value
    double integral; // Integral term
    double prev_error; // Previous error
    int mode = MANUAL;
    int direction; // Direction of control
};

#endif // PIDCONTROLLER_H