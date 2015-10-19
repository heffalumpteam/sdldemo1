/*gcc main.c -o test -Wall -Wextra -pedantic -std=c90 -lSDL2*/
#include <stdio.h>
#include "def.h"
#include "graphics.h"
#include "events.h"


void graphics_init(void);

int main (){
  /*why use a whole int when it only needs to be 1 or 0?!
  there is a typedef in def.h defining a byte*/
  byte running = 1;

  printf("Booting\n");

  graphics_init();

  while(running){ /*program happens in this loop*/

    /*Lets check for events. But lets pass it the address of the running
        variable. This means that the events can tell us to exit the
        program*/
    events_poll(&running);
  }

  printf("Quitting\n");

  graphics_close();
  return 0;
}
