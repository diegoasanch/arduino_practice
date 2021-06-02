#ifndef POTENTIOMETER_CLASS
#define POTENTIOMETER_CLASS

#include <Arduino.h>

class Potentiometer {
    private:
        uint8_t pin;
        bool inverted;
        int adjustment;

    public:
        Potentiometer(uint8_t pin);
        int getValue();
        void setAdjustment(int adjustment);
        void setInverted(bool inverted);
};

#endif
