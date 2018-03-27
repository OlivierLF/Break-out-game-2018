#ifndef WALL_H
#define WALL_H

#include "object.h"

class Wall: public Object
{
public:
    Wall(float x, float y, bool lat);
    virtual ~Wall();
    virtual void paint();

private:
    float x_;
    float y_;
    bool lat_;
};

#endif // WALL_H
