#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glu.h>

class Object
{
public:
    Object();
    virtual ~Object();
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
    virtual bool getBallMovementTest(){}


protected:
    float x_;
    float y_;
    int type_;

};

#endif // OBJECT_H
