#include "Potentiometer.hpp"

Potentiometer::Potentiometer(uint8_t pin) {
    this->pin = pin;
    setInverted(false);
    setAdjustment(0);
}

int Potentiometer::getValue() {
    int result = analogRead(pin) + adjustment;
    if (inverted)
        return map(result, 0, 1023, 1023, 0);
    return result;
}

void Potentiometer::setAdjustment(int adjustment) {
    this->adjustment = adjustment;
}

void Potentiometer::setInverted(bool inverted) {
    this->inverted = inverted;
}
