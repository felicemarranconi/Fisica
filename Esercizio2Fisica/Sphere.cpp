//
//  Sphere.cpp
//  TestGL
//
//  Created by Marabese Daniele on 19/03/15.
//
//

#include "Sphere.h"

int ShapeSphere::collideWithPlane(const RigidBody *r, float A, float B, float C, float D,
                    Collision *c, int MaxCollisions)
{
    // troviamo il punto di contatto della sfera verso il piano
    c[0].inpactPoint[0] = -A;
    c[0].inpactPoint[1] = -B;
    c[0].inpactPoint[2] = -C;
    MoltiplicaVettoreScalare(c[0].inpactPoint, this->ray, c[0].inpactPoint);
    
    ProdottoVettoriale(r->Vang, c[0].inpactPoint, c[0].inpactVelocity);
    SommaVettori(r->Pos, c[0].inpactPoint, c[0].inpactPoint);
    SommaVettori(r->Vel, c[0].inpactVelocity, c[0].inpactVelocity);
    
    c[0].deformation = -(A * c[0].inpactPoint[0] + B * c[0].inpactPoint[1] + C * c[0].inpactPoint[2] + D);
    if(c[0].deformation < 0) return(0);
    
    c[0].normalVector[0] = A;
    c[0].normalVector[1] = B;
    c[0].normalVector[2] = C;
    
    c[0].inpactVelocity[0] = -c[0].inpactVelocity[0];
    c[0].inpactVelocity[1] = -c[0].inpactVelocity[1];
    c[0].inpactVelocity[2] = -c[0].inpactVelocity[2];
    
    return(1);
}

int ShapeSphere::collideWithSphere(const RigidBody *s1, const float r1, const RigidBody *s2, const float r2, Collision *c, int maxc)
{
    float d;
    float Temp[3];
    
    // portiamo le coord della sfera relative al paral
    SottraiVettori(s2->Pos, s1->Pos, c[0].inpactPoint);
    RuotaRelative(s1->MRot, c[0].inpactPoint, c[0].inpactPoint);
    
    if(c[0].inpactPoint[0] > r1)
        c[0].inpactPoint[0] = r1;
    if(c[0].inpactPoint[0] < -r1)
        c[0].inpactPoint[0] = -r1;
    if(c[0].inpactPoint[1] > r1)
        c[0].inpactPoint[1] = r1;
    if(c[0].inpactPoint[1] < -r1)
        c[0].inpactPoint[1] = -r1;
    if(c[0].inpactPoint[2] > r1)
        c[0].inpactPoint[2] = r1;
    if(c[0].inpactPoint[2] < -r1)
        c[0].inpactPoint[2] = -r1;
    
    // trovato il punto relativo d'impatto, rendiamolo assoluto
    RuotaAssolute(s1->MRot, c[0].inpactPoint, c[0].inpactPoint);
    SommaVettori(s1->Pos, c[0].inpactPoint, c[0].inpactPoint);
    
    // direzione e distanza (dalla Sfera verso il paral)
    SottraiVettori(c[0].inpactPoint, s2->Pos, c[0].normalVector);
    d = ModuloVettore(c[0].normalVector);
    if(d > r2) return(0);
    
    c[0].deformation = r2 - d;
    DividiVettoreScalare(c[0].normalVector, d, c[0].normalVector);
    
    // la vel di impatto e' la diff tra la vel della sfera e quella del parall
    SottraiVettori(c[0].inpactPoint, s2->Pos, c[0].inpactVelocity);
    ProdottoVettoriale(s2->Vang, c[0].inpactVelocity, c[0].inpactVelocity);
    SommaVettori(s2->Vel, c[0].inpactVelocity, c[0].inpactVelocity);
    
    SottraiVettori(c[0].inpactPoint, s1->Pos, Temp);
    ProdottoVettoriale(s1->Vang, Temp, Temp);
    SommaVettori(s1->Vel, Temp, Temp);
    
    SottraiVettori(c[0].inpactVelocity, Temp, c[0].inpactVelocity);
    
    return(1);
};

