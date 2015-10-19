#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Surface *image = NULL;
SDL_Texture *texture = NULL;

void graphics_init(void){
  /*get the graphics going*/
  SDL_Init(SDL_INIT_VIDEO);

  /*give us a window*/
  window = SDL_CreateWindow("Testing",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            800,
                            600,
                            SDL_WINDOW_ALLOW_HIGHDPI);
  /*setup the renderer*/
  renderer = SDL_CreateRenderer(window, -1, 0);

  /*load an image (as a surface)*/
  image = IMG_Load("ourimage.png");

  /*make a texture from the image*/
  texture = SDL_CreateTextureFromSurface(renderer, image);

  /*cleanup surface - finished with it*/
  SDL_FreeSurface(image);
  image = NULL;

  /*Clear the render (get rid of what may have been there before)*/
  SDL_RenderClear(renderer);

  /*put the texture on to the renderer*/
  SDL_RenderCopy(renderer, texture, 0, 0);

  /*put the rendereaed stuff on to the screen*/
  SDL_RenderPresent(renderer);
}

void graphics_close(void){
  /*get rid of the renderer*/
  SDL_DestroyTexture(texture);
  /*close the renderer*/
  SDL_DestroyWindow(window);
  window = NULL;
  /*quit SDL*/
  SDL_Quit();
}
