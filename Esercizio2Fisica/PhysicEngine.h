//
//  PhysicEngine.h
//  TestGL
//
//  Created by Marabese Daniele on 13/03/15.
//
//

#ifndef __TestGL__PhysicEngine__
#define __TestGL__PhysicEngine__

#include <stdio.h>
#include "Shapes.h"
#include "Collision.h"
#include "RigidBody.h"
//#include "Renderer.h"
#include "PhysicEngine.h"
#include "Binds.h"
#include "Sphere.h"
#include "Paral.h"
#include <vector>

using namespace std;

//  COSTANTS
static const float g = 9.8f;
static const float m = 0.2f;

static int A = 0;
static int B = 1;
static int C = 0;
static int D = 5;

static int MAX_COL = 8;

// delta integration
static float DT = 0.010f;
static double totalTime = 0.0f;

static float calculateInertiaParall(float weight, float X, float Y)
{
    return (((4.0f*X*X)+(4.0f*Y*Y))*weight/12.0f);
}

static float calculateInertiaSpere(float weigth, float ray)
{
    return 0.4f * weigth * ray * ray;
}

struct Environment {
    int sphereNum;
    int parallNum;
    int bindNum;
    
    vector<ShapeSphere>* fSphere;
    vector<RigidBody>* rSphere;
    vector<ShapeParall>* fParal;
    vector<RigidBody>* rParal;
    Collision collisions[8];
    vector<Bind>* bindings;
    
    void addSphere(float* pos, float* rot, float* qmoto,  float* mrot, float weight, float l, float k, float ray, float* inertia, float* vin);
    
    void addParall(float* pos, float* rot, float* mang, float* mrot, float weight, float l, float k, float semx, float semy, float semz, float* inertia, float* vin);
    
    void addBinding(float k, float l, float* posrel1, float* posrel2, RigidBody* c1, RigidBody* c2);
    
    void removeSphereAtIndex(int index);
    void removeParallAtIndex(int index);
    void removeBindingAtIndex(int index);
    
    void removeLastSphere();
    void removeLastParall();
    void removeLastBinding();
    
    void removeAllSphere();
    void removeAllParall();
    void removeAllBindings();
    
    const int getNumSphere()const { return fSphere->size(); }
    const int getNumParal()const { return fParal->size(); }
    const int getNumBinding()const { return bindings->size(); }
    
};

#endif /* defined(__TestGL__PhysicEngine__) */

 
 
