#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(13, 12);

void setup() {
  Serial.begin(9600);
  
  int temperature = 21.5;
  ultrasonic.setTemperature(temperature);
}

void loop() {
  int distance = ultrasonic.distanceInMillimeters();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");
}
