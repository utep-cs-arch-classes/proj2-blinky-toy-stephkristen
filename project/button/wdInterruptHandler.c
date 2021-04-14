#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char state_count = 0;

  if(++blink_count == 10) {
    if (switch_state_changed == 0) {
      redOff();
      greenOff();
      buzzer_set_period(0);
      blink_count = 0;
    }
  }

  else if (blink_count == 1) {
    if (switch_state_changed == 1) {
      stateMachine();
      blink_count = 0;

      if (++state_count == 250) {
	change_states();
	state_count = 0;
      }
    }
  }

  else if (blink_count == 125) {
    if (switch_state_changed == 2) {
      redOn();
      greenOn();
      blink_count = 0;
    }
  }

  else if (blink_count == 200) {
    if( switch_state_changed == 3) {
      redOff();
      greenOff();
      buzzer_set_period(500);
      blink_count = 0;
    }
  }
}
