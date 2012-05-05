#ifndef CHARACTER_H
#define CHARACTER_H
#include "SDL/SDL.h"
#include "test.h"
#include "global.h"

//The dot that will move around on the screen
class Character
{
    private:
    // The X and Y offsets of the dot
    int x, y;

    // The velocity of the dot
    int xVel, yVel;

    // Character image;
    SDL_Surface* character;

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
    void move();

    void change_image(Character::Direction direction);
    // Shows the dot on the screen
    void show();

    // Get all positions;
    int get_position_x();
    int get_position_y();
    int get_width();
    int get_height();
};

#endif

