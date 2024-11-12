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
  P1DIR &= ~BIT3;          // Set P1.3 as input
  P1REN |= BIT3;           // Enable pull-up/down resistor on P1.3
  P1OUT |= BIT3;           // Configure as pull-up
  P1IE |= BIT3;            // Enable interrupt on P1.3
  P1IES |= BIT3;           // Set as falling edge interrupt
  P1IFG &= ~BIT3;          // Clear interrupt flag for P1.3
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  led_update();
}
