#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "alarm.h"

char switch_state_down, switch_state_changed;

void switch_init() {
  P2REN |= ALARM_BUTTON;
  P2IE |= ALARM_BUTTON;  
  P2OUT |= ALARM_BUTTON;
  P2DIR &= ~ALARM_BUTTON; 
  alarm_init();
}

void switch_interrupt_handler() {
  char p2val = P2IN;
  switch_state_down = (p2val & ALARM_BUTTON) ? 0 : 1;
  if (switch_state_down) {
    if (alarm_state == 0) {
      alarm_state = 1;
      alarm_init();    
    } else {
      alarm_state = 0;
      red_led_off();   
      buzzer_set_period(0);
    }
  }
  led_update();
}
