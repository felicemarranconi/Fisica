//
//  main.cpp
//  TestGL
//
//  Created by Marabese Daniele on 16/03/15.
//
//
#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "glut.h"
#include "Matrici.h"
#include "Shapes.h"
#include "Collision.h"
#include "RigidBody.h"
#include "Renderer.h"
#include "PhysicEngine.h"
#include "Binds.h"
#include "Sphere.h"
#include "Paral.h"
#include "Initializer.h"
#include <time.h>

using namespace std;

Environment env;

void drawSphere(float X, float Y, float Z, float R)
{
	int i;
	float j, X1, Y1, X2, Y2, s, c;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(X, Y, Z);

	glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMateriali(GL_FRONT, GL_SHININESS, 16);

	//glutSolidSphere(R, 64, 64);
	X2 = 0;
	Y2 = -1;
	for (i = 1; i <= 64; i++) {
		Y1 = Y2;
		X1 = X2;
		Y2 = (i / 32.0f) - 1.0f;
		X2 = 1 - (Y2 * Y2);
		if (X2 > 0) X2 = R * sqrt(X2);
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j < 6.2831f; j += (6.283f / 64)) {
			s = sin(j);
			c = cos(j);
			glNormal3f(c * X1, Y1, s * X1);
			glVertex3f(c * X1 * R, Y1 * R, s * X1 * R);
			glNormal3f(c * X2, Y2, s * X2);
			glVertex3f(c * X2 * R, Y2 * R, s * X2 * R);
		}
		glEnd();
	}

	glPopMatrix();
}

void drawSphere(float X, float Y, float Z, float R, const float *M)
{
	int i;
	float j, X1, Y1, X2, Y2, s, c;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(X, Y, Z);

	if (M != NULL) {
		Rot[0] = M[0]; Rot[1] = M[1]; Rot[2] = M[2]; Rot[3] = 0;
		Rot[4] = M[3]; Rot[5] = M[4]; Rot[6] = M[5]; Rot[7] = 0;
		Rot[8] = M[6]; Rot[9] = M[7]; Rot[10] = M[8]; Rot[11] = 0;
		Rot[12] = 0; Rot[13] = 0; Rot[14] = 0; Rot[15] = 1;
		glMultMatrixf(Rot);
	}

	glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMateriali(GL_FRONT, GL_SHININESS, 16);

	//glutSolidSphere(R, 64, 64);
	X2 = 0;
	Y2 = -1;
	for (i = 1; i <= 64; i++) {
		Y1 = Y2;
		X1 = X2;
		Y2 = (i / 32.0f) - 1.0f;
		X2 = 1 - (Y2 * Y2);
		if (X2 > 0) X2 = R * sqrt(X2);

		if (i == 17) {
			glMaterialfv(GL_FRONT, GL_AMBIENT, white);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		}
		if (i == 48) {
			glMaterialfv(GL_FRONT, GL_AMBIENT, red);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
		}

		glBegin(GL_QUAD_STRIP);
		for (j = 0; j < 6.2831f; j += (6.283f / 64)) {
			s = sin(j);
			c = cos(j);
			glNormal3f(c * X1, Y1, s * X1);
			glVertex3f(c * X1 * R, Y1 * R, s * X1 * R);
			glNormal3f(c * X2, Y2, s * X2);
			glVertex3f(c * X2 * R, Y2 * R, s * X2 * R);
		}
		glEnd();
	}

	glPopMatrix();
}

