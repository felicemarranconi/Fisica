//
//  Renderer.h
//  TestGL
//
//  Created by Marabese Daniele on 15/03/15.
//
//

#ifndef __TestGL__Renderer__
#define __TestGL__Renderer__

#include <stdio.h>
#include "Matrici.h"
#include "glut.h"
#include "PhysicEngine.h"

 void drawSphere(float X, float Y, float Z, float R);
 void drawSphere(float X, float Y, float Z, float R, const float *M);
 void drawParall(float X, float Y, float Z, float Lx, float Ly, float Lz, const float *R);
 void drawXZPlane(float Y);
 void changeDimension(int w, int h);
 void buttonAction(unsigned char key, int, int);

//  costanti per il rendering
static GLfloat red[] = { 1.0f, 0.2f, 0.2f, 1.0f };
static GLfloat green[] = { 0.2f, 0.8f, 0.2f, 1.0f };
static GLfloat green2[] = { 0.4f, 1.0f, 0.4f, 1.0f };
static GLfloat blue[] = {0.4f, 0.4f, 1.0f, 1.0f };
static GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };

static GLfloat black[] = { 0.0f, 0.0f, 0.0f, 1.0f };
static GLfloat aLite[] = { 0.2f, 0.2f, 0.2f, 1.0f };
static GLfloat dLite[] = { 0.8f, 0.8f, 0.8f, 1.0f };
static GLfloat sLite[] = { 0.8f, 0.8f, 0.8f, 1.0f };
static GLfloat LightPos[4] = { 1, 2, 1, 0 };

static GLfloat Rot[16];

#endif /* defined(__TestGL__Renderer__) */


