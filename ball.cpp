#include "ball.h"
#include "object.h"
#include <GL/glu.h>
#include <iostream>

Ball::Ball(float rad, float r, float g, float b)
{
    //Type = balle = 0
    type_=0;

    //Position initiale de la balle
    x_=10.0f;
    y_=-40.0f;

    this->rad_=rad; //Rayon de la balle

    //Couleur de la balle
    red_=r;
    blue_=b;
    green_=g;

    //Direction initiale de la balle
    direction_[0]=0.5f;
    direction_[1]=0.5f;
}

Ball::~Ball(){
    gluDeleteQuadric(quadrique_);
    delete this;
}

void Ball::paint(float m_TimeElapsed){
    glPushMatrix();
    glLoadIdentity();

    // Couleur de l'objet
    float color[]={red_,green_,blue_,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);

    //Déplacement de la balle
    glTranslatef(x_+direction_[0]*0.1f,y_+direction_[1]*0.1f,0);

    //Mise a jour des coordonnees de la balle
    x_=x_+direction_[0]*0.2f;
    y_=y_+direction_[1]*0.2f;

    //Déclaration de la quadrique
    quadrique_=gluNewQuadric();
    // Affichage de la quadrique
    gluQuadricDrawStyle(quadrique_, GL_FILL);
    gluSphere(quadrique_, rad_,100, 10);
    gluDeleteQuadric(quadrique_);
    glPopMatrix();
}
