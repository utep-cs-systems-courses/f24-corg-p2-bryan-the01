#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "libTimer.h"

static char debounce = 0;  // Debounce flag

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void) {
  if (P1IFG & BIT3) {               // Check if the interrupt is from S1 (P1.3)
    if (!debounce) {              // Only proceed if debounce flag is clear
      debounce = 1;             // Set debounce flag
      switch_interrupt_handler(); // Call the switch handler
      __delay_cycles(50000);    // Small delay for debounce (approx. 10ms at 1MHz)
      debounce = 0;             // Clear debounce flag after delay
    }
    P1IFG &= ~BIT3;               // Clear interrupt flag for S1
  }
}
