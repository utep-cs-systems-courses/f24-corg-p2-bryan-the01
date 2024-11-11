#ifndef LED_H
#define LED_H

void led_init();
void toggle_red_led();
void toggle_green_led();
void red_led_bright();
void red_led_dim();
void green_led_bright();
void green_led_dim();

#define LED_DIM  0
#define LED_BRIGHT 1

#endif
