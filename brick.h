#ifndef BRICK_H
#define BRICK_H

#include "object.h"

class Brick: public Object
{
public:
    Brick(float x, float y);
    virtual ~Brick();
    virtual void paint(float m_TimeElapsed);
    virtual int getType(){return type_;}
    virtual float getX(){return x_;}
    virtual float getY(){return y_;}
    virtual void setX(float x){x_=x;}
    virtual void setY(float y){y_=y;}
    virtual void changeDirectX(){}
    virtual void changeDirectY(){}
    virtual void setDirection(float x, float y){}
    virtual void ballMovement(){}

};

#endif // BRICK_H
