#include <msp430.h>
#include "stateMachines.h"

#pragma vector=WDT_VECTOR
__interrupt void WDT() {
  static char count = 0;
  if (++count == 20) {        // Adjust the count threshold to control the frequency
    state_advance();        // Call state advance function (e.g., toggle LED)
    count = 0;              // Reset count
  }
}
