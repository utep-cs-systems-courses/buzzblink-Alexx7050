#include <msp430.h>
#include "led.h"
#include "libTimer.h"
#include "stateMachines.h"

  static char blink_count = 0;

  if(++blink_count == 250){
    state_advance();
    blink_count = 0;
  }
