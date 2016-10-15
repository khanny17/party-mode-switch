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
        blinkLight();
    } else {
        turnOffLight();
    }
}

bool Switch::isOn()
{
    return (digitalRead(switchPin) == HIGH);
}

LightMode Switch::getLightMode()
{
    return lightMode; 
}

void Switch::setLight(bool setOn)
{
    if(setOn) {
        digitalWrite(lightPin, HIGH);
        lightStatus = true;
    } else {
        digitalWrite(lightPin, LOW);
        lightStatus = false;
    }
}

void Switch::turnOffLight()
{
    setLight(false);
    lightMode = OFF;
}

void Switch::turnOnLight()
{
    setLight(true);
    lightMode = ON;
}

void Switch::toggleLight()
{
    setLight(!lightStatus);
}

void Switch::blinkLight(uint8_t ms)
{
    setLight(!lightStatus);
    lightMode = BLINK;
    blinkRate = ms;
    msToToggle = blinkRate;
}

void Switch::configInterrupt(void (* isr)(), int mode)
{
    attachInterrupt(digitalPinToInterrupt(switchPin), isr, mode);
}


//Hopefully called every ms
void Switch::notify()
{
    msToToggle--;
    if(lightMode == BLINK && msToToggle <= 0) {
        toggleLight();
        msToToggle = blinkRate;
    }
}

