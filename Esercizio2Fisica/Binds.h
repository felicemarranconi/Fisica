//
//  Binds.h
//  TestGL
//
//  Created by Marabese Daniele on 17/03/15.
//
//

#ifndef __TestGL__Binds__
#define __TestGL__Binds__

#include <stdio.h>
#include "RigidBody.h"


class Bind {
    
public:
    
    float K;
    float L;
    
    float PosRel1[3];
    float PosRel2[3];
    
    RigidBody* c1;
    RigidBody* c2;
    
    void applyBindingForce(RigidBody *c1, RigidBody *c2, float K, float L);
};

#endif /* defined(__TestGL__Binds__) */


