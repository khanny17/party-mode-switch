#ifndef SWITCH_H
#define SWITCH_H

#include "Arduino.h"
#include "observer.h"

class Switch : public Observer
{
public:
  Switch(int switchPin, int lightPin);

  //Returns true if the switch is in the on position
  bool isOn();

  //Returns true if the light is on
  bool lightIsOn();

  //Turns on the light
  void turnOnLight();

  //Turns off the light
  void turnOffLight();

  //Attaches an interrupt to the switch pin
  void configInterrupt(void (* isr)(), int mode); 

  //Called when there is an update
  void notify();

private:
  bool lightStatus;
  int switchPin, lightPin;
  
};

#endif
