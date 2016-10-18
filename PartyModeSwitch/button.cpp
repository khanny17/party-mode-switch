#include "button.h"

Button::Button(int inputPin, int lightPin, void (*isr)(), Timer0 *timer0)
{
    this->inputPin = inputPin;
    this->light = new Light(lightPin, timer0);
    this->pressedSinceLastCheck = false;

    //Configure pins
    pinMode(inputPin, INPUT_PULLUP);

    //Configure interrupt
    attachInterrupt(digitalPinToInterrupt(inputPin), isr, RISING);

    light->turnOff();
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

void Button::turnLightOff()
{
    light->turnOff();
}

void Button::check(void (*callback)()) {
    if(pressedSinceLastCheck) {
        pressedSinceLastCheck = false;
        callback();
    }
}

