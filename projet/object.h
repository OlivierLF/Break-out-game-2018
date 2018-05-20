#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glu.h>

class Object
{
public:
    Object();
    virtual ~Object();
    //affiche la brique
    virtual void paint(float m_TimeElapsed);
    //getters & setters
    virtual int getType(){return type_;}
    virtual float getX(){return x_;}
    virtual float getY(){return y_;}
    virtual void setX(float x){x_=x;}
    virtual void setY(float y){y_=y;}
    virtual void setDirection(float x, float y){}
    virtual bool getBallMovementTest(){}
    //change la direction latérale
    virtual void changeDirectX(){}
    //change la direction verticale
    virtual void changeDirectY(){}
    //active ou désactive le mouvement de la balle
    virtual void ballMovement(){}



protected:
    float x_;
    float y_;
    int type_;

};

#endif // OBJECT_H
