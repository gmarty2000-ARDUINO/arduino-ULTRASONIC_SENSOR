#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(13, 12);

void setup() {
  Serial.begin(9600);
}

void loop() {
  ultrasonic.calibration(10);
  int temperature = ultrasonic.getTemperature();

  Serial.println(temperature);
}
