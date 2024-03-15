// New code by Jacob Mejia
// edited by Bradley Harz
// Information from:
// https://ctms.engin.umich.edu/CTMS/index.php?example=Introduction&section=ControlPID

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PIDController {
public:
    PIDController(double kp, double ki, double kd, double target);
    double calculate(double measured_value);
    void setTarget(double target);
    void reset();

private:
    double kp, ki, kd; // Proportional, Integral, and Derivative gains
    double target; // Target value
    double integral; // Integral term
    double prev_error; // Previous error
};

#endif // PIDCONTROLLER_H