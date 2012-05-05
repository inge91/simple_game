#ifndef GLOBAL_H
#define GLOBAL_H
#include "SDL/SDL.h"

class global
{
    public:

    static SDL_Surface* screen;
    static SDL_Surface* background;
    static SDL_Event event;
};

#endif // GLOBAL_H
