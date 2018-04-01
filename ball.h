#ifndef BALL_H
#define BALL_H

#include <GL/glu.h>
#include "object.h"

class Ball : public Object
{
public:
    Ball(float rad, float r, float g, float b);
    virtual ~Ball();
    virtual void paint(float m_TimeElapsed);
    virtual int getType(){return type_;}
    virtual float getX(){return x_;}
    virtual float getY(){return y_;}
    virtual void setX(float x){x_=x;}
    virtual void setY(float y){y_=y;}
    virtual void changeDirectX(){direction_[0]=-direction_[0];}
    virtual void changeDirectY(){direction_[1]=-direction_[1];}

private:
    float red_;
    float green_;
    float blue_;
    float rad_;
    GLUquadric* quadrique_;
    float direction_[2];
};

#endif // BALL_H
