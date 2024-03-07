// UltrasonicSensor.h
#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

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
