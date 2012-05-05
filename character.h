#ifndef CHARACTER_H
#define CHARACTER_H
#include "SDL/SDL.h"

//The dot that will move around on the screen
class Character
{
    private:
    //The X and Y offsets of the dot
    int x, y;

    //The velocity of the dot
    int xVel, yVel;
    //The dimensions of the dot
    //int DOT_WIDTH = 20;
    //int DOT_HEIGHT = 20;


    public:
    //Initializes the variables
    Character();

    //Takes key presses and adjusts the dot's velocity
    void handle_input(SDL_Event event);

    //Moves the dot
    void move(int h, int w);

    //Shows the dot on the screen
    void show(SDL_Surface* dot, SDL_Surface* screen);

    // Get all positions;
    int get_position_x();
    int get_position_y();
    int get_width();
    int get_height();
};

#endif

