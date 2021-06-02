#define CENTER 511

// const int joystick_btn = 2;
const int pin_r = 9;
const int pin_g = 10;
const int pin_b = 11;

const int left_pot = A0;
const int pos_x = A1;
const int pos_y = A2;

int ledR = 256;
int ledG = 256;
int ledB = 256;

// int btnState = LOW;
// int ledState = LOW;
// int prevBtnState = LOW;

void setup() {
    // Serial.begin(9600);

    // pinMode(joystick_btn, INPUT);
    pinMode(pin_r, OUTPUT);
    pinMode(pin_g, OUTPUT);
    pinMode(pin_b, OUTPUT);
}

void loop() {

    getValues();
    writeValues();

    delay(1);
}

void getValues() {
    int val_r = analogRead(left_pot);
    int val_g = analogRead(pos_y);
    int val_b = analogRead(pos_x);

    // Serial.println("\nR: " + val_r);
    // Serial.println("G: " + val_g);
    // Serial.println("B: " + val_b);

    ledR = map(val_r, 0, 1023, 255, 0);
    ledG = map(val_g, 0, 1023, 255, 0);
    ledB = map(val_b, 0, 1023, 0, 255);
}

void writeValues() {
    analogWrite(pin_r, ledR);
    analogWrite(pin_g, ledG);
    analogWrite(pin_b, ledB);
}

// void toggleLed() {
//     if (ledState == HIGH) {
//         ledState = LOW;
//         analogWrite(pin_r, 0);
//         analogWrite(pin_g, 0);
//         analogWrite(pin_b, 0);
//     }
//     else {
//         ledState = HIGH;
//     }
// }
