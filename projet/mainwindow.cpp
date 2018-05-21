#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog();
    timer = new QTimer();
    timer->start(10);
    connect (timer,SIGNAL(timeout()),this,SLOT(camera()));
    connect(timer, SIGNAL(on_Pause_clicked()),this, SLOT(on_Pause_clicked()));


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
    case Qt::Key_D:
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
void MainWindow::camera(){
    Mat frameToUpdate;
    QImage image ;
    frameToUpdate=dialog->processFrameAndUpdateGUI();
    image = QImage((const unsigned char*) (frameToUpdate.data), frameToUpdate.cols, frameToUpdate.rows,frameToUpdate.step, QImage::Format_RGB888);
    QImage size = image.scaled(ui->camera->width(),ui->camera->height(),Qt::KeepAspectRatio);
    ui->camera->setPixmap(QPixmap::fromImage(size));

    bool test = dialog->getMoveRight();
    if (test){
        std::cout<<"mouvement a droite"<<std::endl;
        ui->glWidget->moveRight();
    }
    else{
        std::cout<<"mouvement a gauche"<<std::endl;
        ui->glWidget->moveLeft();
    }

}

void MainWindow::on_Pause_clicked()
{
    if(timer->isActive() == true){
        timer->stop();
        ui->Pause->setText("relancer");

    }else{
        timer->start(20);
        ui->Pause->setText("pause");

    }

}
