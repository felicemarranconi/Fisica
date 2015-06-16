//
//  Collision.h
//  TestGL
//
//  Created by Marabese Daniele on 16/03/15.
//
//

#ifndef __TestGL__Collision__
#define __TestGL__Collision__

#include <stdio.h>
#include "RigidBody.h"

class Collision {
    
public:
    
    float deformation;
    float inpactPoint[3];
    float normalVector[3];
    float inpactVelocity[3];
    
    // c2 collide on c1
    
    void applyCollisionForce(RigidBody *c1, RigidBody *c2,
                        float K, float L, float m);
};

#endif /* defined(__TestGL__Collision__) */

