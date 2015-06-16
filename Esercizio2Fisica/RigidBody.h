//
//  RigidBody.h
//  TestGL
//
//  Created by Marabese Daniele on 16/03/15.
//
//

#ifndef __TestGL__RigidBody__
#define __TestGL__RigidBody__


#include <stdio.h>
#include "Matrici.h"


class RigidBody {

public:

    float K;    // costante elastica
    float L;    // costante viscosa
    float Weight;
    float Inertia[3];
    float Pos[3];
    float Rot[4];
    float Vel[3];
    float Vin[3];
    float Vang[3];
    float Qmoto[3];
    float Mang[3];
    float MRot[9];
    float Fris[3];
    float Mris[3];
    
    void applyForce(const float *force, const float *applicationPoint);
    void updateState(float dt);
};

#endif

