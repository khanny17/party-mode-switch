#include "switch.h"

Switch::Switch(int switchPin, int lightPin, Timer0 *timer0)
{
    //Get the pins
    this->switchPin = switchPin;
    this->light = new Light(lightPin, timer0);
    lastStatus = false;

    //Configure pins
    pinMode(switchPin, INPUT_PULLUP);

    //If switch is on at startup, blink
    //Otherwise, set light off
    if(isOn()) {
        light->blink();
    } else {
        light->turnOff();
    }
}

Switch::~Switch()
{
    delete light;
}

bool Switch::isOn()
{
    return (digitalRead(switchPin) == LOW);
}

void Switch::turnLightOn()
{
    light->turnOn();
}

void Switch::turnLightOff()
{
    light->turnOff();
}

void Switch::blinkLight()
{
    light->blink();
}

void Switch::configInterrupt(void (* isr)(), int mode)
{
    attachInterrupt(digitalPinToInterrupt(switchPin), isr, mode);
}

void Switch::check(void (*callback)(bool)) {
    bool newStatus = isOn();

    if(newStatus != lastStatus) {
        callback(newStatus);
    }
    
    lastStatus = newStatus;
}



