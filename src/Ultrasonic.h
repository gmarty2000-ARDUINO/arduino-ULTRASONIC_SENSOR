#ifndef __ULTRASONIC_h
#define __ULTRASONIC_h

#include "Arduino.h"

class Ultrasonic {
    public:     Ultrasonic(int, int);
                int distanceInMicroseconds();
                float getTemperature();
                void setTemperature(float);
                int distanceInCentimeters();
                int distanceInMillimeters();
                String toString();
    private:    int pinTrigger;
                int pinEcho;
                float temperature;
};

#endif