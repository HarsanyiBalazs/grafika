#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>

typedef struct Line{
    int startx;
    int starty;
    int endx;
    int endy;
} line;

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

  int max=3;
  int i,j;
  i=0;
  j=0;
  int x,y;
  line lines[max];

  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {

      
      //SDL_GetMouseState(&x,&y);

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
      //SDL_RenderClear(renderer);

      
      SDL_SetRenderDrawColor(renderer, 255, 128, 0, SDL_ALPHA_OPAQUE);
      //SDL_RenderDrawLine(renderer, 0, 0, x, y);
      

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
        if(i<max)
        {
          if(j % 2 ==0)
          {
            SDL_GetMouseState(&lines[i].startx,&lines[i].starty);
            printf("%d %d\n",lines[i].startx,lines[i].starty);
            j++;
          }else if(j % 2 ==1)
          {
            SDL_GetMouseState(&lines[i].endx,&lines[i].endy);
            printf("%d %d\n",lines[i].endx,lines[i].endy);
            SDL_RenderDrawLine(renderer, lines[i].startx , lines[i].starty, lines[i].endx,lines[i].endy);
            j++;
            i++;
          }
        }
        else
        {
          i=0;
          j=0;
          SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
          SDL_RenderClear(renderer);
        }
        break;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
