#include "Button.hpp"

ButtonToggle::ButtonToggle(uint8_t pin) {
    this->pin = pin;
    this->wasPressedBefore = false;
    this->isActiveNow = false;

    pinMode(pin, INPUT);
}

boolean ButtonToggle::isActive() {
    determineState();
    return isActiveNow;
}

void ButtonToggle::determineState() {
    int reading = digitalRead(pin);

    if (reading && !wasPressedBefore)
        isActiveNow = !isActiveNow;

    wasPressedBefore = reading;
}
