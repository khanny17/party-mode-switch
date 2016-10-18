#ifndef LIGHTABLE_H
#define LIGHTABLE_H

#include "Arduino.h"
#include "observer.h"
#include "timer0.h"

enum LightMode
{
    ON,
    OFF,
    BLINK
};

class Light : public Observer
{
public:
    Light(int pin, Timer0 *timer0);

    //Returns mode of light
    LightMode getLightMode();
  
    //Turns on the light
    void turnOn();
  
    //Turns off the light
    void turnOff();
  
    //Toggles light
    void toggle();

    //Blinks light
    void blink(uint8_t ms = 500);

    //Called when there is an update
    void notify();

private:
    int pin, blinkRate, msToToggle;
    bool lightStatus;
    LightMode lightMode;

    void setLight(bool setOn);
    
};

#endif
