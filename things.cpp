#include "things.h"

Things::Things()
{}

Things::Things(int x_pos, int y_pos, std::string filename)
{
    // Initialise x and y pos in board
    m_x = x_pos;
    m_y = y_pos;

    m_image = load_image(filename);

    // Height and width determined by image size
    m_width = m_image->w;
    m_height = m_image->h;
}

int Things::get_position_x()
{
    return m_x;
}

int Things::get_position_y()
{
    return m_y;
}

int Things::get_height()
{
    return m_height;
}

int Things::get_width()
{
    return m_width;
}



