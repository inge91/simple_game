#ifndef THINGS_H
#define THINGS_H
#include "test.h"
#include "global.h"

class Things
{

protected:
    // x y values
    int m_x, m_y;
    int m_width, m_height;
    SDL_Surface* m_image;

public:
    Things();
    Things(int x_pos, int y_pos, std::string filename);

    // Mandatory function
    int get_position_x();
    int get_position_y();
    int get_height();
    int get_width();
    virtual void show(){}

};

#endif // THINGS_H
