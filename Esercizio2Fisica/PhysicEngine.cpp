//
//  PhysicEngine.cpp
//  TestGL
//
//  Created by Marabese Daniele on 13/03/15.
//
//

#include "PhysicEngine.h"

void Environment::addSphere(float* pos, float* rot, float* qmoto,  float* mrot, float weight, float l, float k, float ray, float* inertia, float* vin)
{
    fSphere->push_back(ShapeSphere(ray));
    
    RigidBody r = RigidBody();
    
    r.Weight = weight;
    r.K = k;
    r.L = l;
    
    r.Inertia[0] = inertia[0];
    r.Inertia[1] = inertia[1];
    r.Inertia[2] = inertia[2];
    
    r.Rot[0] = rot[0];
    r.Rot[1] = rot[1];
    r.Rot[2] = rot[2];
    r.Rot[3] = rot[3];
    
    r.MRot[0] = mrot[0];
    r.MRot[1] = mrot[1];
    r.MRot[2] = mrot[2];
    r.MRot[3] = mrot[3];
    r.MRot[4] = mrot[4];
    r.MRot[5] = mrot[5];
    r.MRot[6] = mrot[6];
    r.MRot[7] = mrot[7];
    r.MRot[8] = mrot[8];
    
    r.Pos[0] = pos[0];
    r.Pos[1] = pos[1];
    r.Pos[2] = pos[2];
    
    r.Qmoto[0] = qmoto[0];
    r.Qmoto[1] = qmoto[1];
    r.Qmoto[2] = qmoto[2];
    
    r.Vin[0] = vin[0];
    r.Vin[1] = vin[1];
    r.Vin[2] = vin[2];
    
    rSphere->push_back(r);
    sphereNum++;
}

void Environment::addParall(float* pos, float* rot, float* mang, float* mrot, float massa, float l, float k, float semx, float semy, float semz, float* inerzia, float* vin)
{
    fParal->push_back(ShapeParall(semx, semy, semz));
    
    RigidBody r = RigidBody();
    
    r.Weight = massa;
    r.K = k;
    r.L = l;
    
    r.Inertia[0] = inerzia[0];
    r.Inertia[1] = inerzia[1];
    r.Inertia[2] = inerzia[2];
    
    r.Pos[0] = pos[0];
    r.Pos[1] = pos[1];
    r.Pos[2] = pos[2];
    
    r.Rot[0] = rot[0];
    r.Rot[1] = rot[1];
    r.Rot[2] = rot[2];
    r.Rot[3] = rot[3];
    
    r.MRot[0] = mrot[0];
    r.MRot[1] = mrot[1];
    r.MRot[2] = mrot[2];
    r.MRot[3] = mrot[3];
    r.MRot[4] = mrot[4];
    r.MRot[5] = mrot[5];
    r.MRot[6] = mrot[6];
    r.MRot[7] = mrot[7];
    r.MRot[8] = mrot[8];
    
    r.Mang[0] = mang[0];
    r.Mang[1] = mang[1];
    r.Mang[2] = mang[2];
    
    r.Vin[0] = vin[0];
    r.Vin[1] = vin[1];
    r.Vin[2] = vin[2];
    
    rParal->push_back(r);
    
    parallNum++;
}

void Environment::addBinding(float k, float l, float* posrel1, float* posrel2, RigidBody* c1, RigidBody* c2)
{    
    Bind b = Bind();
    
    b.PosRel1[0] = posrel1[0];
    b.PosRel1[1] = posrel1[1];
    b.PosRel1[2] = posrel1[2];
    
    b.PosRel2[0] = posrel2[0];
    b.PosRel2[1] = posrel2[1];
    b.PosRel2[2] = posrel2[2];
    
    b.K = k;
    b.L = l;
    b.c1 = c1;
    b.c2 = c2;
    
    bindings->push_back(b);
    
    bindNum++;
}

void Environment::removeSphereAtIndex(int index) {
    if (index >= 0 && index < sphereNum) {
        fSphere->erase(fSphere->begin() + index);
        rSphere->erase(rSphere->begin() + index);
        sphereNum--;
    }
}

void Environment::removeParallAtIndex(int index) {
    if (index >= 0 && index < parallNum) {
        fParal->erase(fParal->begin() + index);
        rParal->erase(rParal->begin() + index);
        parallNum--;
    }
}

void Environment::removeBindingAtIndex(int index) {
    if (index >= 0 && index < bindNum) {
        bindings->erase(bindings->begin() + index);
        bindNum--;
    }
}

void Environment::removeLastSphere() {
    rSphere->pop_back();
    fSphere->pop_back();
    sphereNum--;
}

void Environment::removeLastParall() {
    rParal->pop_back();
    fParal->pop_back();
    parallNum--;
}

void Environment::removeLastBinding() {
    bindings->pop_back();
    bindNum--;
}

void Environment::removeAllSphere() {
    fSphere->erase(fSphere->begin(), fSphere->end());
    rSphere->erase(rSphere->begin(), rSphere->end());
    sphereNum = 0;
}

void Environment::removeAllParall() {
    fParal->erase(fParal->begin(), fParal->end());
    rParal->erase(rParal->begin(), rParal->end());
    parallNum = 0;
}

void Environment::removeAllBindings() {
    bindings->erase(bindings->begin(), bindings->end());
    bindNum = 0;
}

