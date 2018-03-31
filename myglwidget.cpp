#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include <iostream>
#include <GL/glu.h>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1366;
const unsigned int WIN_HEIGHT = 768;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    // Reglage de la lampe
    //glEnable(GL_LIGHT0);
    //Couleur de l'éclairage
    //GLfloat lampe []={1.0,1.0,1.0,1.0};
    //glLightfv(GL_LIGHT0,GL_AMBIENT_AND_DIFFUSE,lampe);
    //Position de la lampe
    //GLfloat position []={0.0,0.0,0.0,1.0};
    //glLightfv(GL_LIGHT0,GL_POSITION,position);

    // Activation de la lumiere
    //glEnable(GL_LIGHTING);

    // Création de la scène

    //Déclaration des murs
    Wall* top = new Wall(-10.0,0.0,false);
    Wall* bot = new Wall(-10.0,-60.0,false);
    Wall* left = new Wall(-10.0,-50.0,true);
    Wall* right = new Wall(41.0,-50.0,true);

    //Ajout des murs aux éléments de la scène
    scene_.push_back(top);
    scene_.push_back(bot);
    scene_.push_back(left);
    scene_.push_back(right);

    //Ajout des briques dans la scène
    int x=1;
    while (x<=37){
        int y=-2;
        while (y>=-23){
            scene_.push_back(new Brick(x,y));
            y=y-2;
        }
        x=x+4;
    }

    //Déclaration et ajout du palet à la scène
    myPuck_=new Puck(10,-48);
    scene_.push_back(myPuck_);

    //Déclaration et ajout de la balle à la scène
    scene_.push_back(new Ball(0.5,255,255,0));

}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-11,52,-61,11,-100,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Definition de la position de la camera
    gluLookAt(0.0f, 0.0f, 25.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);



    for (Object* obj : scene_){
        obj->paint();
    }



}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    std::cout<<"actif"<<std::endl;
    switch(event->key())
    {
    // Activation/Arret de l'animation
    case Qt::Key_Space:
    {
        break;
    }

    // Sortie de l'application
    case Qt::Key_Escape:
    {
        exit(0);
    }
    case Qt::LeftArrow:
    {
        std::cout<<"left"<<std::endl;
        myPuck_->setX(myPuck_->getX()-1);
        break;

    }
    case Qt::RightArrow:
    {
        myPuck_->setX(myPuck_->getX()+1);
        break;
    }
        // Cas par defaut
    default:
    {
        // Ignorer l'evenement
        event->ignore();
        return;
    }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}

