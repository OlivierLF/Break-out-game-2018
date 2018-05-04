#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include <iostream>
#include <GL/glu.h>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 700;
const unsigned int WIN_HEIGHT = 720;

bool oneBallTest = true;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    //Initialisation du score à zéro
    score_=0;

    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 10.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();
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

    scene_.push_back(new Puck(20,-48));

    //Déclaration et ajout de la balle à la scène
    scene_.push_back(new Ball(22.5, -46.5, 0.5,255,255,0));

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
        if (obj->getType()==0){ //si l'objet est une balle
            //Gestion de la collision avec les murs
            if (obj->getY()>-0.5){ //mur du haut
                obj->changeDirectY();
            }
            if (obj->getX()<0.5){ //mur de gauche
                obj->changeDirectX();
            }
            if (obj->getX()>40.5){ //mur de droite
                obj->changeDirectX();
            }
            if (obj->getY()<-49.5){
                obj->changeDirectY();
                /*
                float newBallX;
                float newBallY;
                std::vector<Object*>::iterator it;
                for (it=scene_.begin();it!=scene_.end();++it){
                    if ((*it)->getType()==0 && oneBallTest){ //la balle tombe à côté du palet
                        //oneBallTest= !oneBallTest;
                    }
                    if ((*it)->getType()==2){ //si c'est un palet on enregistre la position pour y mettre une nouvelle balle
                        newBallX= 2.5 + (*it)->getX();
                        newBallY= 1.5 + (*it)->getY();
                    }
                }*/

            }

            std::vector<Object*>::iterator it;
            //Gestion de la collision avec les briques et le palet
            for (it=scene_.begin();it!=scene_.end();++it){
                if ((*it)->getType()==1){ //collision avec une brique
                    // la balle tape en dessous de la brique
                    if (obj->getY()>=(*it)->getY()-0.5 && obj->getY()<=(*it)->getY()+0.5
                            && obj->getX()>=(*it)->getX() && obj->getX()<=(*it)->getX()+3.0 ){
                        obj->changeDirectY();
                        scene_.erase(it);
                        score_+=1;
                    }
                    // la balle tape au dessus de la brique
                    if (obj->getY()>=(*it)->getY()+0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX() && obj->getX()<=(*it)->getX()+3.0 ){
                        obj->changeDirectY();
                        scene_.erase(it);
                        score_+=1;
                    }
                    //la balle tape sur le côté gauche de la brique
                    if (obj->getY()>=(*it)->getY()-0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX()-0.5 && obj->getX()<=(*it)->getX()){
                        obj->changeDirectX();
                        scene_.erase(it);
                        score_+=1;
                    }
                    //la balle tape sur le côté droit de la brique
                    if (obj->getY()>=(*it)->getY()-0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX()+3.0 && obj->getX()<=(*it)->getX()+3.5){
                        obj->changeDirectX();
                        scene_.erase(it);
                        score_+=1;
                    }
                }
                if ((*it)->getType()==2){ //collision avec le palet
                    // la balle tape au dessus du palet
                    if (obj->getY()>=(*it)->getY()+0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX() && obj->getX()<=(*it)->getX()+5.0 ){
                        float D = (obj->getX()-(*it)->getX()-2.5)*20; //angle en degrés
                        float pi =3.1415;
                        D = D*pi/180; // angle en rad
                        obj->setDirection(cos(pi/2-D), sin(pi/2-D));
                    }
                }
            }
        }
        QString scoreText = QString::number(score_);
        renderText(1,-49,0,"Score : "+scoreText);
        obj->paint(m_TimeElapsed);
    }
}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
}


void MyGLWidget::moveLeft(){
    std::vector<Object*>::iterator it;
    for (it=scene_.begin();it!=scene_.end();++it){
        if ((*it)->getType()==2){ //Si l'objet est un palet
            //Condition pour ne pas faire sortir le palet de la partie jouable
            if ((*it)->getX() > 0){
                (*it)->setX((*it)->getX()-1);
            }

        }
    }
}

void MyGLWidget::moveRight(){
    std::vector<Object*>::iterator it;
    for (it=scene_.begin();it!=scene_.end();++it){
        if ((*it)->getType()==2){ //Si l'objet est un palet
            //Condition pour ne pas faire sortir le palet de la partie jouable
            if ((*it)->getX() <36){ //largeur (41) - taille du palet (5) = 35
                (*it)->setX((*it)->getX()+1);
            }
        }
    }
}

void MyGLWidget::changeBallMovement(){
    std::vector<Object*>::iterator it;
    for (it=scene_.begin();it!=scene_.end();++it){
        if ((*it)->getType()==0){ //Si l'objet est une balle
            (*it)->ballMovement();
        }
    }
}
