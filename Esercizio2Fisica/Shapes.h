//
//  Shapes.h
//  TestGL
//
//  Created by Marabese Daniele on 16/03/15.
//
//

#ifndef __TestGL__Shapes__
#define __TestGL__Shapes__

#include <stdio.h>
#include "Matrici.h"
#include "RigidBody.h"
#include "Collision.h"

class Shape {
    
public:
    
    virtual int collideWithPlane(const RigidBody *r, float A, float B, float C, float D, Collision *c, int MaxCollisioni) = 0;
};

#endif /* defined(__TestGL__Shapes__) */


