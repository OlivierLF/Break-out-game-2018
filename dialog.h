#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <opencv2\opencv.hpp>
#include <opencv2\video\tracking.hpp>
#include <opencv2\imgproc.hpp>
#include <C:\opencv-2.4.13.5\opencv-2.4.13.5\build\install\include\opencv2\highgui\highgui.hpp>


#include <cstdio>
#include <iostream>
using namespace cv;
using namespace std;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();



private:

    int frameWidth;
    int frameHeight;
    int subImageWidth;
    int subImageHeight;
    int templateWidth;
    int templateHeight;

    Mat frame1,frame2,frameRect1,frameRect2;



    Ui::Dialog *ui;

    cv::VideoCapture capwebcam;
    cv::Mat matOriginal;
    cv::Mat matProcess;


    QImage qimgOriginal;
    QImage qimgProcess;

    std::vector<cv::Vec3f>VecCircles;
    std::vector<cv::Vec3f>::iterator itrCircles;

    QTimer* tmrTimer;

 public slots:
    void processFrameAndUpdateGUI();



 private slots:
    void on_btnPauseOrResume_clicked();



};

#endif // DIALOG_H
