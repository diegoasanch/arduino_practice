const int x = 2;
const int y = 3;


void setup() {
    pinMode(x, OUTPUT);
    pinMode(y, OUTPUT);
}

void loop() {
    digitalWrite(x, HIGH);
    digitalWrite(y, LOW);

}
