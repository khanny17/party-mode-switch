#include "timer0.h"

Timer0::Timer0()
{
    // Timer0 is already used for millis() - we'll just interrupt somewhere
    // in the middle and call the "Compare A" function below
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
}

void Timer0::addObserver(Observer *observer)
{
    observers.add(observer);
}


void Timer0::handleInterrupt()
{
    for(int i = 0; i < observers.size(); ++i){
        observers.get(i)->notify();
    }
}

