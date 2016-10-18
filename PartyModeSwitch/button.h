#ifndef BUTTON_H
#define BUTTON_H

#include "light.h"
#include "timer0.h"

class Button
{
public:
    Button(int inputPin, int lightPin, void (*isr)(), Timer0 *timer0);
    ~Button();

    //Called when there is an update
    void notify();

    void check(void (*callback)());

    void wasPressed();

    void blinkLight();
    void turnLightOff();

private:
    bool pressedSinceLastCheck;
    int inputPin;  
    Light *light;
};

void BUTTON_ISR();

#endif
