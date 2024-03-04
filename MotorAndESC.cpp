#include "Arduino.h"
#include "MotorAndESC.h"

#include "Servo.h"

//constructor for MotorAndESC class
MotorAndESC::MotorAndESC(unsigned int pin, unsigned int maxSignal, unsigned int minSignalForWork) {
    //setting pin for pwm signal to ESC as OUTPUT, then attaching a servo object to it;
  pinMode(pin, OUTPUT);
  esc.attach(pin, -1 * maxSignal, maxSignal);
  
    //Setting private variables for 
  _pin = pin;
  _maxSignal = maxSignal;
  _minSignalForWork = minSignalForWork;
}

void MotorAndESC::Motor(int pwm) {
  if(pwm < 0) {
    esc.writeMicroseconds(map(pwm, 0, -1*_maxSignal, -1*_minSignalForWork, -1*_maxSignal));
  } else if(pwm > 0) {
    esc.writeMicroseconds(map(pwm, 0, _maxSignal, _minSignalForWork, _maxSignal));
  } else{
    esc.writeMicroseconds(0);
  }
}
