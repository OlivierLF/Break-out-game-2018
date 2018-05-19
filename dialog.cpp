#include "dialog.h"

#include <QTime>
#include <QtCore>
#include "opencv2\video\tracking.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\highgui\highgui.hpp"
#include <QDebug>

#include <cstdio>
#include <iostream>
using namespace cv;
using namespace std;

Dialog::Dialog() :
    QDialog()

{

    capwebcam.open(0);
    //capwebcam.read(frame1);

    tmrTimer = new QTimer(this);
    connect(tmrTimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));
    tmrTimer->start(20);
    frameWidth=320;
    frameHeight=240;
    subImageWidth=100;
    subImageHeight=100;
    templateWidth=25;
    templateHeight=25;



}

Dialog::~Dialog()
{

}
void Dialog::processFrameAndUpdateGUI(){
    Rect workingRect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    Rect templateRect((workingRect.width-templateWidth)/2,(workingRect.height-templateHeight)/2,templateWidth,templateHeight);
    Point workingCenter(workingRect.x+subImageWidth/2,workingRect.y+subImageHeight/2);

    capwebcam.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth);
    capwebcam.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight);
    capwebcam.read(frame1);

    cv::flip(frame1,frame1,1);
    // Extract rect1 and convert to gray
    cv::cvtColor(Mat(frame1,workingRect),frameRect1,COLOR_BGR2GRAY);
    //Mat(frame1,rect).copyTo(frameRect1);

    // Create the matchTemplate image result
    Mat resultImage;    // to store the matchTemplate result
    int result_cols =  frame1.cols-templateWidth  + 1;
    int result_rows = frame1.rows-templateHeight + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );

        // Get frame2
        capwebcam.read(frame2);
        //cap >> frame2;
        // Mirror effect
        cv::flip(frame2,frame2,1);
        // Extract working rect in frame2 and convert to gray
        cv::cvtColor(Mat(frame2,workingRect),frameRect2,COLOR_BGR2GRAY);

        // Extract template image in frame1
        Mat templateImage(frameRect1,templateRect);
        // Do the Matching between the working rect in frame2 and the templateImage in frame1
        matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
        // Localize the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
        // Compute the translation vector between the origin and the matching rect
        Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y);

        // Draw green rectangle and the translation vector
        rectangle(frame2,workingRect,Scalar( 0, 255, 0),2);
        Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
        arrowedLine(frame2,workingCenter,p,Scalar(255,255,255),2);
        if(vect.x>1){
            qDebug()<<"droite";
        }
        if(vect.x<-1){

            qDebug()<<"gauche";
        }

        // Display frame2
        //imshow("WebCam2", frame2);
        QImage qimgOriginal((uchar*)frame2.data,frame2.cols,frame2.rows,frame2.step,QImage::Format_RGB888);
        // Swap matrixes
        swap(frameRect1,frameRect2);
        cvtColor(frame2, frame2, CV_BGR2RGB);



}
void Dialog::on_btnPauseOrResume_clicked()
{
    if(tmrTimer->isActive() == true){
        tmrTimer->stop();

    }else{
        tmrTimer->start(20);

    }

}
