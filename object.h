#ifndef OBJECT_H
#define OBJECT_H

// For random
#include "time.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "global.h"
#include "non_living_things.h"
#include "targetable.h"

class Object: public Non_living_things, public Targetable
{
    private:

    // x y positions of object
    int x, y;
    // The amount of objects picked up
    int wins;

    // used for score
    SDL_Surface* score ;
    TTF_Font* font ;
    SDL_Color* score_color ;

    // Use for Image
    SDL_Surface* object;

    public:
    // Initialize variables
    Object(std::string filename);

    // Procedure for when the object was found
    void respawn();

    // New position for the object
    void new_position();

    void show();

    // Get the amount of winds
    int get_wins();


};

#endif // OBJECT_H
