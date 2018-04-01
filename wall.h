#ifndef WALL_H
#define WALL_H

#include "object.h"

class Wall: public Object
{
public:
    Wall(float x, float y, bool lat);
    virtual ~Wall();
    virtual void paint(float m_TimeElapsed);
    virtual int getType(){return type_;}
    virtual float getX(){return x_;}
    virtual float getY(){return y_;}
    virtual void setX(float x){x_=x;}
    virtual void setY(float y){y_=y;}
    virtual void changeDirectX(){}
    virtual void changeDirectY(){}

private:
    bool lat_;
};

#endif // WALL_H
