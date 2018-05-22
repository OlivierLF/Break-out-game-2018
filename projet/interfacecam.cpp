#include "interfacecam.h"
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

// définition du constructeur de la classe permettant l'affichage des éléments vidéo
Interfacecam::Interfacecam() {
    //on initialise la palet sans mouvement
    move_=0;
    // initialisation de la caméra
    capture.open(0);

    // définition du timer
    tmrTimer = new QTimer(this);
    //moment auquel le timer démarre
    tmrTimer->start(20);
    // dimensions des frames
    frameWidth=320;
    frameHeight=240;
    subImageWidth=100;
    subImageHeight=100;
    templateWidth=25;
    templateHeight=25;

}
// destructeur
Interfacecam::~Interfacecam()
{
}

// type matrice dans lequel sont implémentés les éléments permettant l'affichage de la caméra
Mat Interfacecam::framesInterface(){
    Rect myRect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    Rect templateRect((myRect.width-templateWidth)/2,(myRect.height-templateHeight)/2,templateWidth,templateHeight);
    Point workingCenter(myRect.x+subImageWidth/2,myRect.y+subImageHeight/2);

    capture.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight);
    capture.read(frame1);

    cv::flip(frame1,frame1,1);
    // Extrait le rectange 1 et le convertit en gray
    cv::cvtColor(Mat(frame1,myRect),frameRect1,COLOR_BGR2GRAY);
    //Mat(frame1,rect).copyTo(frameRect1);

    // Crée une correspondance avec l'image de résultat
    Mat image_de_resultat;    // pour stocker le résultat
    int resultat_col =  frame1.cols-templateWidth  + 1; // résultat sur les colonnes de la matrice finale
    int result_rows = frame1.rows-templateHeight + 1; // résultat sur les lignes de la matrice finale
    image_de_resultat.create( resultat_col, result_rows, CV_32FC1 );

        // Permet d'accéder à la frame 2
        capture.read(frame2);
        //cap >> frame2;

        // Effet miroir pour avoir les gestes devant la caméra du bon côté
        cv::flip(frame2,frame2,1);
        // Extraction de la zone de travail (ici un rectangle) de la frame 2 et conversion en gray
        cv::cvtColor(Mat(frame2,myRect),frameRect2,COLOR_BGR2GRAY);

        // Extraction de l'image modèle dans la frame 1
        Mat templateImage(frameRect1,templateRect);
        // Réalise la correspondance entre le rectangle de travail dans la frame 2 et l'image modèle de la frame 1
        matchTemplate( frameRect2, templateImage, image_de_resultat, TM_CCORR_NORMED );
        // Localise la meilleure correspondance entre minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( image_de_resultat, &minVal, &maxVal, &minLoc, &maxLoc);
        // Réalise la translation du vecteur entre l'origine et le correspondant
        Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y);
        // Trace le rectangle vert (zone active à la caméra) et le vecteur de déplacement selon le mouvement de la main
        rectangle(frame2,myRect,Scalar( 0, 255, 0),2);
        Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
        // récupère le mouvement afin d'afficher en sortie d'application la direction de la main
        arrowedLine(frame2,workingCenter,p,Scalar(255,255,255),2);


        if(vect.x>1){ // condition si le vecteur de déplacement est orienté vers la droite
            qDebug()<<"droite"; // affiché en sortie de l'application
            //le palet va a droite lorsque move_=2
            move_=2; // le palet se déplace à droite
        }
        if(vect.x<-1){ // condition si le vecteur de déplacement est orienté vers la droite
            //le palet va a gauche lorsque move_=1
            move_=1; // le palet se déplace à gauche
            qDebug()<<"gauche"; // affiché en sortie de l'application
        }

        if(vect.x<1 && vect.x>-1){ // condition si le vecteur de déplacement est immobile
            move_=0; // le palet reste immobile
            qDebug()<<"none"; // affiché en sortie de l'application
        }

        // Affichage frame2
        QImage qimgOriginal((uchar*)frame2.data,frame2.cols,frame2.rows,frame2.step,QImage::Format_RGB888);

        // Echange les matrices
        swap(frameRect1,frameRect2);
        cvtColor(frame2, frame2, CV_BGR2RGB);
    return frame2; // affiche la frame 2


}


