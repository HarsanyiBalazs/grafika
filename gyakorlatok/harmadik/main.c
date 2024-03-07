#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>

typedef struct Line{
    int startx;
    int starty;
    int endx;
    int endy;
    int re;
    int gre;
    int blu;
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

  int max=5;
  int i,j;
  i=0;
  j=0;
  int x,y;
  line lines[max];
  
  for(int k=0;k<max;k++)
  {
    lines[k].re=255;
    lines[k].gre=255;
    lines[k].blu=255;
  }

  SDL_Rect rectToDraw1 = {0,0,150,100};
  SDL_Rect rectToDraw2 = {0,100,150,100};
  SDL_Rect rectToDraw3 = {0,200,150,100};
  SDL_Rect rectToDraw4 = {0,300,150,100};

  int paletta[4][3]={{255,255,255},{255,0,0},{0,255,0},{0,0,255}};
  int c;

  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {

      
      //SDL_GetMouseState(&x,&y);

      //SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
      

      
      SDL_SetRenderDrawColor(renderer, paletta[0][0], paletta[0][1], paletta[0][2], SDL_ALPHA_OPAQUE);
      SDL_RenderDrawRect(renderer, &rectToDraw1);
      SDL_RenderFillRects(renderer,&rectToDraw1,1);

      SDL_SetRenderDrawColor(renderer, paletta[1][0], paletta[1][1], paletta[1][2], SDL_ALPHA_OPAQUE);
      SDL_RenderDrawRect(renderer, &rectToDraw2);
      SDL_RenderFillRects(renderer,&rectToDraw2,1);

      SDL_SetRenderDrawColor(renderer, paletta[2][0], paletta[2][1], paletta[2][2], SDL_ALPHA_OPAQUE);
      SDL_RenderDrawRect(renderer, &rectToDraw3);
      SDL_RenderFillRects(renderer,&rectToDraw3,1);

      SDL_SetRenderDrawColor(renderer, paletta[3][0], paletta[3][1], paletta[3][2], SDL_ALPHA_OPAQUE);
      SDL_RenderDrawRect(renderer, &rectToDraw4);
      SDL_RenderFillRects(renderer,&rectToDraw4,1);
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
        SDL_GetMouseState(&x,&y);
        c=(int)(y/100);
        if(x<150 && c>=0 && c<4 && i<max)
        {
          for(int l=0 ;l<max;l++)
          {
            lines[l].re=paletta[c][0];
            lines[l].gre=paletta[c][1];
            lines[l].blu=paletta[c][2];
          }
        }else{
        if(i<max)
        {
          if(j % 2 ==0)
          {
            lines[i].startx=x;
            lines[i].starty=y;
            printf("%d %d\n",lines[i].startx,lines[i].starty);
            j++;
          }else if(j % 2 ==1)
          {
            lines[i].endx=x;
            lines[i].endy=y;
            printf("%d %d\n",lines[i].endx,lines[i].endy);
            SDL_SetRenderDrawColor(renderer, lines[i].re, lines[i].gre, lines[i].blu, SDL_ALPHA_OPAQUE);
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
