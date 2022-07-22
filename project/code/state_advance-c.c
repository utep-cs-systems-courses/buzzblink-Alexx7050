#include <msp430.h>
#include "stateMachines.h"
#include "state_advance.h"

void state_advance(n_switch)
{
 switch(n_switch){
  case 1:
    toggle_red();
    break;
  case 2:
    toggle_green();
    break;
  case 3:
     toggle_both();
    break;
  case 4:
    turn_off();
    break;
 } 
}
