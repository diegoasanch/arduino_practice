const int led = 9;
const int sensor = A0;
int brightness = 0;
int sensorValue = 0;

void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    analogWrite(led, brightness);
    sensorValue = analogRead(sensor);
    brightness = convert(sensorValue, 1023, 255);
    Serial.println("Sensor: " + (String) sensorValue + " LED: " + (String) brightness);

    delay(30);
}

int convert(int input, int maxInput, int target) {
    float in = float(input);
    float max = float(maxInput);

    return target - int((in / max) * target);
}
