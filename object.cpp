#include "object.h"
//todo: correct HIGHT and WIDTH automatically by picture size

Object::Object(std::string filename)
    :Non_living_things(30,30, filename)
{
    srand(time(NULL));

    // No wins yet
    wins = 0;
    font = TTF_OpenFont("lazy.ttf", 28);

    // The image accompanying the object
    object = load_image(filename);
}

// Procedure for when the object was found
void Object::respawn()
{
    new_position();
    wins = wins + 1;
}

// choose a new position at random
void Object::new_position()
{
    m_x = rand() % SCREEN_WIDTH;
    m_y = rand() % SCREEN_HEIGHT;
}

// Showing the object
void Object::show()
{

    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = m_x;
    offset.y = m_y;

    //Blit
    SDL_BlitSurface( object, NULL,  global::screen, &offset );
    SDL_Rect offset2;
    offset2.x = 20;
    offset2.y = 30;
    char score_text[32];
    sprintf(score_text, "Score: %d", wins);
    score = TTF_RenderText_Solid(font, score_text, {0,0,0});
    SDL_BlitSurface(score, NULL, global::screen, &offset2);

}

