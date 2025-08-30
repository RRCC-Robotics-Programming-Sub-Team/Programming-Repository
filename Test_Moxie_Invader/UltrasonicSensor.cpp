#include "UltrasonicSensor.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin) 
    : triggerPin(triggerPin), echoPin(echoPin) {
    pinMode(triggerPin, OUTPUT); // Set the trigger pin as an output
    pinMode(echoPin, INPUT); // Set the echo pin as an input
}

float UltrasonicSensor::getDistance() {
    // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Sets the trigger on HIGH state for 10 micro seconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    // Reads the echo pin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    return distance;
}


/* ─────────────────────────────────────────────────────────────────────────────
   RRCC Space Grant Robotics — Moxie-Invader (2023–24)

   CREDITS
   Lead Programmers: Bradley T. Harz, Zacaryas Dana, Jacob Mejia
   Editor:           Ronald Chu

   © 2025 RRCC Space Grant Robotics Team.
   License (code): Apache-2.0 — see LICENSE
   License (docs/images in repo): CC BY 4.0 — see LICENSE-docs
   ──────────────────────────────────────────────────────────────────────────── */
