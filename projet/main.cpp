#include <QApplication>
#include <ctime>
#include "myglwidget.h"
#include "mainwindow.h"
#include "dialog.h"


int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
    srand(time(nullptr));

    // Creation de l'application QT
    QApplication app(argc, argv);
	
    //Déclaration de la fenêtre principale
    MainWindow myWindow;
    myWindow.show();

    Dialog w;
    w.show();

    // Execution de l'application QT
    return app.exec();
}
