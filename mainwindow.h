#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myglwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //getters
    float getHeight();
    float getWidth();
    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);


private:
    MyGLWidget* glWidget;
    //permet la mise en forme définie par
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
