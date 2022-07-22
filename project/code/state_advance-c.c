#include <msp430.h>
#include "stateMachines.h"
#include "state_advance.h"

void state_advance(n_switch)
{
 switch(n_switch){
  case 0:
    toggle_red();
    break;
  case 1:
    toggle_green();
    break;
  case 2:
     toggle_both();
    break;
  case 3:
    turn_off();
    break;
 } 
}
