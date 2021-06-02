const int ledPin = 13;
const int buttonPin = 2;

int ledState = LOW;
int buttonState = LOW;
int prevButtonState = LOW;

unsigned long previousMillis = 0;
unsigned long currentMillis;

int intervals[] = {1000, 500, 250, 100};
const int MAX_INTERVAL_INDEX = 3;
int intervalIndex = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    currentMillis = millis();

    if (currentMillis - previousMillis >= intervals[intervalIndex]) {
        previousMillis = currentMillis;

        ledState = ~ledState;
        digitalWrite(ledPin, ledState);
    }

    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH) {
        if (prevButtonState == LOW) {
            if (intervalIndex == MAX_INTERVAL_INDEX)
                intervalIndex = 0;
            else
                intervalIndex++;

            Serial.println("Current interval: " + String(intervals[intervalIndex]));
        }
        prevButtonState = HIGH;
    }
    else {
        prevButtonState = LOW;
    }

}
