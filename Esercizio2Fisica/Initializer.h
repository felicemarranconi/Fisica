//
//  Parser.h
//  TestGL
//
//  Created by Marabese Daniele on 29/03/15.
//
//

#ifndef __TestGL__Initializer__
#define __TestGL__Initializer__

#include <stdio.h>
#include "PhysicEngine.h"
#include <vector>

using namespace std;

static void initEnvironment(Environment* env)
{
    env->sphereNum = 0;
    env->parallNum = 0;
    env->bindNum = 0;
    
    env->fParal = new vector<ShapeParall>();
    env->rParal = new vector<RigidBody>();
    env->rSphere = new vector<RigidBody>();
    env->fSphere = new vector<ShapeSphere>();
    env->bindings = new vector<Bind>();
    
    float t_semx, t_semy, t_semz;
    float t_massa;
    float t_k;
    float t_l;
    float t_raggio;
    float t_inerzia[3];
    float t_pos[3];
    float t_rot[4];
    float t_mrot[9];
    float t_mang[3];
    float t_qmoto[3];
    float t_posrel1[3];
    float t_posrel2[3];
    float t_vin[3];
    RigidBody* t_c1;
    RigidBody* t_c2;
    
    //  par1
    t_semx = 0.5;
    t_semy = 0.5;
    t_semz = 0.5;
    t_massa = 10;
    t_k = 600.0f;
    t_l = 100.0f;
    t_inerzia[0] = calculateInertiaParall(t_massa, 1, 1);
    t_inerzia[1] = calculateInertiaParall(t_massa, 2, 1);
    t_inerzia[2] = calculateInertiaParall(t_massa, 2, 1);
    t_rot[0] = 0;
    t_rot[1] = 0;
    t_rot[2] = 0;
    t_rot[3] = 0;
    t_mrot[0] = 0;
    t_mrot[1] = 0;
    t_mrot[2] = 0;
    t_mrot[3] = 0;
    t_mrot[4] = 0;
    t_mrot[5] = 0;
    t_mrot[6] = 0;
    t_mrot[7] = 0;
    t_mrot[8] = 0;
    t_mang[0] = 0;
    t_mang[1] = 0;
    t_mang[2] = 0;
    t_vin[0] = 0;
    t_vin[1] = 0;
    t_vin[2] = 0;
    
    //  piano terra
    t_pos[0] = 0;
    t_pos[1] = -4.5;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    t_pos[0] = -1.1;
    t_pos[1] = -4.5;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    t_pos[0] = -2.2;
    t_pos[1] = -4.5;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    t_pos[0] = 1.0;
    t_pos[1] = -4.5;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    //  primo piano
    t_pos[0] = 0;
    t_pos[1] = -3.4;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);

    t_pos[0] = -1.1;
    t_pos[1] = -3.4;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);

    t_pos[0] = -2.2;
    t_pos[1] = -3.4;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    t_pos[0] = 1.0;
    t_pos[1] = -3.4;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    //  terzo piano
    t_pos[0] = 0;
    t_pos[1] = -2.3;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);

    t_pos[0] = -1.1;
    t_pos[1] = -2.3;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);

    t_pos[0] = -2.2;
    t_pos[1] = -2.3;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    t_pos[0] = 1.0;
    t_pos[1] = -2.3;
    t_pos[2] = 0;
    env->addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
    
    /*
    //  binding1
    t_k = 200.0f;
    t_l = 100.0f;
    t_posrel1[0] = 2.5f;
    t_posrel1[1] = 0.0f;
    t_posrel1[2] = 0.0f;
    t_posrel2[0] = -1.5f;
    t_posrel2[1] = 0.0f;
    t_posrel2[2] = 0.0f;
    t_c1 = &env->rParal[0];
    t_c2 = &env->rSfere[0];
    env->addBinding(t_k, t_l, t_posrel1, t_posrel2, t_c1, t_c2);
    
    //  binding2
    t_k = 200.0f;
    t_l = 100.0f;
    t_posrel1[0] = 0.0f;
    t_posrel1[1] = 1.0f;
    t_posrel1[2] = -1.0f;
    t_posrel2[0] = -1.5f;
    t_posrel2[1] = 0.0f;
    t_posrel2[2] = 0.0f;
    t_c1 = &env->rSfere[0];
    t_c2 = &env->rSfere[1];
    env->addBinding(t_k, t_l, t_posrel1, t_posrel2, t_c1, t_c2);
    */
    
}

static void deinitEnvironment(Environment* env) {
    env->removeAllSphere();
    env->removeAllParall();
    env->removeAllBindings();
    
    delete env->fSphere;
    delete env->rSphere;
    delete env->fParal;
    delete env->rParal;
    delete env->bindings;
}


#endif /* defined(__TestGL__Initializer__) */
