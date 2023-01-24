#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

#pragma once

class Screen
{
public:
    Screen();
    ~Screen();
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;

public:
    bool init();
    bool processEvents();
    void close();
};

#endif