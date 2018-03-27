#ifndef BALL_H
#define BALL_H

#include <GL/glu.h>
#include "object.h"

class Ball : public Object
{
public:
    Ball(float rad, float r, float g, float b);
    virtual ~Ball();
    virtual void paint();

private:
    float red_;
    float green_;
    float blue_;
    float rad_;
    GLUquadric* quadrique_;

};

#endif // BALL_H
