void setup() {
    int comm_bits_per_sec = 9600;
    Serial.begin(comm_bits_per_sec);
}

void loop() {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    delay(1);
}
