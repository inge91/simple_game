#ifndef BANDIT_H
#define BANDIT_H
#include "living_things.h"
#include <string>
#include "time.h"
#include "test.h"
#include "global.h"
#include "targetable.h"

class Bandit: public Living_things
{

private:
    // The target of the bandit
    Targetable* m_target;

public:
    Bandit(std::string filename, Targetable *target);

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    //Changing the sides he looks at
    void change_image(Bandit::Direction direction);

    // The move function
    void move();

    // Check if its target was caught
    bool check_if_caught();

    // Returns vulnerability status of target
    bool return_target_invul();

    Targetable* return_target();


};

#endif // BANDIT_H
