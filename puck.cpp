#include "puck.h"
#include "object.h"


const float PUCK_WIDTH=5.0;
const float PUCK_HEIGHT=1.0;


Puck::Puck(float x, float y):Object()
{
    //Type = puck = 2
    type_=2;

    //Position du coin inf droit d'un palet
    x_=x;
    y_=y;
}

Puck::~Puck(){
    delete this;
}

void Puck::paint(float m_TimeElapsed){
    glBegin(GL_QUADS);

    glColor3ub(255,255,255); // c'est ce paramètre qui choisi la couleur de la face avant visible
    glVertex3f(x_, y_, -5.0f); glVertex3f( x_+PUCK_WIDTH, y_, -5.0f);
    glVertex3f( x_+PUCK_WIDTH, y_+PUCK_HEIGHT, -5.0f);
    glVertex3f(x_, y_+PUCK_HEIGHT, -5.0f);

    glColor3ub(255,0,255); glVertex3f(x_, y_, -7.0f); glVertex3f( x_+PUCK_WIDTH, y_, -7.0f);
    glVertex3f( x_+PUCK_WIDTH, y_+PUCK_HEIGHT, -7.0f);
    glVertex3f(x_, y_+PUCK_HEIGHT, -7.0f);

    glColor3ub(255,0,0); glVertex3f(x_, y_+PUCK_HEIGHT, -7.0f); glVertex3f(x_, y_+PUCK_HEIGHT, -5.0f);
    glVertex3f( x_+PUCK_WIDTH, y_+PUCK_HEIGHT, -5.0f);
    glVertex3f( x_+PUCK_WIDTH, y_+PUCK_HEIGHT, -7.0f);

    glColor3ub(0,255,255); glVertex3f(x_, y_, -7.0f); glVertex3f( x_+PUCK_WIDTH, y_, -7.0f);
    glVertex3f( x_+PUCK_WIDTH, y_, -5.0f);
    glVertex3f(x_, y_, -5.0f);

    glColor3ub(0,255,0); glVertex3f( x_+PUCK_WIDTH, y_, -7.0f); glVertex3f( x_+PUCK_WIDTH, y_+PUCK_HEIGHT, -7.0f);
    glVertex3f( x_+PUCK_WIDTH, y_+PUCK_HEIGHT, -5.0f);
    glVertex3f( x_+PUCK_WIDTH, y_, - 5.0f);

    glColor3ub(255,255,0); glVertex3f(x_, y_, -7.0f); glVertex3f(x_, y_, -5.0f);
    glVertex3f(x_, y_+PUCK_HEIGHT, -5.0f);
    glVertex3f(x_, y_+PUCK_HEIGHT, -7.0f);
    glEnd();
}

