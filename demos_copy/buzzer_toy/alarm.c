#include <msp430.h>
#include "alarm.h"
#include "buzzer.h"
#include "led.h"

int alarm_state = 0;

#define ALARM_DELAY 1000
#define BUZZER_LOW 2000
#define BUZZER_HIGH 1000

void alarm_init() {
  buzzer_init(); 
  led_init();     
}

void alarm_update() {
  static int led_brightness = 0;
  static int buzzer_state = 0;
  alarm_toggle_led(&led_brightness);
  alarm_toggle_buzzer(&buzzer_state);
  __delay_cycles(ALARM_DELAY);
}

void alarm_toggle_led(int *brightness) {
  if (*brightness == 0) {
    red_led_bright();
    *brightness = 1;
  } else {
    red_led_dim();
    *brightness = 0;
  }
}

void alarm_toggle_buzzer(int *buzzer_state) {
  if (*buzzer_state == 0) {
    buzzer_set_period(BUZZER_HIGH);
    *buzzer_state = 1;
  } else {
    buzzer_set_period(BUZZER_LOW);
    *buzzer_state = 0;
  }
}
