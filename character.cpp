#include "character.h"
#include "test.h"

Character::Character(std::string filename)
    :Living_things(0,0, filename)
{
    //Initialize the velocity
    xVel = 0;
    yVel = 0;

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
                yVel -= m_height / 8;
                break;

            case SDLK_DOWN:
                    yVel += m_height / 8;
                    break;

            case SDLK_LEFT:
                xVel -= m_width / 6;
                break;

            case SDLK_RIGHT:
                xVel += m_width / 6;
                break;

}    }
    //If a key was released
    else if( global::event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( global::event.key.keysym.sym )
        {
            case SDLK_UP: yVel += m_height / 8; break;
            case SDLK_DOWN: yVel -= m_height / 8; break;
            case SDLK_LEFT: xVel += m_width / 6; break;
            case SDLK_RIGHT: xVel -= m_width / 6; break;
        }
    }
}

void Character::move()
{
    //Move the dot left or right
    m_x += xVel;
    if(xVel > 0)
    {
        change_image(RIGHT);
    }
    if(xVel < 0)
    {
        change_image(LEFT);
    }

   // check if not out of bounds
   if( m_x < 0)
   {
       m_x = 0;
   }

   if( (m_x + m_width) > SCREEN_WIDTH )
   {
        m_x = SCREEN_WIDTH - m_width;
   }

    //Move the dot left or right
    m_y += yVel;

    if(yVel > 0)
    {
        change_image(DOWN);
    }

    if(yVel < 0)
    {
        change_image(UP);
    }

   // check if not out of bounds
   if( m_y < 0)
   {
       m_y = 0;
   }

   if( (m_y + m_height) > SCREEN_HEIGHT )
   {
        m_y = SCREEN_HEIGHT - m_height;
   }

}


//FIXME: Dont change after last keypress, but direction of movement
void Character::change_image(Character::Direction direction)
{
    switch(direction)
    {
        case UP:
            m_image = load_image("character_up.bmp");
            break;
        case DOWN:
            m_image = load_image("character_down.bmp");
            break;
        case LEFT:
            m_image = load_image("character_left.bmp");
            break;
        case RIGHT:
            m_image = load_image("character_right.bmp");
            break;
    }

}

void Character::respawn()
{
    m_x = 0;
    m_y = 0;
    m_invul = true;
}

bool Character::get_invul()
{
    return m_invul;
}


