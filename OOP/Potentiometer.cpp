#include "Potentiometer.hpp"

Potentiometer::Potentiometer(int pin) {
    this -> pin = pin;
}

int Potentiometer::getReading() {
    int reading = analogRead(pin);
    return reading;
}

int Potentiometer::getReadingLed() {
    int reading = getReading();
    return map(reading, 0, 1023, 0, 255);
}
