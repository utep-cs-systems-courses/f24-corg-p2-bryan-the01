#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */
  return p1val;
}

void switch_init() {
  P1DIR &= ~SWITCHES;       // Set switches as inputs
  P1REN |= SWITCHES;        // Enable pull-up resistors on switches
  P1OUT |= SWITCHES;        // Set pull-up (default high when unpressed)
  P1IE |= SWITCHES;         // Enable interrupts for switches
  P1IES |= SWITCHES;        // Trigger on falling edge
  P1IFG &= ~SWITCHES;       // Clear interrupt flags
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  led_update();
}
