#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static char led_state = 0;

char toggle_both()		/* always toggle! */
{
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();			
}


void toggle_green(){
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
}

void toggle_red(){
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void turn_off(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void change_led()
{
  switch (led_state) {
  case (0):
    P1OUT |= LED_GREEN;
    led_state = 1;
    break;
  case (1):
    P1OUT &= ~LED_GREEN;
    led_state = 0;
    break;
  default:
    led_state = 0;
    break;
  }
}

void state_advance(n_switch)
{
 switch(n_switch){
  case 0:
    toggle_red();
    break;
  case 1:
    toggle_green();
    change_led();
    buzzer_set_period(1000);
    break;
  case 2:
     toggle_both();
     buzzer_set_period(6000);
    break;
  case 3:
    turn_off();
    buzzer_set_period(0);
    break;
 } 
}
