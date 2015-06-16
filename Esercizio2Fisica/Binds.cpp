//
//  Binds.cpp
//  TestGL
//
//  Created by Marabese Daniele on 17/03/15.
//
//

#include "Binds.h"

void Bind:: applyBindingForce(RigidBody *c1, RigidBody *c2, float K, float L)
{
    float p1[3];
    float p2[3];
    float v1[3];
    float v2[3];
    float f[3];
    
    // troviamo come sempre posizioni e velocita' assolute
    RuotaAssolute(c1->MRot, PosRel1, p1);
    RuotaAssolute(c2->MRot, PosRel2, p2);
    ProdottoVettoriale(c1->Vang, p1, v1);
    ProdottoVettoriale(c2->Vang, p2, v2);
    SommaVettori(c1->Pos, p1, p1);
    SommaVettori(c2->Pos, p2, p2);
    SommaVettori(c1->Vel, v1, v1);
    SommaVettori(c2->Vel, v2, v2);
    
    f[0] = K * (p2[0] - p1[0]) + L * (v2[0] - v1[0]);
    f[1] = K * (p2[1] - p1[1]) + L * (v2[1] - v1[1]);
    f[2] = K * (p2[2] - p1[2]) + L * (v2[2] - v1[2]);
    
    c1->applyForce(f, p1);
    f[0] = -f[0];
    f[1] = -f[1];
    f[2] = -f[2];
    c2->applyForce(f, p2);
}
