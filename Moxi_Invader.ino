#include "UltrasonicSensor.h"

UltrasonicSensor sensor(9, 10); // Example pins: 9 for trigger, 10 for echo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float distance = sensor.getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000); // Delay a second between measurements
}
