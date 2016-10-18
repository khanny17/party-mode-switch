#ifndef SWITCH_H
#define SWITCH_H

#include "Arduino.h"
#include "light.h"
#include "timer0.h"

class Switch
{
public:
  Switch(int switchPin, int lightPin, Timer0 *timer0);
  ~Switch();

  //Returns true if the switch is in the on position
  bool isOn();

  void turnLightOn();
  void turnLightOff();
  void blinkLight();

  //Notifies if it has changed since last time
  void check(void (*callback)(bool));

  //Attaches an interrupt to the switch pin
  void configInterrupt(void (* isr)(), int mode); 

private:
  bool lastStatus;
  int switchPin;
  Light *light;
  
};

#endif
