#include <IRremote.h>
#include "remote.h"

const int irPin = 11;
const int led = 12;
int codigo;

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
    pinMode(led, OUTPUT);
}

void loop() {
    if (IrReceiver.decode()) {
        codigo = IrReceiver.decodedIRData.command;
        Serial.println(codigo, HEX);

        if (codigo == LED_ON) {
            digitalWrite(led, HIGH);
            Serial.println("Led ON");
        }
        else if (codigo == LED_OFF) {
            digitalWrite(led, LOW);
            Serial.println("Led OFF");
        }

        delay(500);
        IrReceiver.resume();
    }
}
