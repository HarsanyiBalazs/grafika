#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>

/**
 * SDL2 example
 */
int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_Renderer* renderer;
  int i;

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Hello SDL!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


  int x,y;
  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {

      
      //SDL_GetMouseState(&x,&y);

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
      //SDL_RenderClear(renderer);

      
      SDL_SetRenderDrawColor(renderer, 255, 128, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(renderer, 0, 0, x, y);
      

      SDL_RenderPresent(renderer);


      switch (event.type) {
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
      case SDL_QUIT:
        need_run = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&x,&y);
        printf("%d %d\n",x,y);
        break;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
