#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char dim = 0;

char toggle_red()		/* always toggle red */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()             /* always toggle green */
{
  static char state = 0;

  switch (state) {
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  return 1;
}

void redOn(){
  red_on = 1;

  led_changed = 1;
  led_update();
}

void redOff(){
  red_on = 0;

  led_changed = 1;
  led_update();
}

void greenOn(){
  green_on = 1;

  led_changed = 1;
  led_update();
}

void greenOff(){
  green_on = 0;

  led_changed = 1;
  led_update();
}

void redDim75() {

  static char state = 0;

  if (state == 0) {
    red_on = 1;
    state = 1;
  }
  else if (state == 1) {
    red_on = 1;
    state = 2;
  }
  else if (state == 2) {
    red_on = 1;
    state = 3;
  }
  else if (state == 3) {
    red_on = 0;
    state = 0;
  }
  
  led_changed = 1;
  led_update();
}

void redDim50() {

  static char state = 0;

  if (state == 0) {
    red_on = 1;
    state = 1;
  }
  else {
    red_on = 0;
    state = 0;
  }

  led_changed = 1;
  led_update();
 }

void redDim25() {

  static char state = 0;

  if (state == 0) {
    red_on = 1;
    state = 1;
  }
  else if (state == 1) {
    red_on = 0;
    state = 2;
  }
  else if (state == 2) {
    red_on = 0;
    state = 3;
  }
  else if (state == 3) {
    red_on = 0;
    state = 0;
  }
  
  led_changed = 1;
  led_update();
}

void stateMachine() {

  switch (dim) {

  case 0: redDim25(); break;
  case 1: redDim50(); break;
  case 2: redDim75(); break;
  case 3: redOn(); break;
  case 4: redOff(); break;
  }
}

void change_states() {

  if (dim == 0) {
    dim = 1;
  } else if (dim == 1) {
    dim = 2;
  } else if (dim == 2){
    dim = 3;
  } else if (dim == 3){
    dim = 4;
  } else if (dim == 4){
    dim = 0;
  }
}



