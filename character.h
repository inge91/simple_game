#ifndef CHARACTER_H
#define CHARACTER_H
#include "SDL/SDL.h"
#include "test.h"
#include "global.h"
#include "living_things.h"
#include "targetable.h"

//The dot that will move around on the screen
class Character : public Living_things, public Targetable
{
    private:

    int xVel;
    int yVel;
    // Enum for the direction
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    public:
    // Initializes the variables
    Character(std::string filename);

    // Takes key presses and adjusts the dot's velocity
    void handle_input();

    // Moves the dot
    virtual void move() ;

    void change_image(Character::Direction direction);
    virtual void respawn() ;
    bool get_invul();
};

#endif

