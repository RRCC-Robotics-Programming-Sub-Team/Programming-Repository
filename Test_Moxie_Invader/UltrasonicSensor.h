// UltrasonicSensor.h
#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "Arduino.h"
//This is path for Arduino.h file in my computer.
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


/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Editor:           Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */
