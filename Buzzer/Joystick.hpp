#ifndef JOYSTICK_CLASS
#define JOYSTICK_CLASS

#include <Arduino.h>
#include "Potentiometer.hpp"

#define JOYSTICK_CENTER 511

class Joystick {
    private:
        Potentiometer potX;
        Potentiometer potY;
        uint8_t pinButton;

    public:
        Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinButton);
        int getX();
        int getY();
        bool isButtonPressed();
        void loadValues(int* toLoad[3]);
        void setAdjustmentX(int val);
        void setAdjustmentY(int val);
        void setInvertX(bool val);
        void setInvertY(bool val);
};

#endif
