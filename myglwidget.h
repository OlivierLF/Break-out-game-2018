#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <vector>
#include <QKeyEvent>
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
    std::vector<Ball*> balls_;
    std::vector<Brick*> bricks_;
    Puck* myPuck_;
    std::vector <Wall*> walls_;
    std::vector<Object*> scene_;

};

#endif // MYGLWIDGET_H
