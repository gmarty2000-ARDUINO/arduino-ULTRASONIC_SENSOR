#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(13, 12);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.distanceInMicroseconds();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" us");
}
