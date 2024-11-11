#ifndef SWITCHES_H
#define SWITCHES_H

void switch_init();               
void switch_interrupt_handler();     

#define ALARM_BUTTON BIT0  // P2.0 for alarm button

#endif
