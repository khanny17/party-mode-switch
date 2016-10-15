#ifndef SWITCH_H
#define SWITCH_H

#include "Arduino.h"
#include "observer.h"

enum LightMode
{
    ON,
    OFF,
    BLINK
};

class Switch : public Observer
{
public:
  Switch(int switchPin, int lightPin);

  //Returns true if the switch is in the on position
  bool isOn();

  //Returns mode of light
  LightMode getLightMode();

  //Turns on the light
  void turnOnLight();

  //Turns off the light
  void turnOffLight();

  //Toggles light
  void toggleLight();

  //Blinks light
  void blinkLight(uint8_t ms = 500);

  //Attaches an interrupt to the switch pin
  void configInterrupt(void (* isr)(), int mode); 

  //Called when there is an update
  void notify();

private:
  bool lightStatus;
  LightMode lightMode;
  int switchPin, lightPin, blinkRate, msToToggle;

  void setLight(bool setOn);
  
};

#endif
