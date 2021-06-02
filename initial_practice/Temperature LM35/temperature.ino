int ledState = LOW;

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;

int valA = LOW;
int valB = LOW;
int valC = LOW;
int valD = LOW;
int valE = LOW;
int valF = LOW;
int valG = LOW;

const int D1 = 9;
const int D2 = 10;
const int D3 = 11;
const int D4 = 12;

int digits[] = { D1, D2, D3, D4 };

const int potenSensor = A1;
const int thermSensor = A0;
int screenDelay = 5;

float temp;

unsigned long prevMillis = 0;
unsigned long currentMillis = 0;
const int fetchDelay = 1000;

void setup() {
    Serial.begin(9600);

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
}

void loop() {
    displayNum(temp);

    currentMillis = millis();
    screenDelay = getPotentiometerValue();

    if (currentMillis - prevMillis >= fetchDelay) {
        prevMillis = currentMillis;

        temp = getTemperature();
        logStats(temp);
    }
}

float getTemperature() {
    int sensorVal = analogRead(thermSensor);
    Serial.println("Temp sensor: " + String(sensorVal));
    float converted = (5.0 * sensorVal * 100.0) / 1024.0;
    return converted;
}

int getPotentiometerValue() {
    int sensor = analogRead(potenSensor);
    return convert(sensor, 1023, 1, 500);
}

int convert(int input, int maxInput, int minTarget, int maxTarget) {
    float in = float(input);
    float max = float(maxInput);
    int targetRange = maxTarget - minTarget;

    return maxTarget - int((in / max) * targetRange) + minTarget;
}


void logStats(float temp) {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" ℃");

    Serial.println("Delay: " + String(screenDelay) + "\n");
}

void displayNum(int num) {

    int tempInt = int(num);
    int current_num;

    for (int i = 0; i <= 3; i++) {

        if (i == 0)
            current_num = tempInt / 10;
        else if (i == 1)
            current_num = tempInt % 10;
        else if (i == 2)
            current_num = -1;
        else
            current_num = 0xC;

        enableDigit(digits[i]);
        updateValues(current_num);

        digitalWrite(pinA, valA);
        digitalWrite(pinB, valB);
        digitalWrite(pinC, valC);
        digitalWrite(pinD, valD);
        digitalWrite(pinE, valE);
        digitalWrite(pinF, valF);
        digitalWrite(pinG, valG);

        delay(screenDelay);
    }

}

void enableDigit(int digit) {
    for (int i = 0; i < 4; i++) {
        if (digits[i] == digit)
            digitalWrite(digits[i], LOW);
        else
            digitalWrite(digits[i], HIGH);
    }
}

void updateValues(int num) {
    clearValues();

    if (num >= 0 && num <= 0xF) {
        if (num == 0 || num == 2 || num == 3 || (num >= 5 && num <= 0xA) || num == 0xC || num >= 0xE)
            valA = HIGH;
        if (num <= 4 || (num >= 7 && num <= 0xA) || num == 0xD)
            valB = HIGH;
        if (num == 0 || num == 1 || (num >= 3 && num <= 0xB) || num == 0xD)
            valC = HIGH;
        if (num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || (num >= 0xB && num <= 0xE))
            valD = HIGH;
        if (num == 0 || num == 2 || num == 6 || num == 8 || num >= 0xA)
            valE = HIGH;
        if (num == 0 || (num >= 4 && num <= 6) || (num >= 8 && num <= 0xC )|| num >= 0xE)
            valF = HIGH;
        if ((num >= 2 && num <= 6 ) || (num >= 8 && num <= 0xB) || num >= 0xD)
            valG = HIGH;
    }
    else {
        if (num == -1)
            valB = HIGH;
    }
}

void clearValues() {
    valA = LOW;
    valB = LOW;
    valC = LOW;
    valD = LOW;
    valE = LOW;
    valF = LOW;
    valG = LOW;
}
