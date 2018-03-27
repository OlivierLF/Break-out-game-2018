#include "ball.h"
#include "object.h"
#include <GL/glu.h>

Ball::Ball(float rad, float r, float g, float b)
{
    this->rad_=rad;
    quadrique_=gluNewQuadric();
    red_=r;
    blue_=b;
    green_=g;
}

Ball::~Ball(){
    gluDeleteQuadric(quadrique_);
    delete this;
}

void Ball::paint(){
    glPushMatrix();
    glLoadIdentity();
    // Couleur de l'objet
    //float color[]={red_,green_,blue_,1.0f};
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);

    glTranslatef(10.0,-40,0);
    // Affichage de la quadrique
    gluQuadricDrawStyle(quadrique_, GL_FILL);
    gluSphere(quadrique_, rad_,100, 10);
    gluDeleteQuadric(quadrique_);

    glPopMatrix();
}
