#include "Joystick.hpp"

int centerValue(int value, int offset = 0) {
    return constrain((value - JOYSTICK_CENTER) + offset, -511, 511);
}

Joystick::Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinButton, bool centered) {
    this->pinX = pinX;
    this->pinY = pinY;
    this->pinButton = pinButton;
    this->adjustmentX = 0;
    this->adjustmentY = 0;
    this->isCentered = centered;
    this->invertX = false;
    this->invertY = false;

    pinMode(pinButton, INPUT);
}

int Joystick::getX() {
    int reading = analogRead(pinX);
    int result = isCentered ? centerValue(reading, adjustmentX) : reading;
    return invertX ? (1023 - result) : result;
}

int Joystick::getY() {
    int reading = analogRead(pinY);
    int result = isCentered ? centerValue(reading, adjustmentY) : reading;
    return invertY ? (1023 - result) : result;
}

bool Joystick::isButtonPressed() {
    return  digitalRead(pinButton) == HIGH;
}

void Joystick::setAdjustmentX(int val) {
    this->adjustmentX = val;
}
void Joystick::setAdjustmentY(int val) {
    this->adjustmentY = val;
}

void Joystick::setInvertX(bool val) {
    this->invertX = val;
}

void Joystick::setInvertY(bool val) {
    this->invertY = val;
}


void Joystick::loadValues(int* toLoad[3]) {
    *toLoad[0] = getX();
    *toLoad[1] = getY();
    *toLoad[2] = isButtonPressed() ? 1 : 0;
}
