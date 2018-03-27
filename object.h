#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glu.h>

class Object
{
public:
    Object();
    virtual ~Object();
    virtual void paint();
};

#endif // OBJECT_H
