#include "wall.h"
#include "object.h"
#include <iostream>


Wall::Wall(float x, float y, bool lat):Object()
{
    //Type = brick = 3
    type_=3;

    //Position du coin inf droit d'un mur
    x_=x;
    y_=y;

    //Côté latéral ou non
    lat_=lat;
}

Wall::~Wall(){
    delete this;
}

void Wall::paint(float m_TimeElapsed){

    //mur du dessus ou dessous
    float WALL_WIDTH=53.8;
    float WALL_HEIGHT=10.0;

    //mur sur les côtés
    if(lat_){
        WALL_WIDTH=10.0;
        WALL_HEIGHT=24.0;
    }

    glBegin(GL_QUADS);
    glColor3ub(255,255,255); // c'est ce paramètre qui choisit la couleur de la face avant visible
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
