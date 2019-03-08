#ifndef __ULTRASONIC_h
#define __ULTRASONIC_h

#include "Arduino.h"

class Ultrasonic {
    public:     Ultrasonic(int, int);
                float getTemperature();
                void setTemperature(float);
                int distanceInMicroseconds();
                int distanceInCentimeters();
                int distanceInMillimeters();
                String toString();
    private:    int pinTrigger;
                int pinEcho;
                float temperature;
};

#endif
