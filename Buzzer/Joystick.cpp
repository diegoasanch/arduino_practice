#include "Joystick.hpp"

int centerValue(int value, int offset = 0) {
    return constrain((value - JOYSTICK_CENTER) + offset, -511, 511);
}

Joystick::Joystick(
        uint8_t pinX,
        uint8_t pinY,
        uint8_t pinButton
    )
        : potX(pinX), potY(pinY)
    {
    this->pinButton = pinButton;
    pinMode(pinButton, INPUT);
}

int Joystick::getX() {
    return potX.getValue();
}

int Joystick::getY() {
    return potY.getValue();
}

bool Joystick::isButtonPressed() {
    return  digitalRead(pinButton) == HIGH;
}

void Joystick::setAdjustmentX(int val) {
    potX.setAdjustment(val);
}
void Joystick::setAdjustmentY(int val) {
    potY.setAdjustment(val);
}

void Joystick::setInvertX(bool val) {
    potX.setInverted(val);
}

void Joystick::setInvertY(bool val) {
    potY.setInverted(val);
}

void Joystick::loadValues(int* toLoad[3]) {
    *toLoad[0] = getX();
    *toLoad[1] = getY();
    *toLoad[2] = isButtonPressed() ? 1 : 0;
}
