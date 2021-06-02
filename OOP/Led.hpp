#ifndef LED_CLASS
#define LED_CLASS

#define DIGITAL 0
#define ANALOG 1

#include <Arduino.h>

class Led {
    private:
        uint8_t pin;
        uint8_t state;
        short level;
        int mode; // 0 = Digital, 1 = Analog s
        void writeState();

    public:
        Led(uint8_t pin);
        Led(uint8_t pin, int mode);
        void toggleState();
        void setBrightness(short newLevel);
};

#endif
