//
//  RigidBody.cpp
//  TestGL
//
//  Created by Marabese Daniele on 16/03/15.
//
//

#include "RigidBody.h"

void RigidBody:: applyForce(const float *force, const float *applicationPoint)
{
        float b[3];
        
        SommaVettori(force, Fris, Fris);
        SottraiVettori(applicationPoint, Pos, b);
        ProdottoVettoriale(b, force, b);
        SommaVettori(b, Mris, Mris);
}
    
void RigidBody:: updateState(float dt)
{
    float v[3];
    float q[4];
    float A[3];
    
    DividiVettoreScalare(Fris, Weight, A);
    
    MoltiplicaVettoreScalare(A, dt, A);
    SommaVettori(Vin, A, Vin);
    MoltiplicaVettoreScalare(Vin, dt, A);
    
    
    MoltiplicaVettoreScalare(Fris, dt, v);
    SommaVettori(v, Qmoto, Qmoto);
    MoltiplicaVettoreScalare(Mris, dt, v);
    SommaVettori(v, Mang, Mang);
        
    DividiVettoreScalare(Qmoto, Weight, Vel);
    MoltiplicaVettoreScalare(Vel, dt, v);
    
    SommaVettori(A, v, v);
    
    SommaVettori(v, Pos, Pos);
        
    RuotaRelative(MRot, Mang, Vang);
    Vang[0] /= Inertia[0];
    Vang[1] /= Inertia[1];
    Vang[2] /= Inertia[2];		// v = vang
    q[0] = 1;
    q[1] = Vang[0] * dt / 2;
    q[2] = Vang[1] * dt / 2;
    q[3] = Vang[2] * dt / 2;
    NormalizzaQuaternione(q, q);
    MoltiplicaQuaternioni(Rot, q, Rot);
    NormalizzaQuaternione(Rot, Rot);
        
    RuotaAssolute(MRot, Vang, Vang);
    MatriceDaQuaternione(Rot, MRot);
}
