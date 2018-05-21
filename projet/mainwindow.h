#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myglwidget.h"
#include "dialog.h"
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

//signals:
    //void on_Dialog_clicked(); //Emit quand on clique sur le bouton "webcam"
private slots:
    void camera();


private:
    MyGLWidget* glWidget;
    //permet la mise en forme définie par
    Ui::MainWindow *ui;
    Dialog *dialog;
    QTimer *timer;

};

#endif // MAINWINDOW_H
