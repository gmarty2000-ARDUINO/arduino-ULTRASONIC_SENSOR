#ifndef __ULTRASONIC_SENSOR_h
#define __ULTRASONIC_SENSOR_h

#include "Arduino.h"

class UltrasonicSensor {
    public:     UltrasonicSensor(int, int);
                float getTemperature();
                void setTemperature(float);
                int distanceInMicroseconds();
                int distanceInCentimeters();
                int distanceInMillimeters();
                void calibration(int);
                String toString();
    private:    int pinTrigger;
                int pinEcho;
                float temperature;
};

#endif
