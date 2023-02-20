#include "Screen.h"

using namespace std;

Screen::Screen (): m_window(NULL),
    m_renderer(NULL),
    m_texture(NULL),
    m_buffer(NULL)
{
}
bool Screen::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    } 

    m_window = SDL_CreateWindow("Particle Fire", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (m_window == NULL){
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC); //sync renderer with vertical refresh
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if (m_renderer == NULL){
        SDL_DestroyWindow(m_window); 
        SDL_Quit();
        return false;
    }
    if (m_texture == NULL){
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window); 
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; //allocate memory to store pixels
    // might be  m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]

    memset(m_buffer, 0, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32)); //set colour of screen

    /*for(int i = 0; i < SCREEN_HEIGHT*SCREEN_WIDTH; i++){
        m_buffer[i] = 0xFFFFFF00;
    }*/
  
    return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    
    //TODO optional line to prevent clipping so pixels are not plotted on the border (1 pixel off the edge)

    Uint32 color = 0;

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color +=  blue;
    color <<= 8;
    color += 0xFF;

    m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32)); //update the texture with the info in the buffer and tell the renderer to render and draw the texture
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer); 
}
bool Screen::processEvents()
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event)){
      if (event.type == SDL_QUIT){
        return false;
      }
    }
    return true;
}
void Screen::close()
{
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Screen::clear(){
    memset(m_buffer, 0, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32)); //clears screen
}

Screen::~Screen()
{
}