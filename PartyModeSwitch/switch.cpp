#include "switch.h"

Switch::Switch(int switchPin, int lightPin)
{
    //Get the pins
    this->switchPin = switchPin;
    this->lightPin = lightPin;

    //Configure pins
    pinMode(switchPin, INPUT);
    pinMode(lightPin, OUTPUT);

    //If switch is on at startup, blink
    //Otherwise, set light off
    if(isOn()) {

    } else {
        turnOffLight();
    }
}

bool Switch::isOn()
{
    return (digitalRead(switchPin) == HIGH);
}

bool Switch::lightIsOn()
{
    return lightStatus; 
}

void Switch::turnOffLight()
{
    digitalWrite(lightPin, LOW);
    lightStatus = false;
}

void Switch::turnOnLight()
{
    digitalWrite(lightPin, HIGH);
    lightStatus = true;
}

void Switch::configInterrupt(void (* isr)(), int mode)
{
    attachInterrupt(digitalPinToInterrupt(switchPin), isr, mode);
}

void Switch::notify()
{
    //Called every ms
}

