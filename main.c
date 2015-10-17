/*gcc main.c -o test -Wall -Wextra -pedantic -std=c90 -lSDL2*/
#include <SDL2/SDL.h>

void graphics_init(void);

int main (){
  graphics_init();
  return 0;
}

void graphics_init(void){
  SDL_Window *window = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Testing",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            800,
                            600,
                            0);
  SDL_Delay(2000);
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}
