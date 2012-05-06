#ifndef LIVING_THINGS_H
#define LIVING_THINGS_H
#include "things.h"

class Things;
class Living_things:public Things
{
public:
    Living_things(int x, int y, std::string filename);

    virtual void move(){}
    void show();
};

#endif // LIVING_THINGS_H
