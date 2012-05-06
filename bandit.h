#ifndef BANDIT_H
#define BANDIT_H
#include "living_things.h"
#include <string>
#include "time.h"
#include "test.h"
#include "global.h"

class Bandit: public Living_things
{

private:
    // The target of the bandit
    Things* m_target;

public:
    Bandit(std::string filename, Things *target);

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    void change_image(Bandit::Direction direction);
    void move();

};

#endif // BANDIT_H
