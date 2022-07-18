#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void state_advance(n_switch)
{
 switch(n_switch){
  case 0:
    toggle_red();
    buzzer_set_period(0);
    break;
  case 1:
    toggle_green();
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
