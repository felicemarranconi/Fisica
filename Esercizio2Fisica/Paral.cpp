//
//  Paral.cpp
//  TestGL
//
//  Created by Marabese Daniele on 19/03/15.
//
//

#include "Paral.h"

ShapeParall::ShapeParall(float SemiX, float SemiY, float SemiZ):semiX(SemiX),semiY(SemiY),semiZ(SemiZ)
{
    Verteces[2][0] = Verteces[3][0] = Verteces[6][0] = Verteces[7][0] = SemiX;
    Verteces[0][0] = Verteces[1][0] = Verteces[4][0] = Verteces[5][0] = -SemiX;
    Verteces[1][1] = Verteces[2][1] = Verteces[5][1] = Verteces[6][1] = SemiY;
    Verteces[0][1] = Verteces[3][1] = Verteces[4][1] = Verteces[7][1] = -SemiY;
    Verteces[0][2] = Verteces[1][2] = Verteces[2][2] = Verteces[3][2] = SemiZ;
    Verteces[4][2] = Verteces[5][2] = Verteces[6][2] = Verteces[7][2] = -SemiZ;
}

int ShapeParall::collideWithSphere(const RigidBody *r, const RigidBody *sphere, float ray,
                    Collision *c, int MaxCollisions)
{
    float d;
    float Temp[3];
    
    // portiamo le coord della sfera relative al paral
    SottraiVettori(sphere->Pos, r->Pos, c[0].inpactPoint);
    RuotaRelative(r->MRot, c[0].inpactPoint, c[0].inpactPoint);
    
    if(c[0].inpactPoint[0] > Verteces[2][0]) c[0].inpactPoint[0] = Verteces[2][0];
    if(c[0].inpactPoint[0] < Verteces[0][0]) c[0].inpactPoint[0] = Verteces[0][0];
    if(c[0].inpactPoint[1] > Verteces[1][1]) c[0].inpactPoint[1] = Verteces[1][1];
    if(c[0].inpactPoint[1] < Verteces[0][1]) c[0].inpactPoint[1] = Verteces[0][1];
    if(c[0].inpactPoint[2] > Verteces[0][2]) c[0].inpactPoint[2] = Verteces[0][2];
    if(c[0].inpactPoint[2] < Verteces[4][2]) c[0].inpactPoint[2] = Verteces[4][2];
    
    // trovato il punto relativo d'impatto, rendiamolo assoluto
    RuotaAssolute(r->MRot, c[0].inpactPoint, c[0].inpactPoint);
    SommaVettori(r->Pos, c[0].inpactPoint, c[0].inpactPoint);
    
    // direzione e distanza (dalla Sfera verso il paral)
    SottraiVettori(c[0].inpactPoint, sphere->Pos, c[0].normalVector);
    d = ModuloVettore(c[0].normalVector);
    if(d > ray) return(0);
    
    c[0].deformation = ray - d;
    DividiVettoreScalare(c[0].normalVector, d, c[0].normalVector);
    
    // la vel di impatto e' la diff tra la vel della sfera e quella del parall
    SottraiVettori(c[0].inpactPoint, sphere->Pos, c[0].inpactVelocity);
    ProdottoVettoriale(sphere->Vang, c[0].inpactVelocity, c[0].inpactVelocity);
    SommaVettori(sphere->Vel, c[0].inpactVelocity, c[0].inpactVelocity);
    
    SottraiVettori(c[0].inpactPoint, r->Pos, Temp);
    ProdottoVettoriale(r->Vang, Temp, Temp);
    SommaVettori(r->Vel, Temp, Temp);
    
    SottraiVettori(c[0].inpactVelocity, Temp, c[0].inpactVelocity);
    
    return(1);
}

int ShapeParall::collideWithParall(const RigidBody *p1, const RigidBody *p2, Collision *c, int MaxCollisions)
{
    float d1;
    
    float Temp[3];
    
    // portiamo le coord del paral2 relative al paral1
    SottraiVettori(p2->Pos, p1->Pos, c[0].inpactPoint);
    RuotaRelative(p1->MRot, c[0].inpactPoint, c[0].inpactPoint);
    
    if(c[0].inpactPoint[0] > Verteces[2][0]) c[0].inpactPoint[0] = Verteces[2][0];
    if(c[0].inpactPoint[0] < Verteces[0][0]) c[0].inpactPoint[0] = Verteces[0][0];
    if(c[0].inpactPoint[1] > Verteces[1][1]) c[0].inpactPoint[1] = Verteces[1][1];
    if(c[0].inpactPoint[1] < Verteces[0][1]) c[0].inpactPoint[1] = Verteces[0][1];
    if(c[0].inpactPoint[2] > Verteces[0][2]) c[0].inpactPoint[2] = Verteces[0][2];
    if(c[0].inpactPoint[2] < Verteces[4][2]) c[0].inpactPoint[2] = Verteces[4][2];
    
    // trovato il punto relativo d'impatto, rendiamolo assoluto
    RuotaAssolute(p1->MRot, c[0].inpactPoint, c[0].inpactPoint);
    SommaVettori(p1->Pos, c[0].inpactPoint, c[0].inpactPoint);
    
    // direzione e distanza (dal paral2 verso il paral1)
    SottraiVettori(c[0].inpactPoint, p2->Pos, c[0].normalVector);
    
    d1 = ModuloVettore(c[0].normalVector);
    
    float media = sqrt(2*semiX*semiX + 2*semiY*semiY + 2*semiZ*semiZ)/2;
    if(d1 > media) return(0);
    
    c[0].deformation = media - d1;
    DividiVettoreScalare(c[0].normalVector, d1, c[0].normalVector);
    
    // la vel di impatto e' la diff tra la vel del paral1 e quella del parall2
    SottraiVettori(c[0].inpactPoint, p2->Pos, c[0].inpactVelocity);
    ProdottoVettoriale(p2->Vang, c[0].inpactVelocity, c[0].inpactVelocity);
    SommaVettori(p2->Vel, c[0].inpactVelocity, c[0].inpactVelocity);
    
    SottraiVettori(c[0].inpactPoint, p1->Pos, Temp);
    ProdottoVettoriale(p1->Vang, Temp, Temp);
    SommaVettori(p1->Vel, Temp, Temp);
    
    SottraiVettori(c[0].inpactVelocity, Temp, c[0].inpactVelocity);
    
    return(1);
}

int ShapeParall::collideWithPlane(const RigidBody *r, float A, float B, float C, float D,
                    Collision *c, int MaxCollisioni)
{
    int i;
    int n = 0;
    
    for(i = 0;i < MaxCollisioni; i++) {
        RuotaAssolute(r->MRot, Verteces[i], c[n].inpactPoint);
        ProdottoVettoriale(r->Vang, c[n].inpactPoint, c[n].inpactVelocity);
        SommaVettori(r->Pos, c[n].inpactPoint, c[n].inpactPoint);
        SommaVettori(r->Vel, c[n].inpactVelocity, c[n].inpactVelocity);
        
        c[n].deformation = -(A * c[n].inpactPoint[0] + B * c[n].inpactPoint[1] + C * c[n].inpactPoint[2] + D);
        if(c[n].deformation < 0) continue;
        
        c[n].normalVector[0] = A;
        c[n].normalVector[1] = B;
        c[n].normalVector[2] = C;
        
        c[n].inpactVelocity[0] = -c[n].inpactVelocity[0];
        c[n].inpactVelocity[1] = -c[n].inpactVelocity[1];
        c[n].inpactVelocity[2] = -c[n].inpactVelocity[2];
        
        n++;
        if(n == MaxCollisioni) break;
    }
    
    return(n);
}
