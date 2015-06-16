//
//  Sphere.h
//  TestGL
//
//  Created by Marabese Daniele on 19/03/15.
//
//

#ifndef __TestGL__Sphere__
#define __TestGL__Sphere__

#include <stdio.h>
#include "Shapes.h"


class ShapeSphere : public Shape {
    
public:
    
    float ray;
    
    ShapeSphere(){
    }
    
    ShapeSphere(float R)
    {   ray = R;
    }
    
    int collideWithPlane(const RigidBody *r, float A, float B, float C, float D, Collision *c, int MaxCollisions);
    
    int collideWithSphere(const RigidBody *s1, const float r1, const RigidBody *s2, const float r2, Collision* c, int maxc);
    
};

#endif /* defined(__TestGL__Sphere__) */

