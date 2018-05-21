#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <vector>
#include <QKeyEvent>
#include <QTimer>
#include "ball.h"
#include "puck.h"
#include "object.h"
#include "brick.h"
#include "wall.h"
#include <GL/glu.h>



// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    //récupère la scène
    std::vector<Object*> getScene(){return scene_;}

    //Mouvement du palet vers la gauche
    void puckMovement(int dir);
    //Activer mouvement ou non de la balle
    void changeBallMovement();
    //Initialise la scène
    void init();
    //Réinitialise la scène
    void restart();
    //Nettoie la scene de tous ses éléments
    void cleanScene();
    //Test pour savoir si le joueur a gagné.
    void winTest();


protected:

    // Fonction d'initialisation
    void initializeGL();
    // Fonction de redimensionnement
    void resizeGL(int width, int height);
    // Fonction d'affichage
    void paintGL();
    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

private:
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;

    //paramètre de la partie
    int score_;
    int life_;

    //vecteur qui contient les éléments de la scène
    std::vector<Object*> scene_;
    //std::vector<puck*> move_puck;

};

#endif // MYGLWIDGET_H
