#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main()
{

  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;
  if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
  {
    std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Particle Fire", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  
  if (window == NULL){
    SDL_Quit();
    return 2;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); //sync renderer with vertical refresh
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
  
  if (renderer == NULL){
    cout << "could not create renderer" << endl;
    SDL_DestroyWindow(window); 
    SDL_Quit();
    return 3;
  }
  if (texture == NULL){
    cout << "could not create texture" << endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); 
    SDL_Quit();
    return 4;
  }

  Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; //allocate memory to store pixels
  // might be  m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]

  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32)); //update the texture with the info in the buffer and tell the renderer to render and draw the texture
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer); 
  
  bool quit = false;

  SDL_Event event;

  while(!quit){
    //update particles
    //Draw particles
    //Check for messages/events

    while(SDL_PollEvent(&event)){
      if (event.type == SDL_QUIT){
        quit = true;
      }
    }
  }

  delete [] buffer;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}