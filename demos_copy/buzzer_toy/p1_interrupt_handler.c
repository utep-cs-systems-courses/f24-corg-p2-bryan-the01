#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "libTimer.h"

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void) {
  if (P1IFG & SW1) {               // Check if SW1 (P1.3) triggered the interrupt
    P1IFG &= ~SW1;               // Clear the interrupt flag for SW1
    switch_interrupt_handler();   // Call the switch handler
  }
}
