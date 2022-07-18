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
