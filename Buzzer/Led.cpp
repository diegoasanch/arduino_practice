#include "Led.hpp"

Led::Led(uint8_t pin, int mode) {
    this->pin = pin;
    this->state = LOW;
    this->mode = mode;
    this->level = 0;

    pinMode(pin, OUTPUT);
    writeState();
}

Led::Led(uint8_t pin) : Led(pin, DIGITAL){}; // Default mode is digital

void Led::toggleState() {
    state = !state;
    writeState();
}

void Led::writeState() {
    if (mode == DIGITAL)
        digitalWrite(pin, state);
    else
        analogWrite(pin, level);
}

void Led::setBrightness(short newLevel) {
    if (mode == DIGITAL)
        this->state = newLevel != 0 ? HIGH : LOW;
    else
        this->level = newLevel;
    writeState();
}
