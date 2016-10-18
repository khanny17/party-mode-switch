#include "light.h"

Light::Light(int pin, Timer0 *timer0)
{
    this->pin = pin;
    timer0->addObserver(this);
    pinMode(pin, OUTPUT);
}


LightMode Light::getLightMode()
{
    return lightMode; 
}

void Light::setLight(bool setOn)
{
    if(setOn) {
        digitalWrite(pin, HIGH);
        lightStatus = true;
    } else {
        digitalWrite(pin, LOW);
        lightStatus = false;
    }
}

void Light::turnOff()
{
    setLight(false);
    lightMode = OFF;
}

void Light::turnOn()
{
    setLight(true);
    lightMode = ON;
}

void Light::toggle()
{
    setLight(!lightStatus);
}

void Light::blink(uint8_t ms)
{
    setLight(!lightStatus);
    lightMode = BLINK;
    blinkRate = ms;
    msToToggle = blinkRate;
}

//Hopefully called every ms
void Light::notify()
{
    msToToggle--;
    if(lightMode == BLINK && msToToggle <= 0) {
        toggle();
        msToToggle = blinkRate;
    }
}

