#include "brick.h"
#include "object.h"

const float BRICK_WIDTH=3.0;
const float BRICK_HEIGHT=1.0;

Brick::Brick(float x, float y):Object()
{
    x_=x;
    y_=y;
}

Brick::~Brick(){
    delete this;
}

void Brick::paint(){

    glBegin(GL_QUADS);
    glColor3ub(0,0,255); glVertex3f(x_, y_, -5.0f); glVertex3f( x_+BRICK_WIDTH, y_, -5.0f);
    glVertex3f( x_+BRICK_WIDTH, y_+BRICK_HEIGHT, -5.0f);
    glVertex3f(x_, y_+BRICK_HEIGHT, -5.0f);

    glColor3ub(255,0,255); glVertex3f(x_, y_, -7.0f); glVertex3f( x_+BRICK_WIDTH, y_, -7.0f);
    glVertex3f( x_+BRICK_WIDTH, y_+BRICK_HEIGHT, -7.0f);
    glVertex3f(x_, y_+BRICK_HEIGHT, -7.0f);

    glColor3ub(255,0,0); glVertex3f(x_, y_+BRICK_HEIGHT, -7.0f); glVertex3f(x_, y_+BRICK_HEIGHT, -5.0f);
    glVertex3f( x_+BRICK_WIDTH, y_+BRICK_HEIGHT, -5.0f);
    glVertex3f( x_+BRICK_WIDTH, y_+BRICK_HEIGHT, -7.0f);

    glColor3ub(0,255,255); glVertex3f(x_, y_, -7.0f); glVertex3f( x_+BRICK_WIDTH, y_, -7.0f);
    glVertex3f( x_+BRICK_WIDTH, y_, -5.0f);
    glVertex3f(x_, y_, -5.0f);

    glColor3ub(0,255,0); glVertex3f( x_+BRICK_WIDTH, y_, -7.0f); glVertex3f( x_+BRICK_WIDTH, y_+BRICK_HEIGHT, -7.0f);
    glVertex3f( x_+BRICK_WIDTH, y_+BRICK_HEIGHT, -5.0f);
    glVertex3f( x_+BRICK_WIDTH, y_, - 5.0f);

    glColor3ub(255,255,0); glVertex3f(x_, y_, -7.0f); glVertex3f(x_, y_, -5.0f);
    glVertex3f(x_, y_+BRICK_HEIGHT, -5.0f);
    glVertex3f(x_, y_+BRICK_HEIGHT, -7.0f);
    glEnd();
}
