#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "alarm.h"

int main(void) {
  WDTCTL = WDTPW | WDTHOLD;
  configureClocks();
  led_init();
  switch_init();
  alarm_init();

  or_sr(0x18);

  while (1) {
    if (alarm_state == 1) {
      alarm_update();  // Update alarm system (LED and buzzer)
    }
  }
}
