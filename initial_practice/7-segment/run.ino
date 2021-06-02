const int pinA = 3;
const int pinB = 2;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 4;
const int pinG = 5;

int pins[7] = { pinA, pinB, pinC, pinD, pinE, pinF, pinG };
int values[7] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW };

int currentValue = 0;
int maxValue = 0xF;

void setup() {

    Serial.begin(9600);

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
}

void loop() {

    if (Serial) {
        Serial.println("Displaying: " + String(currentValue));
    }

    getDisplaySegments(currentValue, values);
    printValue(pins, values);

    if (currentValue < maxValue)
        currentValue++;
    else
        currentValue = 0;
    delay(1000);
}

