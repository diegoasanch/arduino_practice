#include <dht.h>
#include "temp.h"

const int D1 = 2;
const int D2 = 3;
const int D3 = 4;
const int D4 = 5;

const int digits[4] = { D1, D2, D3, D4 };

const int clearPin = 6;
const int serialData = 7;
const int shiftClock = 8;
const int latchClock = 9;

const int button = 10;
const int dhtPin = 11;
const int readLed = 12;

int btnPressed;

byte screenByte;
int prevMillis = 0;
int currentMillis = 0;

int prevValue = 0;
int currentValue = 25;
byte values[4] = { 0, 0, 0, 0 };

const int fetchDelay = 1000;
int prevFetch = 1000;
float temp, humi;

boolean prevBtn = false;

struct Data sensor;
dht DHT;

int currentMode = TEMP;
int prevMode = TEMP;

void setup() {
    Serial.begin(9600);

    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);

    pinMode(clearPin, OUTPUT);
    pinMode(serialData, OUTPUT);
    pinMode(shiftClock, OUTPUT);
    pinMode(latchClock, OUTPUT);
    pinMode(readLed, OUTPUT);

    pinMode(button, INPUT);

    // Clear the shift register
    digitalWrite(clearPin, LOW);
    digitalWrite(clearPin, HIGH);
}

void loop() {

    currentMillis = millis();
    btnPressed = digitalRead(button);

    if (btnPressed && !prevBtn) {
        prevBtn = true;
        btnPressed = false;

        if (currentMode == TEMP)
            currentMode = HUMI;
        else
            currentMode = TEMP;

        Serial.print("Toggle mode");
    }
    else if (!btnPressed && prevBtn) {
        prevBtn = false;
    }
    if (currentMillis - prevFetch >= fetchDelay) {
        prevFetch = currentMillis;
        digitalWrite(readLed, HIGH);

        DHT.read11(dhtPin);
        temp = DHT.temperature;
        humi = DHT.humidity;
        sensor.temperature = (int) temp;
        sensor.humidity = (int) humi;
        currentValue = (sensor.temperature * 100) + sensor.humidity;
        digitalWrite(readLed, LOW);
    }

    if ((currentValue != prevValue) || (currentMode != prevMode)) {
        prevValue = currentValue;
        prevMode = currentMode;
        loadValues(
            currentMode == TEMP
                ? sensor.temperature
                : sensor.humidity,
            values,
            currentMode
        );
    }
    printItems();
}

void printItems() {
    for (int i = 0; i < 4; i++) {
        writeRegister(values[i]);
        digitalWrite(digits[i], LOW);
        delay(1);
        digitalWrite(digits[i], HIGH);
    }
}

void writeRegister(byte value) {
    digitalWrite(latchClock, LOW);
    shiftOut(serialData, shiftClock, LSBFIRST, value);
    digitalWrite(latchClock, HIGH);
}

void loadValues(int num, byte values[4], int mode) {
    int digit1 = num / 10;
    int digit2 = num % 10;

    values[0] = getDisplaySegments(digit1);
    values[1] = getDisplaySegments(digit2);

    if (mode == TEMP) {
        values[2] = getDisplaySegments(-2);
        values[3] = getDisplaySegments(0xC);
    }
    else {
        values[2] = getDisplaySegments(-100);
        values[3] = getDisplaySegments(-3);
    }
}
