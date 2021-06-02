const int clearPin = 5;
const int serialData = 6;
const int shiftClock = 7;
const int latchClock = 8;
const int photoPin = A0;

const int ledR = 9;
const int ledG = 10;
const int ledB = 11;

int values[8] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };

const int maxValue = 0xF;
int currentValue = 0;
int lightLevel = 0;

void setup() {

    Serial.begin(9600);
    pinMode(clearPin, OUTPUT);
    pinMode(serialData, OUTPUT);
    pinMode(shiftClock, OUTPUT);
    pinMode(latchClock, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);

    digitalWrite(clearPin, LOW);
    digitalWrite(clearPin, HIGH);
}

void loop() {

    lightLevel = getLightLevel();
    getDisplaySegments(lightLevel, values);

    currentValue = valuesToByte(values);

    digitalWrite(latchClock, LOW);
    shiftOut(serialData, shiftClock, LSBFIRST, currentValue);
    digitalWrite(latchClock, HIGH);

    int ledVal = map(lightLevel, 0, maxValue, 255, 0);

    Serial.println("Current val: " + String(lightLevel));

    analogWrite(ledR, ledVal);
    analogWrite(ledG, ledVal);
    analogWrite(ledB, ledVal);

    Serial.println("RGB val: " + String(ledVal) +"\n");

    delay(100);
}

int getLightLevel() {
    int sensorInput = analogRead(photoPin);
    int converted = map(sensorInput, 0, 1023, 0, maxValue);
    Serial.println("Sensor: " + String(sensorInput) + " - Mapped: " + String(converted));
    return converted;
}
