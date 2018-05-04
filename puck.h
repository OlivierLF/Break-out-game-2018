#ifndef PUCK_H
#define PUCK_H


#include "object.h"

class Puck: public Object
{
public:
    Puck(float x, float y);
    virtual ~Puck();
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

#endif // PUCK_H
