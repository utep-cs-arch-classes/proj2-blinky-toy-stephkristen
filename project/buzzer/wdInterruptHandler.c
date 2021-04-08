#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char sound_count = 0;
  //static char count = 0;
  
  if (++sound_count == 125) {
    makeSound();
    sound_count = 0;
  }
}
