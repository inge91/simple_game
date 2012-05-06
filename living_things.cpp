#include "living_things.h"

Living_things::Living_things(int x, int y, std::string filename)
    :Things(x, y, filename)
{

}

// TODO: Add animations!(not that hard)
void Living_things::show()
{
    //Show the dot

    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = m_x;
    offset.y = m_y;

    //Blit
    SDL_BlitSurface(m_image, NULL,  global::screen, &offset );
}
