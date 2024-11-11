#ifndef ALARM_H
#define ALARM_H

void alarm_init();
void alarm_update();
void alarm_toggle_led();
void alarm_toggle_buzzer();

extern int alarm_state; 

#endif
