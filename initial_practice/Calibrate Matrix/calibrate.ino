const int row[8] = {
    6, 3, 8, 2, 10, 9, A3, 13
};
const int col[8] = {
    A5, A4, 11, 7, 12, 5, 4, A2
};

int pixels[8][8];

int x;
int y;
int iterationDelay = 100;

void setup() {
    Serial.begin(9600);
    for (int thisPin = 0; thisPin < 8; thisPin++) {
        pinMode(col[thisPin], OUTPUT);
        pinMode(row[thisPin], OUTPUT);

        digitalWrite(col[thisPin], HIGH);
    }

    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            pixels[x][y] = HIGH;
        }
    }
}

void loop() {
    calibrateMatrix();
}

void calibrateMatrix() {
    for (int x = 0; x < 8; x++) {
        digitalWrite(row[x], HIGH);
        // Serial.print("Row: " + String(x) + "  ");

        for (int y = 0; y < 8; y++) {
            // Serial.print(String(y));

            digitalWrite(col[y], LOW);

            readSensors();

            if (iterationDelay > 0)
                delay(iterationDelay);

            digitalWrite(col[y], HIGH);
        }
        digitalWrite(row[x], LOW);
        // Serial.print("\n");
    }
    // Serial.print("\n\n\n");
}

void readSensors() {
    iterationDelay = map(analogRead(A0), 0, 1023, 0, 25);
    // Serial.println("Delay: " + String(iterationDelay));
}