void DisegnaParall(float X, float Y, float Z, float Lx, float Ly, float Lz, const float *R)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(X, Y, Z);

	if (R != NULL) {
		Rot[0] = R[0]; Rot[1] = R[1]; Rot[2] = R[2]; Rot[3] = 0;
		Rot[4] = R[3]; Rot[5] = R[4]; Rot[6] = R[5]; Rot[7] = 0;
		Rot[8] = R[6]; Rot[9] = R[7]; Rot[10] = R[8]; Rot[11] = 0;
		Rot[12] = 0; Rot[13] = 0; Rot[14] = 0; Rot[15] = 1;
		glMultMatrixf(Rot);
	}

	glMaterialfv(GL_FRONT, GL_AMBIENT, blue);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMateriali(GL_FRONT, GL_SHININESS, 16);

	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glVertex3f(Lx, Ly, Lz);
	glVertex3f(Lx, -Ly, Lz);
	glVertex3f(Lx, -Ly, -Lz);
	glVertex3f(Lx, Ly, -Lz);
	glNormal3f(0, 1, 0);
	glVertex3f(Lx, Ly, Lz);
	glVertex3f(Lx, Ly, -Lz);
	glVertex3f(-Lx, Ly, -Lz);
	glVertex3f(-Lx, Ly, Lz);
	glNormal3f(0, 0, 1);
	glVertex3f(Lx, Ly, Lz);
	glVertex3f(-Lx, Ly, Lz);
	glVertex3f(-Lx, -Ly, Lz);
	glVertex3f(Lx, -Ly, Lz);
	glNormal3f(-1, 0, 0);
	glVertex3f(-Lx, Ly, Lz);
	glVertex3f(-Lx, Ly, -Lz);
	glVertex3f(-Lx, -Ly, -Lz);
	glVertex3f(-Lx, -Ly, Lz);
	glNormal3f(0, -1, 0);
	glVertex3f(Lx, -Ly, Lz);
	glVertex3f(-Lx, -Ly, Lz);
	glVertex3f(-Lx, -Ly, -Lz);
	glVertex3f(Lx, -Ly, -Lz);
	glNormal3f(0, 0, -1);
	glVertex3f(Lx, Ly, -Lz);
	glVertex3f(Lx, -Ly, -Lz);
	glVertex3f(-Lx, -Ly, -Lz);
	glVertex3f(-Lx, Ly, -Lz);
	glEnd();

	glPopMatrix();
}

void  DisegnaPianoXZ(float Y)
{
	int i;
	float Dim = 20;

	glMaterialfv(GL_FRONT, GL_AMBIENT, green2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMateriali(GL_FRONT, GL_SHININESS, 16);

	glBegin(GL_LINES);
	glNormal3f(0, 1, 0);
	for (i = -Dim; i < Dim; i++) {
		glVertex3f(i, Y, -Dim);
		glVertex3f(i, Y, Dim);
	}
	for (i = -Dim; i < Dim; i++) {
		glVertex3f(-Dim, Y, i);
		glVertex3f(Dim, Y, i);
	}
	glEnd();

}

void changeDimension(int w, int h)
{
	glViewport(0, 0, w, h);

	// matrice
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 2, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -12);
}

void keyPressed(unsigned char Tasto)
{   /*
	if(Tasto == 'w') Sfera.Qmoto[1] = 2 * Sfera.Massa;
	if(Tasto == 'a') Sfera.Qmoto[0] = -2 * Sfera.Massa;
	if(Tasto == 'd') Sfera.Qmoto[0] = 2 * Sfera.Massa;
	if(Tasto == 's') Sfera.Qmoto[2] = -2 * Sfera.Massa;
	*/
}

void buttonAction(unsigned char key, int, int)
{
	keyPressed(key);
}


