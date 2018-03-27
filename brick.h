#ifndef BRICK_H
#define BRICK_H

#include "object.h"

class Brick: public Object
{
public:
    Brick(float x, float y);
    virtual ~Brick();
    virtual void paint();

private:
    float x_;
    float y_;
};

#endif // BRICK_H
