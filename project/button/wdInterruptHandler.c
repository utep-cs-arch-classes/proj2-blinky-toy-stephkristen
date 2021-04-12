#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char state_count = 0;
  static char count = 0;
  
  if ((++blink_count == 50) && (switch_state_changed == 1)) {
    redOn();
    blink_count = 0;
  }
  else if ((++blink_count == 80) && (switch_state_changed == 2)) {
    greenOn();
    blink_count = 0;
  }
  else if ((++blink_count == 20) && (switch_state_changed == 3)) {
    redDim75();
    blink_count = 0;
  }
  else if ((++blink_count == 125) && (switch_state_changed == 4)) {
    greenOff();
    redOff();
   blink_count = 0;
 }
}
