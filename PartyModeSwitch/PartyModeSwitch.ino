#include <LinkedList.h>
#include "switch.h"
#include "timer0.h"

#define SWITCH_1_PIN 2 
#define SWITCH_1_LIGHT_PIN 3
#define SWITCH_2_PIN 4
#define SWITCH_2_LIGHT_PIN 5
#define SWITCH_3_PIN 6 
#define SWITCH_3_LIGHT_PIN 7
#define BUTTON_PIN   8

Timer0 timer0;
Switch *one;
Switch *two;
Switch *three;

void setup() {
    one = new Switch(SWITCH_1_PIN, SWITCH_1_LIGHT_PIN);
    two = new Switch(SWITCH_2_PIN, SWITCH_2_LIGHT_PIN);
    three = new Switch(SWITCH_3_PIN, SWITCH_3_LIGHT_PIN);

    timer0.addObserver(one);
    timer0.addObserver(two);
    timer0.addObserver(three);

    //Set switch one to wake up the arduino
    one->configInterrupt(SWITCH_ONE_ISR, RISING);
}

void loop() {
    // put your main code here, to run repeatedly:

}

void SWITCH_ONE_ISR(){
    
}


// Interrupt is called once a millisecond, 
SIGNAL(TIMER0_COMPA_vect) 
{
    timer0.handleInterrupt();
}

