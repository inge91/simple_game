#include "object.h"
//todo: correct HIGHT and WIDTH automatically by picture size

Object::Object()
{
    // We choose a beginning position for the object
    x = 30;
    y = 30;
    OBJECT_HEIGHT = 20;
    OBJECT_WIDTH = 20;
    srand(time(NULL));

    // No wins yet
    wins = 0;
    font = TTF_OpenFont("lazy.ttf", 28);
}

// Procedure for when the object was found
void Object::found_object(int max_width, int max_height)
{
    new_position(max_height, max_width);
    wins = wins + 1;
}

// choose a new position at random
void Object::new_position(int max_height, int max_width)
{
    x = rand() % max_width;
    y = rand() % max_height;
}

// Showing the object
void Object::show(SDL_Surface* object, SDL_Surface* screen)
{

    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( object, NULL,  screen, &offset );
    SDL_Rect offset2;
    offset2.x = 20;
    offset2.y = 30;
    char score_text[32];
    sprintf(score_text, "Score: %d", wins);
    score = TTF_RenderText_Solid(font, score_text, {0,0,0});
    SDL_BlitSurface(score, NULL, screen, &offset2);


}


// Return the amount of wins
int Object::get_wins()
{
    return wins;
}

// Return the x position
int Object::get_position_x()
{
    return x;
}

// Return the y position
int Object::get_position_y()
{
    return y;
}

int Object::get_width()
{
    return OBJECT_WIDTH;
}

int Object::get_height()
{
    return OBJECT_HEIGHT;
}
