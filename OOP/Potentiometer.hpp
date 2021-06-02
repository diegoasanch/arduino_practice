#ifndef POTENTIOMETER_CLASS
#define POTENTIOMETER_CLASS

#include <Arduino.h>

class Potentiometer {
    private:
        int pin;
    public:
        Potentiometer(int pin);
        int getReading();
        int getReadingLed(); // Maps value to 0 - 255
};

#endif
