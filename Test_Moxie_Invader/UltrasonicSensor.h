// UltrasonicSensor.h
#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "C:\Users\dell\Documents\arduino-cli_0.35.3_Windows_64bit\arduino-cli\arduino-cli.exe"
class UltrasonicSensor {
public:
    UltrasonicSensor(int triggerPin, int echoPin);
    float getDistance();

private:
    int triggerPin;
    int echoPin;
    long duration;
    float distance;
};

#endif // ULTRASONICSENSOR_H