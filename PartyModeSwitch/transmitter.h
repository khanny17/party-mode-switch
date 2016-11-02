#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "RCSwitch.h"

//TODO define command ids somewhere??

class Transmitter
{
  public:
    Transmitter(int powerPin, int dataPin, uint8_t deviceID);
    void send(uint8_t commandID);

  private:
    int powerPin;
    uint8_t deviceID;
    RCSwitch rf;

    void turnOff();
    void turnOn();
};

#endif

