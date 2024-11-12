#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

void main(void) {
  configureClocks();       // Set up system clocks
  switch_init();           // Initialize button S1 (SW1)
  led_init();              // Initialize LEDs

  P1OUT |= BIT0;           // Turn on the LED as a test

  or_sr(0x18);             // CPU off, GIE (General Interrupt Enable)
}
