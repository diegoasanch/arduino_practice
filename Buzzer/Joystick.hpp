#ifndef JOYSTICK_CLASS
#define JOYSTICK_CLASS

#include <Arduino.h>

#define JOYSTICK_CENTER 511

class Joystick {
    private:
        uint8_t pinX;
        uint8_t pinY;
        uint8_t pinButton;
        int adjustmentX;
        int adjustmentY;
        bool isCentered;
        bool invertX;
        bool invertY;

    public:
        Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinButton, bool centered);
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
