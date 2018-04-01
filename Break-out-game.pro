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
    puck.cpp
HEADERS += \
    object.h \
    brick.h \
    ball.h \
    myglwidget.h \
    wall.h \
    mainwindow.h \
    puck.h

RESOURCES += \
    textures.qrc

FORMS += \
    mainwindow.ui
