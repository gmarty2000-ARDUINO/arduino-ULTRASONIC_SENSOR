#include "UltrasonicSensor.h"

/* ------------------------------ CONSTRUCTOR CODE ------------------------------ */

/* Constructor - It saves the pin numbers of the Ultrasonic sensor and set them in OUTPUT and INPUT mode */
UltrasonicSensor::UltrasonicSensor(int trigger, int echo) {
    this->pinTrigger = trigger;
    this->pinEcho = echo;
    this->temperature = 20.0f;

    pinMode(this->pinTrigger, OUTPUT);
    pinMode(this->pinEcho, INPUT);

    digitalWrite(this->pinTrigger, LOW);
}

/* ------------------------------ SIMPLE APIs ------------------------------ */

/* Method - It returns the distance in microseconds */
int UltrasonicSensor::distanceInMicroseconds() {
    digitalWrite(this->pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pinTrigger, LOW);

    return (pulseIn(this->pinEcho, HIGH) / 2);
}

/* Method - It returns the external temperature */
float UltrasonicSensor::getTemperature() {
    return this->temperature;
}

/* Method - It sets the external temperature */
void UltrasonicSensor::setTemperature(float temperature) {
    this->temperature = temperature;
}

/* ------------------------------ OTHER FUNCTIONS ------------------------------ */

/* Method - It returns the distance in centimeters */
int UltrasonicSensor::distanceInCentimeters() {
    double reciprocalVelocity = 10000 / (331.45 + (0.62 * this->temperature));  //  reciprocalVelocity = 1 / velocity
    int duration = this->distanceInMicroseconds();
    int centimeters = (duration / reciprocalVelocity);                          //  space   = duration * velocity =
                                                                                //          = duration / reciprocalVelocity

    return centimeters;
}

/* Method - It returns the distance in millimeters */
int UltrasonicSensor::distanceInMillimeters() {
    double reciprocalVelocity = 1000 / (331.45 + (0.62 * this->temperature));  //  reciprocalVelocity = 1 / velocity
    int duration = this->distanceInMicroseconds();
    int millimeters = (duration / reciprocalVelocity);                          //  space   = duration * velocity =
                                                                                //          = duration / reciprocalVelocity

    return millimeters;
}

/* Method - It calibrates the Ultrasonic sensor */
void UltrasonicSensor::calibration(int realDistance) {
    double velocity = (((double) realDistance) / this->distanceInMicroseconds()) * 10000;
    this->setTemperature((velocity - 331.45) / 0.62);
}

/* Method - It returns the UltrasonicSensor informations */
String UltrasonicSensor::toString() {
    String ret = String("Ultrasonic: {");
    ret.concat("pinTrigger=");
    ret.concat(this->pinTrigger);
    ret.concat(", pinEcho=");
    ret.concat(this->pinEcho);
    ret.concat(", temperature=");
    ret.concat(this->temperature);
    ret.concat("}");
    
    return ret;
}
