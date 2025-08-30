#ifndef MotorAndESC_h
#define MotorAndESC_h

#include "Arduino.h"
#include "Servo.h"

class MotorAndESC{
  public:
    MotorAndESC(unsigned int pin, unsigned int maxSignal, unsigned int minSignalForWork); //Constructor for MotorAndESC class, pin is pwm pin for esc, maxSignal is the max signal in microseconds the ESC will take without issues, and minSignalForWork is a value for the smallest signal in miliseconds one can send to the ESC to actually see effects from the motor.
    void applyControlSignal(double controlSignal); // Updated method (Replaces void Motor)
    // Removed the old Motor method as applyControlSignal replaces its functionality
    Servo esc;
  
  private:
    int _pin;
    unsigned int _maxSignal;
    unsigned int _minSignalForWork;
    //unsigned for better funcionality, semantic correctness, and safety
};

#endif


/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Team:             Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */
