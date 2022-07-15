#include <msp430.h>
#include "led.h"
#include "libTimer.h"
#include "stateMachines.h"

static char second_count = 0;
static char led_state = 0; 

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  if (second_count >=250 )
  {
    second_count = 0;
    change_led();
  }
  second_count++;
}

void change_led()
{
  switch(led_state){
  case(0):
    P1OUT |= LED_GREEN;   //turn on
    led_state = 1;
    break;
  case(1):
    P1OUT &= ~LED_GREEN;  //turn off
    led_state = 0;
    break;
  }
}
