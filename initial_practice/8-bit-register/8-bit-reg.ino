const int clearPin = 5;
const int serialData = 6;
const int shiftClock = 7;
const int latchClock = 8;

void setup() {

    Serial.begin(9600);
    pinMode(clearPin, OUTPUT);
    pinMode(serialData, OUTPUT);
    pinMode(shiftClock, OUTPUT);
    pinMode(latchClock, OUTPUT);

    digitalWrite(clearPin, LOW);
    digitalWrite(clearPin, HIGH);
}

void loop() {
    for (int shiftCount = 0; shiftCount < 256; shiftCount++) {

        digitalWrite(latchClock, LOW);
        // shiftOut(serialData, shiftClock, MSBFIRST, 255);
        shiftOut(serialData, shiftClock, LSBFIRST, shiftCount);
        digitalWrite(latchClock, HIGH);

        Serial.println("Displaying " + String(shiftCount));
        delay(100);
    }
}
