#include <QApplication>
#include <ctime>
#include "myglwidget.h"
#include "mainwindow.h"
#include "interfacecam.h"


int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
    srand(time(nullptr));

    // Creation de l'application QT
    QApplication app(argc, argv);
	
    //Déclaration de la fenêtre principale
    MainWindow myWindow;
    myWindow.show();


    // Execution de l'application QT
    return app.exec();
}
