#include "puck.h"
#include "object.h"


const float PUCK_WIDTH=5.0;
const float PUCK_HEIGHT=1.0;


Puck::Puck(float x, float y):Object()
{
    x_=x;
    y_=y;
}

Puck::~Puck(){
    delete this;
}

void Puck::paint(){
    glBegin(GL_QUADS);
    glColor3ub(0,0,255); glVertex3f(x_, y_, -5.0f); glVertex3f( x_+PUCK_WIDTH, y_, -5.0f);
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

float Puck::getX(){
    return x_;
}

void Puck::setX(float x){
    x_=x;
}
