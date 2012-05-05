#ifndef THINGS_H
#define THINGS_H
#include "test.h"
#include "global.h"

class Things
{

private:
    // x y values
    int m_x, m_y;
    int m_width, m_height;
    SDL_Surface* m_image;

public:
    Things(int x_pos, int y_pos, int im_width, int im_height, std::string filename);

    // Mandatory function
    int get_position_x();
    int get_position_y();
    int get_height();
    int get_width();

};

#endif // THINGS_H
