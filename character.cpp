#include "character.h"

int DOT_HEIGHT = 39;
int DOT_WIDTH = 23;


Character::Character()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;
}

void Character::handle_input(SDL_Event event)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= DOT_HEIGHT / 6; break;
            case SDLK_DOWN: yVel += DOT_HEIGHT / 6; break;
            case SDLK_LEFT: xVel -= DOT_WIDTH / 6; break;
            case SDLK_RIGHT: xVel += DOT_WIDTH / 6; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += DOT_HEIGHT / 6; break;
            case SDLK_DOWN: yVel -= DOT_HEIGHT / 6; break;
            case SDLK_LEFT: xVel += DOT_WIDTH / 6; break;
            case SDLK_RIGHT: xVel -= DOT_WIDTH / 6; break;
        }
    }
}

void Character::move(int SCREEN_HEIGHT, int SCREEN_WIDTH)
{
    //Move the dot left or right
    x += xVel;

   // check if not out of bounds
   if( x < 0)
   {
       x = 0;
   }

   if( (x + DOT_WIDTH) > SCREEN_WIDTH )
   {
        x = SCREEN_WIDTH - DOT_WIDTH ;
   }

    //Move the dot left or right
    y += yVel;

   // check if not out of bounds
   if( y < 0)
   {
       y = 0;
   }

   if( (y + DOT_HEIGHT) > SCREEN_HEIGHT )
   {
        y = SCREEN_HEIGHT - DOT_HEIGHT;
   }

}

void Character::show(SDL_Surface* dot, SDL_Surface* screen)
{
    //Show the dot

    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( dot, NULL,  screen, &offset );
}

int Character::get_position_x()
{
    return x;
}

int Character::get_position_y()
{
    return y;
}

int Character::get_height()
{
    return DOT_HEIGHT;
}

int Character::get_width()
{
    return DOT_WIDTH;
}


