#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static short c_note = 523;
static short a_note = 440;
static short g_note = 784;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

char buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void makeSound() {

  static char state = 0;

  if (state == 0) {
  
  buzzer_set_period(c_note);
  state = 1;
  }
  if (state == 1) {
    
  buzzer_set_period(g_note);
  state = 2;
  }

  if (state == 2) {
  buzzer_set_period(a_note);

  state = 3;
  }
}


    
    
  

