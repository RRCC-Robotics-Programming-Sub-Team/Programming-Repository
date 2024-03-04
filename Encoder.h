#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder{
  public:
    Encoder(unsigned int pin, unsigned int ClockSpeed); //Constructor for Encoder object, it has a chip select pin and Clock Speed in hz.
    float GetPosi(); //Function to return the rotation/position count of the encoder.
    void UpdatePosi(uint16_t command); //Function that reads a value from the encoder.
    void ResetPosi(); //Function to set rotation/position count back to 0;
    void Initialize(); //Function to intialize SPI protocals. Needs to be called once in setup of function, on any one of the Encoder objects;
    float posi = 0.0;
  private:
    int _pin; //private pin variable for class
    int _ClockSpeed;
};

#endif
