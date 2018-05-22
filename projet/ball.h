#ifndef BALL_H
#define BALL_H

#include <GL/glu.h>
#include "object.h"

class Ball : public Object
{
public:
    Ball(float x, float y, float rad, float r, float g, float b);
    virtual ~Ball();
    //affiche la balle
    virtual void paint(float m_TimeElapsed);
    //getters & setters
    virtual int getType(){return type_;}
    virtual float getX(){return x_;}
    virtual float getY(){return y_;}
    virtual void setX(float x){x_=x;}
    virtual void setY(float y){y_=y;}
    virtual void setDirection(float x, float y);
    virtual bool getBallMovementTest(){return moveTest_;}
    //change la direction latérale
    virtual void changeDirectX(){direction_[0]=-direction_[0];}
    //change la direction verticale
    virtual void changeDirectY(){direction_[1]=-direction_[1];}
    //active ou désactive le mouvement de la balle
    virtual void ballMovement(){moveTest_= !moveTest_;}

private:
    //Détermine en rgb la couleur de la balle
    float red_;
    float green_;
    float blue_;
    //contient le rayon de la balle
    float rad_;
    //contient la quadrique qui sert à l'affichage
    GLUquadric* quadrique_;
    //contient la direction de la balle
    float direction_[2];
    //test pour savoir si la balle est en mouvement
    bool moveTest_;
    //variable pour savoir s'il faut afficher la balle ou non
    bool displayBall_;
};

#endif // BALL_H
