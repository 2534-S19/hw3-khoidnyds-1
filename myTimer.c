/*
 * myTimer.c
 *
 *  Created on: Feb 28, 2020
 *      Author: Khoi Dang
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"

// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count.
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
//TIMER0 is for LED2, TIMER1 is for BLED
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{
    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule(TIMER0,TIMER0_PRESCALER,TIMER32_32BIT,TIMER32_PERIODIC_MODE);
    Timer32_initModule(TIMER1,TIMER1_PRESCALER,TIMER32_32BIT,TIMER32_FREE_RUN_MODE);

    // For the specified timer, pass the count value.
    Timer32_setCount(TIMER0,TIMER0_COUNT);
    Timer32_setCount(TIMER1,TIMER1_COUNT);

    // For the specified timer, configure the timer to repeat once it elapses.
    Timer32_startTimer(TIMER0, REPEAT);
    Timer32_startTimer(TIMER1, ONESHOT);

}

// TODO: Write a function that indicates whether Timer0 has expired.
// You have been given a such a function in the lecture slides.
bool timer0Expired(void)
{
    static unsigned int previous = MAX_VALUE;
    unsigned int current;
    bool expired;

    current = Timer32_getValue(TIMER0);
    expired = (current > previous);
    previous = current;
    return expired;

}

// TODO: Write a function that indicates whether Timer1 has expired.
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired(void)
{
    static unsigned int previous = MAX_VALUE;
    unsigned int current;
    bool expired;

    current = Timer32_getValue(TIMER1);
    expired = (current > previous);
    previous = current;
    return expired;
}
