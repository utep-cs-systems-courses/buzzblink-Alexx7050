#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

// char toggle_red()		/* always toggle! */
// {
//   static char state = 0;

//   switch (state) {
//   case 0:
//     red_on = 1;
//     state = 1;
//     break;
//   case 1:
//     red_on = 0;
//     state = 0;
//     break;
//   }
//   return 1;			/* always changes an led */
// }

// char toggle_green()	/* only toggle green if red is on!  */
// {
//   char changed = 0;
//   if (red_on) {
//     green_on ^= 1;
//     led_changed = 1;
//   }
//   return changed;
// }

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

void state_advance(n_switch)
{
 
 char n_switch;
 switch(n_switch){
  case 0:
    toggle_red();
    break;
  case 1:
    toggle_green();
    break;
  case 2:
     toggle_red();
     toggle_green();
     buzzer_set_period(6000);
    break;
  case 3:
    turn_off();
    buzzer_set_period(0);
    break;
 } 
}
