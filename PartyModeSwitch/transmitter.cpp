#include "transmitter.h"

Transmitter::Transmitter(int powerPin, int dataPin, uint8_t deviceID) {
    this->powerPin = powerPin;
    this->deviceID = deviceID;

    rf.enableTransmit(dataPin);

    pinMode(powerPin, OUTPUT);
    turnOff();
}

//Send the command, preceded with the device id
// XXXXXXXX - YYYYYYYY
// DeviceID - CommandID
void Transmitter::send(uint8_t commandID) {
    turnOn();
    rf.send( (deviceID << 8) | commandID , 16);
    turnOff();
}


void Transmitter::turnOn() {
    digitalWrite(powerPin, LOW); //Low because we connect the ground pin
}

void Transmitter::turnOff() {
    digitalWrite(powerPin, HIGH);
}

