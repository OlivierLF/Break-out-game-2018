#ifndef INTERFACECAM_H
#define INTERFACECAM_H

#include <QDialog>
#include <opencv2\opencv.hpp>
#include <opencv2\video\tracking.hpp>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


#include <cstdio>
#include <iostream>
using namespace cv;
using namespace std;



class Interfacecam : public QDialog // classe affichant la caméra et la zone de captation de la main
{
    Q_OBJECT

public:
    explicit Interfacecam();
    ~Interfacecam();
    int move_;
    int getMove(){return move_;}


private:
    // largeur de la frame
    int frameWidth;
    // hateur de la frame
    int frameHeight;
    int subImageWidth;
    int subImageHeight;
    int templateWidth;
    int templateHeight;
    // définition des matrices des différentes frames et rectangles
    Mat frame1,frame2,frameRect1,frameRect2;

    // permet de capturer des données vidéo à partir de séquences ou images
    cv::VideoCapture capture;
    cv::Mat matOriginal;
    cv::Mat matProcess;

    // accéder aux données pixels
    QImage qimgOriginal;
    QImage qimgProcess;

    std::vector<cv::Vec3f>VectorCircles;
    std::vector<cv::Vec3f>::iterator itrCircles;
    //timer
    QTimer* tmrTimer;

 public slots:
    Mat framesInterface();

};

#endif // INTERFACECAM_H
