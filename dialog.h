#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <opencv2\opencv.hpp>
#include <opencv2\video\tracking.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>


#include <cstdio>
#include <iostream>
using namespace cv;
using namespace std;



class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog();
    ~Dialog();



private:

    int frameWidth;
    int frameHeight;
    int subImageWidth;
    int subImageHeight;
    int templateWidth;
    int templateHeight;

    Mat frame1,frame2,frameRect1,frameRect2;



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
