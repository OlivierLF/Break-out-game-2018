#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(on_Dialog_clicked()), ui->glWidget, SLOT(interactionDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::getHeight(){
    return this->height();
}

float MainWindow::getWidth(){
    return this->width();
}

// Fonction de gestion d'interactions clavier
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    //std::cout << event->key()<<std::endl;
    switch(event->key())
    {
    // Activation/Arret de l'animation de la balle
    case Qt::Key_Space:
    {
        ui->glWidget->changeBallMovement();
        break;
    }
    case 16777220:
    {
        ui->glWidget->restart();
        break;
    }
    case 16777234: //Flèche gauche
    {
        ui->glWidget->moveLeft();
        break;
    }
    case 16777236: //Flèche droite
    {
        ui->glWidget->moveRight();
        break;
    }

        // Sortie de l'application
    case Qt::Key_Escape:
    {
        exit(0);
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

}
