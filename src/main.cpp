#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;

int main()
{
  srand(time(NULL));

  Screen screen;

  if(screen.init() == false){
    cout << "error initializing SDL." << endl;
  } 

  Swarm swarm;

  while(true){

    const Particle * const pParticles = swarm.getParticles();

    int elapsed = SDL_GetTicks();
    screen.clear();
    swarm.update();
    
    unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
    unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

    for(int i = 0; i < Swarm::NPARTICLES; i++){
      Particle particle = pParticles[i];

      int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
      int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;
      screen.setPixel(x, y, red, green, blue);

    }

    //Update particles
    /*for(int y = 0; y < Screen::SCREEN_HEIGHT; y++){
      for(int x = 0; x< Screen::SCREEN_WIDTH; x++){
        screen.setPixel(x, y, red, green, blue);
      }
    }*/
    

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