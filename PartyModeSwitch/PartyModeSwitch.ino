#include <LinkedList.h>
#include "switch.h"
#include "timer0.h"
#include "button.h"

//For the uno, only pins 2 & 3 are interruptable

#define SWITCH_1_PIN       3 
#define SWITCH_1_LIGHT_PIN 4
#define SWITCH_2_PIN       5
#define SWITCH_2_LIGHT_PIN 6
#define SWITCH_3_PIN       7
#define SWITCH_3_LIGHT_PIN 8
#define BUTTON_PIN         9
#define BUTTON_LIGHT_PIN   3

Timer0 timer0;
Switch *one;
Switch *two;
Switch *three;
Button *button;

void setup() {
    one = new Switch(SWITCH_1_PIN, SWITCH_1_LIGHT_PIN, &timer0);
    two = new Switch(SWITCH_2_PIN, SWITCH_2_LIGHT_PIN, &timer0);
    three = new Switch(SWITCH_3_PIN, SWITCH_3_LIGHT_PIN, &timer0);
    button = new Button(BUTTON_PIN, BUTTON_LIGHT_PIN, BUTTON_ISR, &timer0);
}

void loop() {
    // put your main code here, to run repeatedly:
    one->check([](bool switchedOn) {
        if(switchedOn && !two->isOn() && !three->isOn()) {
            //Do whatever happens when switch 1 comes on
            one->turnLightOn();
        } else if(switchedOn) {
            //Switched on but not in order
            one->blinkLight();
        } else {
            one->turnLightOff();
        }
    });

    two->check([](bool switchedOn) {
        if(switchedOn && one->isOn() && !three->isOn()) {
            //Do whatever happens when switch 1 comes on in order
            two->turnLightOn();
        } else if(switchedOn) {
            //Switched on but not in order
            two->blinkLight();
        } else {
            two->turnLightOff();
        }
    });

    three->check([](bool switchedOn) {
        if(switchedOn && one->isOn() && two->isOn()) {
            //Do whatever happens when switch 3 comes on in order
            three->turnLightOn();
            button->blinkLight();
        } else if(switchedOn) {
            //Switched on but not in order
            three->blinkLight();
        } else {
            three->turnLightOff();
        }
    });

    button->check([]() {
        if(one->isOn() && two->isOn() && three->isOn()) {
            //Activate party mode!
            one->blinkLight();
            two->blinkLight();
            three->blinkLight();
        }
    });
}



// Interrupt is called once a millisecond
SIGNAL(TIMER0_COMPA_vect) 
{
    timer0.handleInterrupt();
}


void BUTTON_ISR()
{
    static unsigned long prevTime = 0; //This will assign the time to 0 only one time
    unsigned long currentTime = millis();

    //Debounce - if it hasnt been 200ms, ignore
    if(!(currentTime - prevTime > 200)) {
        return;
    }

    button->wasPressed();
    prevTime = currentTime;
}

