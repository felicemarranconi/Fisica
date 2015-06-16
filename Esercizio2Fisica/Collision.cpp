//
//  Collision.cpp
//  TestGL
//
//  Created by Marabese Daniele on 16/03/15.
//
//

#include "Collision.h"
#include "Matrici.h"
#include "RigidBody.h"
#include "PhysicEngine.h"

    // c2 collida on c1
    
void Collision:: applyCollisionForce(RigidBody *c1, RigidBody *c2, float K, float L, float m)
{
        float f;
        float vn;
        float modVtang;
        float Vtang[3];
        float Ftang[3];
        float Fnorm[3];
        
        vn = ProdottoScalare(inpactVelocity, normalVector);
        MoltiplicaVettoreScalare(normalVector, vn, Vtang);
        SottraiVettori(inpactVelocity, Vtang, Vtang);
        
        f = (K * deformation) + (L * vn);
        if(f < 0) f = 0;
        MoltiplicaVettoreScalare(normalVector, f, Fnorm);
        
        f *= m;		// forza attrito (modulo)
        modVtang = ModuloVettore(Vtang);
        MoltiplicaVettoreScalare(Vtang, f, Ftang);
        
        if(modVtang > 9.8f * DT) DividiVettoreScalare(Ftang, modVtang, Ftang);
        else DividiVettoreScalare(Ftang, 9.8f * DT, Ftang);
        
        SommaVettori(Fnorm, Ftang, Fnorm);	// ora Fnorm e' la F totale
        
        if(c1 != NULL) c1->applyForce(Fnorm, inpactPoint);
        Fnorm[0] = -Fnorm[0];
        Fnorm[1] = -Fnorm[1];
        Fnorm[2] = -Fnorm[2];
        if(c2 != NULL) c2->applyForce(Fnorm, inpactPoint);
}
