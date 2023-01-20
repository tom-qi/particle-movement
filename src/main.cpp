#include <iostream>
#include <SDL2/SDL.h>

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

  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}