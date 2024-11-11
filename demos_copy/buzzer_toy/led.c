#include <msp430.h>
#include "led.h"

void led_init() {
  P1DIR |= BIT0;  // Red LED (P1.0)
  P1DIR |= BIT6;  // Green LED (P1.6)

  P1OUT &= ~BIT0; // Red LED off
  P1OUT &= ~BIT6; // Green LED off
}

void toggle_red_led(){
  P1OUT ^= BIT0;
}
void toggle_green_led() {
  P1OUT ^= BIT6;
}
void red_led_bright() {
  P1OUT |= BIT0;
}
void red_led_dim() {
  P1OUT &= ~BIT0;
}
void green_led_bright() {
  P1OUT |= BIT6;
}
void green_led_dim() {
  P1OUT &= ~BIT6;
}
