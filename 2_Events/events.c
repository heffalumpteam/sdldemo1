#include <SDL2/SDL.h>
#include "def.h"

enum eventreturns {noaction, quit, click, resize};

enum eventreturns checkEvents(void);

/*This is our main events function defined in events.h
    You can tell that it's accessable from outside of events.h because
    I named it "events_something" anything with the name "file_" can
    be accessed from outside the function. - Just my way of trying to
    keep everything tidy.*/
void events_poll(byte *running){

  /*This switch checks the return on checkEvents which is an enum eventreturns*/
  switch (checkEvents()){
    case noaction:
      break;
    case quit:
      *running = 0;
      break;
    default:
      break;
    }
}

enum eventreturns checkEvents(void){
  SDL_Event event;
  enum eventreturns to_return = noaction;

   /* Example: https://wiki.libsdl.org/SDL_Event */
  if (SDL_PollEvent(&event)){
    switch (event.type){
      case SDL_QUIT:
        to_return = quit;
        break;
    }
  }

  return to_return;
}
