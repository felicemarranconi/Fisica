//
//  Paral.h
//  TestGL
//
//  Created by Marabese Daniele on 19/03/15.
//
//

#ifndef __TestGL__Paral__
#define __TestGL__Paral__

#include <stdio.h>
#include "Shapes.h"
#include <math.h>

class ShapeParall : public Shape {
    
public:
    
    float Verteces[8][3];
    
    float semiX;
    float semiY;
    float semiZ;
    
    ShapeParall(){
        				
    }
    
    ShapeParall(float SemiX, float SemiY, float SemiZ);
        
    int collideWithSphere(const RigidBody *r, const RigidBody *sphere, float ray, Collision *c, int MaxCollisions);
    
    int collideWithPlane(const RigidBody *r, float A, float B, float C, float D, Collision *c, int MaxCollisioni);
    
    int collideWithParall(const RigidBody *p1, const RigidBody *p2, Collision *c, int MaxCollisions);

};

#endif /* defined(__TestGL__Paral__) */

