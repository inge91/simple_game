#include "character.h"
#include "test.h"

int DOT_HEIGHT = 39;
int DOT_WIDTH = 23;


Character::Character(std::string filename)
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

    // Initialize image
    character = load_image(filename);
}

void Character::handle_input()
{
    //If a key was pressed
    if( global::event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( global::event.key.keysym.sym )
        {
            case SDLK_UP:
                yVel -= DOT_HEIGHT / 6;
                change_image(UP);
                break;

            case SDLK_DOWN:
                    yVel += DOT_HEIGHT / 6;
                    change_image(DOWN);
                    break;

            case SDLK_LEFT:
                xVel -= DOT_WIDTH / 6;
                change_image(LEFT);
                break;

            case SDLK_RIGHT:
                xVel += DOT_WIDTH / 6;
                change_image(RIGHT);
                break;

}    }
    //If a key was released
    else if( global::event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( global::event.key.keysym.sym )
        {
            case SDLK_UP: yVel += DOT_HEIGHT / 6; break;
            case SDLK_DOWN: yVel -= DOT_HEIGHT / 6; break;
            case SDLK_LEFT: xVel += DOT_WIDTH / 6; break;
            case SDLK_RIGHT: xVel -= DOT_WIDTH / 6; break;
        }
    }
}

void Character::move()
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
        x = SCREEN_WIDTH - DOT_WIDTH;
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

void Character::show()
{
    //Show the dot

    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface(character, NULL,  global::screen, &offset );
}


//FIXME: Dont change after last keypress
void Character::change_image(Character::Direction direction)
{
    switch(direction)
    {

        case UP:
            std::cout<<"Change up\n";
            character = load_image("character_up.bmp");
            break;
        case DOWN:
            std::cout<<"Change down\n";
            character = load_image("character_down.bmp");
            break;
        case LEFT:
            std::cout<<"Change left\n";
            character = load_image("character_left.bmp");
            break;
        case RIGHT:
            std::cout<<"Change right\n";
            character = load_image("character_right.bmp");
            break;
    }

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


