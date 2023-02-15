#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;

int main()
{
  Screen screen;

  if(screen.init() == false){
    cout << "error initializing SDL." << endl;
  } 

  while(true){
    int elapsed = SDL_GetTicks();
    unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
    unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

    //Update particles
    for(int y = 0; y < Screen::SCREEN_HEIGHT; y++){
      for(int x = 0; x< Screen::SCREEN_WIDTH; x++){
        screen.setPixel(x, y, red, green, blue);
      }
    }  

    //Draw particles

    screen.update(); // need to add screen update method to the screen class
    //Check for messages/events
    if (screen.processEvents() == false) {
      break;
    }
  }
  screen.close();

  return EXIT_SUCCESS;
}