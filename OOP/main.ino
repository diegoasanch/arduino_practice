#include <Arduino.h>

#include "Potentiometer.hpp"
#include "Led.hpp"

const int potentiometerPin = A0;
const int ledPin = 10;

Potentiometer knob(potentiometerPin);
Led redLed(ledPin, ANALOG);

void setup() {
    // Serial.begin(9600);
}

void loop() {
    redLed.setBrightness(knob.getReadingLed());
    // delay(10);
}
