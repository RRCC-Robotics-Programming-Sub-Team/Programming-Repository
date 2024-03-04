#ifndef MotorAndESC_h
#define MotorAndESC_h

#include "Arduino.h"
#include "Servo.h"

class MotorAndESC{
  public:
    MotorAndESC(unsigned int pin, unsigned int maxSignal, unsigned int minSignalForWork); //Constructor for MotorAndESC class, pin is pwm pin for esc, maxSignal is the max signal in microseconds the ESC will take without issues, and minSignalForWork is a value for the smallest signal in miliseconds one can send to the ESC to actually see effects from the motor.
    void Motor(int pwm);
    Servo esc;
  private:
    int _pin;
    int _maxSignal;
    int _minSignalForWork;
};

#endif
