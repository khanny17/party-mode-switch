#ifndef TIMER0_H
#define TIMER0_H

#include "Arduino.h"
#include "LinkedList.h"
#include "observer.h"

class Timer0
{
public:
    Timer0();
    void addObserver(Observer *observer);
    void handleInterrupt();

private:
    LinkedList<Observer *> observers;
    
};

#endif