static void updateSystem()
{
    int i, nCol;
    
    // gravity
    for (i = 0; i < env.sphereNum; ++i) {
        env.rSphere->at(i).Fris[1] = -g * env.rSphere->at(i).Weight;
    }
    for (i = 0; i < env.parallNum; ++i) {
        env.rParal->at(i).Fris[1] = -g * env.rParal->at(i).Weight;
    }
    
    //  collisions sphere -> plane
    for (int i = 0; i < env.sphereNum; ++i) {
        nCol = env.fSphere->at(i).collideWithPlane(&env.rSphere->at(i), A, B, C, D, env.collisions, MAX_COL);
        
        for (int j = 0; j < nCol; ++j) {
            env.collisions[j].applyCollisionForce(&env.rSphere->at(i), NULL, env.rSphere->at(i).K, env.rSphere->at(i).L, m);
        }
    }
    
    //  collisions parall -> plane
    for (int i = 0; i < env.parallNum; ++i) {
        nCol = env.fParal->at(i).collideWithPlane(&env.rParal->at(i), A, B, C, D, env.collisions, MAX_COL);
        
        for (int j = 0; j < nCol; ++j) {
            env.collisions[j].applyCollisionForce(&env.rParal->at(i), NULL, env.rParal->at(i).K, env.rParal->at(i).L, m);
        }
        
        for (int k = 0; k < env.sphereNum; ++k) {
            nCol = env.fParal->at(i).collideWithSphere(&env.rParal->at(i), &env.rSphere->at(k), env.fSphere->at(k).ray, env.collisions, MAX_COL);
            
            for (int j = 0; j < nCol; ++j) {
                env.collisions[j].applyCollisionForce(&env.rParal->at(i), &env.rSphere->at(k), env.rParal->at(i).K, env.rParal->at(i).L, m);
            }
        }
    }
    
    //  collisions parall -> parall
    for (int i = 0; i < env.parallNum; ++i) {
        
        for (int k = i+1; k < env.parallNum; ++k) {
            nCol = env.fParal->at(i).collideWithParall(&env.rParal->at(i), &env.rParal->at(k), env.collisions, MAX_COL);
            
            for (int j = 0; j < nCol; ++j) {
                env.collisions[j].applyCollisionForce(&env.rParal->at(i), &env.rParal->at(k), env.rParal->at(i).K, env.rParal->at(i).L, m);
            }
        }
    }
    
    //  collisions sphere -> sphere
    for (int i = 0; i < env.sphereNum; ++i) {
        
        for (int k = i+1; k < env.sphereNum; ++k) {
            nCol = env.fSphere->at(i).collideWithSphere(&env.rSphere->at(i), env.fSphere->at(i).ray, &env.rSphere->at(k), env.fSphere->at(k).ray, env.collisions, MAX_COL);
            
            for (int j = 0; j < nCol; ++j) {
                env.collisions[j].applyCollisionForce(&env.rSphere->at(i), &env.rSphere->at(k), env.rSphere->at(i).K, env.rSphere->at(i).L, m);
            }
        }
    }
    
    //  bindings
    for (int i = 0; i < env.bindNum; ++i) {
        env.bindings->at(i).applyBindingForce(env.bindings->at(i).c1, env.bindings->at(i).c2, env.bindings->at(i).K, env.bindings->at(i).L);
    }
    
    for (int i = 0; i < env.parallNum; ++i) {
        env.rParal->at(i).updateState(DT);
        env.rParal->at(i).Fris[0] = env.rParal->at(i).Fris[1] = env.rParal->at(i).Fris[2] = 0;
        env.rParal->at(i).Mris[0] = env.rParal->at(i).Mris[1] = env.rParal->at(i).Mris[2] = 0;
    }
    for (int i = 0; i < env.sphereNum; ++i) {
        env.rSphere->at(i).updateState(DT);
        env.rSphere->at(i).Fris[0] = env.rSphere->at(i).Fris[1] = env.rSphere->at(i).Fris[2] = 0;
        env.rSphere->at(i).Mris[0] = env.rSphere->at(i).Mris[1] = env.rSphere->at(i).Mris[2] = 0;
    }
}

//DisegnaSfera
//visita  sistema
int flag = 0;
static void VisualizzaSistema()
{
	DisegnaPianoXZ(-D);
    



	for (int i = 0; i < 10; ++i) {
		DisegnaParall(env.rParal->at(i).Pos[0],
			env.rParal->at(i).Pos[1],
			env.rParal->at(i).Pos[2],
			env.fParal->at(i).semiX,
			env.fParal->at(i).semiY,
			env.fParal->at(i).semiZ,
			env.rParal->at(i).MRot);
	}








	for (int i = 0; i < env.sphereNum; ++i) {

       // drawSphere(env.rSphere->at(i).Pos[0], env.rSphere->at(i).Pos[1], env.rSphere->at(i).Pos[2], env.fSphere->at(i).ray, env.rSphere->at(i).MRot);
		drawSphere(env.rSphere->at(i).Pos[0],
			env.rSphere->at(i).Pos[1],
			env.rSphere->at(i).Pos[2],
			env.fSphere->at(i).ray, 
			env.rSphere->at(i).MRot);


		if (flag < 3){
			std::cout << "Hello World!"<<"\n";

			std::cout << "env.fSphere->at(i).ray: " << env.fSphere->at(i).ray << "\n";
			std::cout << "env.fSphere->at(i).ray: " << env.rSphere->at(i).MRot << "\n";

			flag++;
		}

    }
	
}

