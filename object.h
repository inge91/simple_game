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

class Object
{
    private:

    // x y positions of object
    int x, y;
    // The amount of objects picked up
    int wins;

    int OBJECT_HEIGHT ;
    int OBJECT_WIDTH  ;

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
    void found_object();

    // New position for the object
    void new_position();

    void show();



    // Get the amount of winds
    int get_wins();

    // Return object position
    int get_position_x();
    int get_position_y();
    int get_width();
    int get_height();

};

#endif // OBJECT_H
