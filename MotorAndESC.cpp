#include "Arduino.h"
#include "MotorAndESC.h"
#include "Servo.h"

//constructor for MotorAndESC class
MotorAndESC::MotorAndESC(unsigned int pin, unsigned int maxSignal, unsigned int minSignalForWork)
    //setting pin for pwm signal to ESC as OUTPUT, then attaching a servo object to it;
  : _pin(pin), _maxSignal(maxSignal), _minSignalForWork(minSignalForWork) {
  pinMode(pin, OUTPUT);
  esc.attach(pin, maxSignal, maxSignal); //(May not need Min/Max Parameters. (maxSignal, maxSignal) min/max parameters is only necessary if specific pulse width boundaries are necessary for your ESC model.)
  }
  
    //Setting private variables for 
  //_pin = pin;
  //_maxSignal = maxSignal;
  //_minSignalForWork = minSignalForWork;
  //(This part is unneeded. Initializer List is in constructor's body to allow direct initialization of member variables)

// Updated method to apply control signal from PID output directly
void MotorAndESC::applyControlSignal(double controlSignal) {
    // Map PID output (-1.0 to 1.0) to the PWM range understood by the ESC
    int pwmOutput = map(controlSignal, -1.0, 1.0, _minSignalForWork, _maxSignal);
    // Use writeMicroseconds to apply the mapped PWM output
    esc.writeMicroseconds(pwmOutput);
}

//void MotorAndESC::Motor(int pwm) {
  //if(pwm < 0) {
    //esc.writeMicroseconds(map(pwm, 0, -1*_maxSignal, -1*_minSignalForWork, -1*_maxSignal));
  //} else if(pwm > 0) {
    //esc.writeMicroseconds(map(pwm, 0, _maxSignal, _minSignalForWork, _maxSignal));
  //} else{
    //esc.writeMicroseconds(0);
  //}
//}

//void MotorAndESC::Motor(int pwm) {
  //if(pwm < 0) {
     //- Assuming `pwm` ranges from -_maxSignal to 0 for reverse,
     //- map this range to appropriate pulse widths for reverse control.
    //esc.writeMicroseconds(map(pwm, -_maxSignal, 0, _minSignalForWork, 1500));
  //} else if(pwm > 0) {
     //- For forward control, assuming `pwm` ranges from 0 to _maxSignal,
     //- map this range to pulse widths from the neutral point to _maxSignal.
    //esc.writeMicroseconds(map(pwm, 0, _maxSignal, 1500, _maxSignal));
  //} else {
     //- Use the neutral point pulse width to stop the motor.
    //esc.writeMicroseconds(1500);
  //}
//}