static void DisegnaTutto()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, aLite);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dLite);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sLite);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
    
	VisualizzaSistema();
    
    glutSwapBuffers();
}

static void RunCyclically()
{
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    
    while(totalTime < t) {
        updateSystem();
        totalTime += DT;
    }
    
    glutPostRedisplay();
}
/*
void randPosGenerator(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float* out) {
    out[0] = 1;
    out[1] = 1;
    out[2] = 1;
    
}
*/

void throwBall(){
    float t_raggio = 1.1;
    float t_massa = 15;
    float t_k = 1200.0f;
    float t_l = 100.0f;
    float t_inerzia[3] = {calculateInertiaSpere(t_massa, t_raggio), calculateInertiaSpere(t_massa, t_raggio), t_inerzia[2] = calculateInertiaSpere(t_massa, t_raggio)};
    float t_pos[3];
	t_pos[0] = 1;
	t_pos[1] = 1;
	t_pos[2] = 1;
    float t_rot[4] = {1, 0, 0, 0};
    float t_mrot[9] = {1, 0, 0, 0, 0, 1, 0, 0, 1};
    float t_qmoto[3] = {-30, 0, 0};
    float t_vin[3] = {0, 0, 0};

    env.addSphere(t_pos, t_rot, t_qmoto, t_mrot, t_massa, t_l, t_k, t_raggio, t_inerzia, t_vin);

}

void throwBox(){
    float t_semx = 0.5;
    float t_semy = 0.5;
    float t_semz = 0.5;
    float t_massa = 10;
    float t_k = 600.0f;
    float t_l = 100.0f;
    float t_inerzia[3];
    t_inerzia[0] = calculateInertiaParall(t_massa, 1, 1);
    t_inerzia[1] = calculateInertiaParall(t_massa, 2, 1);
    t_inerzia[2] = calculateInertiaParall(t_massa, 2, 1);
	
    float t_pos[3];
	t_pos[0] = 1;
	t_pos[1] = 1;
	t_pos[2] = 1;
	
	float t_rot[4] = {1, 0, 0, 0};
    float t_mrot[9] = {1, 0, 0, 0, 0, 1, 0, 0, 1};
    float t_qmoto[3] = {-30, 0, 0};
    float t_vin[3] = {0, 0, 0};
    float t_mang[3];
    t_mang[0] = 0;
    t_mang[1] = 0;
    t_mang[2] = 0;

    env.addParall(t_pos, t_rot, t_mang, t_mrot, t_massa, t_l, t_k, t_semx, t_semy, t_semz, t_inerzia, t_vin);
}

void ProcessSpecialKeys(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            throwBall();
            break;
        case GLUT_KEY_DOWN:
            throwBox();
            break;
        case GLUT_KEY_HOME:
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    srand(time(0));
    
    initEnvironment(&env);
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(1000, 100);
    glutInitWindowSize(900, 900);
    glutCreateWindow("Esame di Fisica:Marranconi && Nam Cam");
    
    glutReshapeFunc(changeDimension);
	//drawAll
	glutDisplayFunc(DisegnaTutto);
    glutKeyboardFunc(buttonAction);
    glutIdleFunc(RunCyclically);
    glutSpecialFunc(ProcessSpecialKeys);
    
    // Z buffer
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    // luci
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    
    glutMainLoop();
    
    return 0;
}

