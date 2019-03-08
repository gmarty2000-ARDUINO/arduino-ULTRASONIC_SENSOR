#include "Ultrasonic.h"

/* ------------------------------ CONSTRUCTOR CODE ------------------------------ */

/* Constructor - It saves the pin numbers of the Ultrasonic sensor and set them in OUTPUT and INPUT mode */
Ultrasonic::Ultrasonic(int trigger, int echo) {
    this->pinTrigger = trigger;
    this->pinEcho = echo;
    this->temperature = 20.0f;

    pinMode(this->pinTrigger, OUTPUT);
    pinMode(this->pinEcho, INPUT);

    digitalWrite(this->pinTrigger, LOW);
}

/* ------------------------------ SIMPLE APIs ------------------------------ */

/* Method - It returns the distance in microseconds */
int Ultrasonic::distanceInMicroseconds() {
    digitalWrite(this->pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pinTrigger, LOW);

    return (pulseIn(this->pinEcho, HIGH) / 2);
}

/* Method - It returns the external temperature */
float Ultrasonic::getTemperature() {
    return this->temperature;
}

/* Method - It sets the external temperature */
void Ultrasonic::setTemperature(float temperature) {
    this->temperature = temperature;
}

/* ------------------------------ OTHER FUNCTIONS ------------------------------ */

/* Method - It returns the distance in centimeters */
int Ultrasonic::distanceInCentimeters() {
    double reciprocalVelocity = 10000 / (331.45 + (0.62 * this->temperature));  //  reciprocalVelocity = 1 / velocity
    int duration = this->distanceInMicroseconds();
    int centimeters = (duration / reciprocalVelocity);                          //  space   = duration * velocity =
                                                                                //          = duration / reciprocalVelocity

    return centimeters;
}

/* Method - It returns the distance in millimeters */
int Ultrasonic::distanceInMillimeters() {
    double reciprocalVelocity = 1000 / (331.45 + (0.62 * this->temperature));  //  reciprocalVelocity = 1 / velocity
    int duration = this->distanceInMicroseconds();
    int millimeters = (duration / reciprocalVelocity);                          //  space   = duration * velocity =
                                                                                //          = duration / reciprocalVelocity

    return millimeters;
}

/* Method - It returns the Ultrasonic informations */
String Ultrasonic::toString() {
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
