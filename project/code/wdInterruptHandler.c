#include <msp430.h>
#include "led.h"
#include "libTimer.h"
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) {
    blink_count = 0;
    P1OUT ^= LED_GREEN;		/* toggle green LED */
    P1OUT ^= LED_RED;		/* toggle green LED */
  }
}
