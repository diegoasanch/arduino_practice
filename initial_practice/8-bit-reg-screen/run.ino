const int clearPin = 5;
const int serialData = 6;
const int shiftClock = 7;
const int latchClock = 8;
const int button = 4;

int values[8] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };

int maxValue = 0xF;
int currentValue = 0;
int i = 0;
bool prevStopped = true;
int buttonState = LOW;

void setup() {

    Serial.begin(9600);
    pinMode(clearPin, OUTPUT);
    pinMode(serialData, OUTPUT);
    pinMode(shiftClock, OUTPUT);
    pinMode(latchClock, OUTPUT);
    pinMode(button, INPUT);

    digitalWrite(clearPin, LOW);
    digitalWrite(clearPin, HIGH);
}

void loop() {

    buttonState = digitalRead(button);

    if (buttonState == HIGH) {
        prevStopped = false;

        getDisplaySegments(i, values);

        currentValue = valuesToByte(values);
        Serial.print("Value: " + String(i) + "\nBinary: ");
        Serial.println(currentValue, BIN);

        digitalWrite(latchClock, LOW);
        shiftOut(serialData, shiftClock, LSBFIRST, currentValue);
        digitalWrite(latchClock, HIGH);

        if (i < 15)
            i++;
        else
            i = 0;

        delay(300);
    }
    else if (!prevStopped) {
        Serial.println("Paused");
        prevStopped = true;
    }
}

