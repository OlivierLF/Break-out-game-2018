#include <QApplication>
#include <ctime>
#include "myglwidget.h"
#include "mainwindow.h"
#include "game.h"

int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
    srand(time(nullptr));

    // Creation de l'application QT
    QApplication app(argc, argv);
	
	// Creation du widget opengl
    //MyGLWidget glWidget;
    //glWidget.show();

    MainWindow myWindow;
    myWindow.show();


    // Creation du jeu
    //Game myGame;

    // Execution de l'application QT
    return app.exec();
}
