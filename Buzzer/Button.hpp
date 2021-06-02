#ifndef BTN_CLASS
#define BTN_CLASS

#include <Arduino.h>

class ButtonToggle {
    private:
        uint8_t pin;
        bool wasPressedBefore;
        bool isActiveNow;
        void determineState();
    public:
        ButtonToggle(uint8_t pin);
        boolean isActive();
};

#endif
