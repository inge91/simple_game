#include "bandit.h"
#include "things.h"
#include <iostream>

Bandit::Bandit(std::string filename, Things* target)
    :Living_things(50, 50, filename)
{
    // Set the random seed
    srandom(time(NULL));

    // Set the target of the bandit
    m_target = target;

}

// The move of the bandit tries to lessen
// the distance between the target and himself
void Bandit::move(){

    // If difference in x value is bigger than y value
    if( abs(m_target->get_position_x() - m_x) > abs(m_target->get_position_y() - m_y))
    {
        // Get closer in the x direction
        if(m_target->get_position_x() > m_x)
        {
            m_x += 3;
            change_image(RIGHT);
        }
        else{
            m_x -=3;

            change_image(LEFT);
        }

    }
    // If difference in y value is bigger than x value
    else if( abs(m_target->get_position_x() - m_x) < abs(m_target->get_position_y() - m_y))
    {

        // Get closer in the y direction
        if(m_target->get_position_y() > m_y)
        {
            m_y += 3;
            change_image(DOWN);
        }
        else{
            m_y -=3;
            change_image(UP);
        }

    }

    else{
     m_x + 3;
     m_y + 3;
    }

}

// Changing the picture according to direction
void Bandit::change_image(Bandit::Direction direction)
{
    switch(direction)
    {
        case UP:
            m_image = load_image("thief_up.bmp");
            break;
        case DOWN:
            m_image = load_image("thief_down.bmp");
            break;
        case LEFT:
            m_image = load_image("thief_left.bmp");
            break;
        case RIGHT:
            m_image = load_image("thief_right.bmp");
            break;
    }

}

void Bandit::check_if_caught()
{
    if(collision_detection(m_x,m_y, m_width, m_height, m_target->m_x, m_target->m_y
                           , m_target->m_width, m_target->m_height) == true)
    {
        m_target

    }
}
