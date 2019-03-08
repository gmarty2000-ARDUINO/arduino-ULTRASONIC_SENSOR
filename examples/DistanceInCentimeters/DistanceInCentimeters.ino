#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(13, 12);

void setup() {
  Serial.begin(9600);
  
  int temperature = 22;
  ultrasonic.setTemperature(temperature);
}

void loop() {
  int distance = ultrasonic.distanceInCentimeters();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
