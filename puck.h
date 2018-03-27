#ifndef PUCK_H
#define PUCK_H


#include "object.h"

class Puck: public Object
{
public:
    Puck(float x, float y);
    virtual ~Puck();
    virtual void paint();
    float getX();
    void setX(float x);

private:
    float x_;
    float y_;
};

#endif // PUCK_H
