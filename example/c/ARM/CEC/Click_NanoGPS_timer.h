/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_NanoGPS_types.h"

uint32_t timerCounter = 0;

static void nanogps_configTimer()
{


    // Configure Timer
}

void Timer_interrupt()
{
    nanogps_tick();
	timerCounter++;
    // Reset Flag
}