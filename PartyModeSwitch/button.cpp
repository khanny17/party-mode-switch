#include "button.h"

Button::Button(int inputPin, int lightPin, void (*isr)(), Timer0 *timer0)
{
    this->inputPin = inputPin;
    this->light = new Light(lightPin, timer0);
    this->pressedSinceLastCheck = false;

    //Configure interrupt
    attachInterrupt(digitalPinToInterrupt(inputPin), isr, RISING);
}

Button::~Button()
{
    delete light;
}

void Button::wasPressed() {
    pressedSinceLastCheck = true;
}


void Button::blinkLight()
{
    light->blink();
}

void Button::check(void (*callback)()) {
    if(pressedSinceLastCheck) {
        pressedSinceLastCheck = false;
        callback();
    }
}

