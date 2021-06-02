#include "Joystick.hpp"
#include "Button.hpp"
#include "Led.hpp"

const int pin_joystick_x = A0;
const int pin_joystick_y = A1;
const int pin_joystick_btn = 2;
const int btn_pin = 3;
const int buzzer_pin = 6;

Joystick ctrl(pin_joystick_x, pin_joystick_y, pin_joystick_btn);
ButtonToggle button(btn_pin);
Led light(7);

int x, y;
bool btn;

void setup() {
    // Serial.begin(9600);
    ctrl.setAdjustmentX(-4);
    ctrl.setAdjustmentY(-27);
    // ctrl.setInvertY(true);
}

void loop() {
    x = ctrl.getX();
    y = ctrl.getY();
    btn = button.isActive();

    light.setBrightness(short(btn));

    if (btn)
        tone(buzzer_pin, potentiometerToTone(x + y));
    else
        noTone(buzzer_pin);

    // Serial.println("X: " + String(x) + " Y: " + String(y));
}

int potentiometerToTone(int value) {
    int new_val = map(value, 0, (2 * 1023), 20, 2000);
    return new_val;
}
