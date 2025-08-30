#include "Encoder.h"
#include "SPI.h"
#include "Arduino.h"

static bool initialize(false);

  //Constructor for Encoder Class
Encoder::Encoder(unsigned int pin, unsigned int ClockSpeed) : _pin(pin), _useSPI(false) {
    //Set the pinMode for the chip select pin on the arduino for the encoder to be an output then default it to being high because the chip is active low.
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);

    //setting private values for initialization variables, common practice for cpp.
  _pin = pin;
  _ClockSpeed = ClockSpeed;
}

Encoder::Encoder(int csPin, bool useSPI) : _pin(csPin), _useSPI(useSPI) {
    if(useSPI) {
        pinMode(csPin, OUTPUT);
        SPI.begin();
    }
}

//or? both?

//necassary initlization method, SPI.begin() has to be called before SPI can be used so this is necassary but i need a better way of insuring it actually gets called rather than this function.
void Encoder::Initialize() {
  if(!initialize) {
    initialize = true;
    SPI.begin();
  }
}

void Encoder::UpdatePosi(uint16_t command){
  digitalWrite(_pin, LOW);
  SPI.beginTransaction(SPISettings(_ClockSpeed, MSBFIRST, SPI_MODE1));
  uint16_t response = SPI.transfer16(command); // Send the command and receive the response
  digitalWrite(_pin, HIGH); // Deactivate the chip
  SPI.endTransaction(); // End SPI transaction
  interpretResponse(response); // Call the method to interpret the response
  //TO-DO: finish this method to transfer the command to the encoder via SPI and save the send back value to a uint_16
  //Complete
}

void Encoder::interpretResponse(uint16_t response){
  posi = static_cast<float>(response); // Convert the response to float and store it in posi
  float Encoder::readAngle() {
    if(_useSPI) {
      // Implement SPI reading
    } else {
      // Implement PWM reading
    }
  // Additional conversion or interpretation logic can be added here
  }
}
//TO-DO: create another method to interpret the byte from UpdatePosi and 
//Complete


/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Team:             Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */
