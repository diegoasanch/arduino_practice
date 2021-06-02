const int row[8] = {
    6, 3, 8, 2, 10, 9, A3, 13
};
const int col[8] = {
    A5, A4, 11, 7, 12, 5, 4, A2
};


// int* frames[2] = { &face, &blink };
int currentFrame = 0;

const int frameDuration = 1000;
int currentMillis = 0;
int prevMillis = 0;

void setup() {
    Serial.begin(9600);
    for (int thisPin = 0; thisPin < 8; thisPin++) {
        pinMode(col[thisPin], OUTPUT);
        pinMode(row[thisPin], OUTPUT);

        digitalWrite(col[thisPin], HIGH);
    }

    // for (int x = 0; x < 8; x++) {
    //     for (int y = 0; y < 8; y++) {
    //         frames[currentFrame][x][y] = HIGH;
    //     }
    // }
}

void loop() {
    fetchFrame();
    refreshScreen();
}

void fetchFrame() {
    currentMillis = millis();

    if (currentMillis - prevMillis >= frameDuration) {
        currentFrame = currentFrame < (totalFrames - 1) ? currentFrame + 1 : 0;
        prevMillis = currentMillis;
        Serial.println("Current frame: " + String(currentFrame));
    }
}

void refreshScreen() {
    for (int thisRow = 0; thisRow < 8; thisRow++) {
        digitalWrite(row[thisRow], HIGH);

        for (int thisCol = 0; thisCol < 8; thisCol++) {
            int thisPixel = !frames[currentFrame][thisRow][thisCol];

            digitalWrite(col[thisCol], thisPixel);

            if (thisPixel == 0)
                digitalWrite(col[thisCol], HIGH);
        }
        digitalWrite(row[thisRow], LOW);
    }
}
