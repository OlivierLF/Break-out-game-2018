#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include <iostream>
#include <GL/glu.h>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1000;
const unsigned int WIN_HEIGHT = 800;

bool oneBallTest = true;
bool justWonTest= false;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    //Initialisation du score à zéro
    score_=0;
    //Initialisation de la vie à 3
    life_=3;

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

    //Initialisation des la scène
    init();
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
        glOrtho(-11,44.8,-35,11,-100,100);

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
            if (!obj->getBallMovementTest()){
                renderText(12,-14.0,0,"Appuyer sur Espace pour démarrer");
            }
            if (justWonTest && !obj->getBallMovementTest()){
                renderText(14,-12.0,0,"Vous avez gagné !");
            }
            std::vector<Object*>::iterator it1;
            if(!obj->getBallMovementTest()){ //Fait en sorte d'avoir la balle collée au palet avant de la lancer
                for (it1=scene_.begin();it1!=scene_.end();++it1){
                    if ((*it1)->getType()== 2){ //la balle tombe à côté du palet
                        obj->setX((*it1)->getX()+2.5);
                        obj->setY((*it1)->getY()+1.5);
                    }
                }
            }


            //Gestion de la collision avec les murs
            if (obj->getY()>-0.5){ //mur du haut
                obj->changeDirectY();
            }
            if (obj->getX()<0.5){ //mur de gauche
                obj->changeDirectX();
            }
            if (obj->getX()>33.3){ //mur de droite
                obj->changeDirectX();
            }
            if (obj->getY()<-23.5){ //correspond à la balle qui tombe sur le mur inférieur
                std::vector<Object*>::iterator ite;
                bool endTest=false;
                ite=scene_.begin();
                while (ite!=scene_.end() && !endTest){
                    if ((*ite)->getType()== 2){
                        obj->setX((*ite)->getX()+2.5);
                        obj->setY((*ite)->getY()+1.5);
                        obj->ballMovement();
                        life_-=1;
                        if (life_==-1){ //redemarre le jeu si on a perdu nos 3 chances
                            restart();
                            endTest=true;
                        }
                    }
                    ++ite;
                }

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
                        winTest();
                    }
                    // la balle tape au dessus de la brique
                    if (obj->getY()>=(*it)->getY()+0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX() && obj->getX()<=(*it)->getX()+3.0 ){
                        obj->changeDirectY();
                        scene_.erase(it);
                        score_+=1;
                        winTest();
                    }
                    //la balle tape sur le côté gauche de la brique
                    if (obj->getY()>=(*it)->getY()-0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX()-0.5 && obj->getX()<=(*it)->getX()){
                        obj->changeDirectX();
                        scene_.erase(it);
                        score_+=1;
                        winTest();
                    }
                    //la balle tape sur le côté droit de la brique
                    if (obj->getY()>=(*it)->getY()-0.5 && obj->getY()<=(*it)->getY()+1.5
                            && obj->getX()>=(*it)->getX()+3.0 && obj->getX()<=(*it)->getX()+3.5){
                        obj->changeDirectX();
                        scene_.erase(it);
                        score_+=1;
                        winTest();
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
        renderText(1,-21,0,"Score : "+scoreText);
        QString lifeText = QString::number(life_);
        renderText(29.8,-21,0,"Vie : "+lifeText);
        renderText(1,-23, 0,"Entrée = Nouvelle partie");
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
                (*it)->setX((*it)->getX()-1.1);
            }

        }
    }
}

void MyGLWidget::moveRight(){
    std::vector<Object*>::iterator it;
    for (it=scene_.begin();it!=scene_.end();++it){
        if ((*it)->getType()==2){ //Si l'objet est un palet
            //Condition pour ne pas faire sortir le palet de la partie jouable
            if ((*it)->getX() <29){ //largeur (33.8) - taille du palet (5) = 28.8
                (*it)->setX((*it)->getX()+1.1);
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

void MyGLWidget::init(){

    score_=0;
    life_=3;

    //Déclaration des murs
    Wall* top = new Wall(-10.0,0.0,false);
    Wall* bot = new Wall(-10.0,-34.0,false);
    Wall* left = new Wall(-10.0,-24.0,true);
    Wall* right = new Wall(33.8,-24.0,true);

    //Ajout des murs aux éléments de la scène
    scene_.push_back(top);
    scene_.push_back(bot);
    scene_.push_back(left);
    scene_.push_back(right);

    //Ajout des briques dans la scène
    float x=1;
    while (x<=32){
        float y=-2;
        while (y>=-10){
            scene_.push_back(new Brick(x,y));
            y=y-2;
        }
        x=x+3.2;
    }

    //Déclaration et ajout du palet à la scène

    scene_.push_back(new Puck(20,-22));

    //Déclaration et ajout de la balle à la scène
    scene_.push_back(new Ball(21.5, -20.5, 0.5,255,255,0));
}

void MyGLWidget::restart(){
    cleanScene();
    init();
}

void MyGLWidget::cleanScene(){
    while (!scene_.empty()){
        scene_.pop_back();
    }
}


void MyGLWidget::winTest(){
    if (score_==50){
        restart();
        justWonTest= true;
    }


}
