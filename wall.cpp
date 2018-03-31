#include "wall.h"
#include "object.h"
#include <iostream>


Wall::Wall(float x, float y, bool lat):Object()
{
    x_=x;
    y_=y;
    lat_=lat;
}

Wall::~Wall(){
    delete this;
}

void Wall::paint(){

    //mur du dessus ou dessous
    float WALL_WIDTH=61.0;
    float WALL_HEIGHT=10.0;

    //mur sur les côtés
    if(lat_){
        WALL_WIDTH=10.0;
        WALL_HEIGHT=50.0;
    }

    glBegin(GL_QUADS);
    glColor3ub(255,255,255); // c'est ce paramètre qui choisi la couleur de la face avant visible
    glVertex3f(x_, y_, -5.0f); glVertex3f( x_+WALL_WIDTH, y_, -5.0f);
    glVertex3f( x_+WALL_WIDTH, y_+WALL_HEIGHT, -5.0f);
    glVertex3f(x_, y_+WALL_HEIGHT, -5.0f);

    glColor3ub(255,0,255); glVertex3f(x_, y_, -7.0f); glVertex3f( x_+WALL_WIDTH, y_, -7.0f);
    glVertex3f( x_+WALL_WIDTH, y_+WALL_HEIGHT, -7.0f);
    glVertex3f(x_, y_+WALL_HEIGHT, -7.0f);

    glColor3ub(255,0,0); glVertex3f(x_, y_+WALL_HEIGHT, -7.0f); glVertex3f(x_, y_+WALL_HEIGHT, -5.0f);
    glVertex3f( x_+WALL_WIDTH, y_+WALL_HEIGHT, -5.0f);
    glVertex3f( x_+WALL_WIDTH, y_+WALL_HEIGHT, -7.0f);

    glColor3ub(0,255,255); glVertex3f(x_, y_, -7.0f); glVertex3f( x_+WALL_WIDTH, y_, -7.0f);
    glVertex3f( x_+WALL_WIDTH, y_, -5.0f);
    glVertex3f(x_, y_, -5.0f);

    glColor3ub(0,255,0); glVertex3f( x_+WALL_WIDTH, y_, -7.0f); glVertex3f( x_+WALL_WIDTH, y_+WALL_HEIGHT, -7.0f);
    glVertex3f( x_+WALL_WIDTH, y_+WALL_HEIGHT, -5.0f);
    glVertex3f( x_+WALL_WIDTH, y_, - 5.0f);

    glColor3ub(255,255,0); glVertex3f(x_, y_, -7.0f); glVertex3f(x_, y_, -5.0f);
    glVertex3f(x_, y_+WALL_HEIGHT, -5.0f);
    glVertex3f(x_, y_+WALL_HEIGHT, -7.0f);
    glEnd();
}
