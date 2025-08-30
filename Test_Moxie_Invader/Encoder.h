#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder{
  public:
    Encoder(unsigned int pin, unsigned int ClockSpeed); //Constructor for Encoder object, it has a chip select pin and Clock Speed in hz.
    Encoder(int csPin, bool useSPI);
    float GetPosi(); //Function to return the rotation/position count of the encoder.
    void UpdatePosi(uint16_t command); //Function that reads a value from the encoder.
    void ResetPosi(); //Function to set rotation/position count back to 0;
    void Initialize(); //Function to intialize SPI protocals. Needs to be called once in setup of function, on any one of the Encoder objects;
    void interpretResponse(uint16_t response); // Declare the new method here
    // Other members...
    float readAngle();
    float posi = 0.0;
  private:
    int _pin; //private pin variable for class
    bool _useSPI; //private boolean variable for class
    int _ClockSpeed;
};

#endif


/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Editor:           Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */
