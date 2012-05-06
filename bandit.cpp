#include "bandit.h"
#include "things.h"
#include <iostream>

Bandit::Bandit(std::string filename, Targetable* target)
    :Living_things(300,300, filename)
{
    // Set the random seed
    srandom(time(NULL));

    // Set the target of the bandit
    m_target = target;

}

// The move of the bandit tries to lessen
// the distance between the target and himself
void Bandit::move(){

    Things* target;
    // Make a Things of m_target for coordinates
    if (target = dynamic_cast<Things*>(m_target))
    {
        // If difference in x value is bigger than y value
        if( abs(target->get_position_x() - m_x) > abs(target->get_position_y() - m_y))
        {
            // Get closer in the x direction
            if(target->get_position_x() > m_x)
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
        else if( abs(target->get_position_x() - m_x) < abs(target->get_position_y() - m_y))
        {

            // Get closer in the y direction
            if(target->get_position_y() > m_y)
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
        // The cases in which x and y positions are equallty far away
        if(m_x < target->get_position_x() && m_y < target->get_position_y())
        {
            m_x += 1.5;
            m_y += 1.5;
        }
        if(m_x > target->get_position_x() && m_y < target->get_position_y())
        {
            m_x -= 1.5;
            m_y += 1.5;
        }

        if(m_x < target->get_position_x() && m_y > target->get_position_y())
        {
            m_x += 1.5;
            m_y -= 1.5;
        }

        if(m_x > target->get_position_x() && m_y > target->get_position_y())
        {
            m_x -= 1.5;
            m_y -= 1.5;
        }
    }
}
           // nu kan je zijn positie opvragen
    else
    {exit(1);
}
           // foutmelding ofz


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

// Check if the character is caught
bool Bandit::check_if_caught()
{
    Things* target;
    if (target = dynamic_cast<Things*>(m_target))
    {
        // If there is a collision and target doesn't have invul
        if(collision_detection(m_x,m_y, m_width, m_height,
                               target->get_position_x(), target->get_position_y()
                               , target->get_width(), target->get_height()) == true
                                &&m_target->get_invul() == false)
        {
            // Respawn the Targetable
            m_target->respawn();
            return true;

        }
        return false;
    }
    else
        exit(1);
}


Targetable* Bandit::return_target()
{
    return m_target;
}



