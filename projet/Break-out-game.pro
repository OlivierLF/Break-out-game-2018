#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T09:00:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTracker
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH +=C:\build\opencv2\include
          # $$(OPENCV_DIR)\..\..\include\
INCLUDEPATH+=D:\opencv-2.4.13.5\build\install/include

LIBS += -LD:\opencv-2.4.13.5\build\install\x86\mingw\lib\
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413 \
    -lopencv_video2413



# configuration Qt
QT       += core gui opengl widgets
CONFIG	 += c++14
TEMPLATE  = app


# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
unix {
        LIBS     += -lGL -lGLU
}


# nom de l'exe genere
TARGET 	  = Break-out-game

# fichiers sources/headers/ressources
SOURCES += main.cpp \
    object.cpp \
    brick.cpp \
    ball.cpp \
    myglwidget.cpp \
    wall.cpp \
    mainwindow.cpp \
    puck.cpp \
    dialog.cpp
HEADERS += \
    object.h \
    brick.h \
    ball.h \
    myglwidget.h \
    wall.h \
    mainwindow.h \
    puck.h \
    dialog.h

RESOURCES += \
    textures.qrc

FORMS += \
    mainwindow.ui \
    dialog.ui
