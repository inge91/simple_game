#include "things.h"

Things::Things(int x_pos, int y_pos, int im_width, int im_height,
               std::string filename)
{
    m_x = x_pos;
    m_y = y_pos;
    m_width = im_width;
    m_height = im_height;

    m_image = load_image(filename);
}

Things::get_position_x()
{
    return x;
}

Things::get_position_y()
{
    return y;
}

Things::get_height()
{
    return height;
}

Things::get_width()
{
    return width;
}

