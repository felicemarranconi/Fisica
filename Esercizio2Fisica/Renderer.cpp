//
//  Renderer.cpp
//  TestGL
//
//  Created by Marabese Daniele on 15/03/15.
//
//

#include "Renderer.h"

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
    for(i = 1;i <= 64;i++) {
        Y1 = Y2;
        X1 = X2;
        Y2 = (i / 32.0f) - 1.0f;
        X2 = 1 - (Y2 * Y2);
        if(X2 > 0) X2 = R * sqrt(X2);
        glBegin(GL_QUAD_STRIP);
        for(j = 0;j < 6.2831f;j += (6.283f / 64)) {
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
    
    if(M != NULL) {
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
    for(i = 1;i <= 64;i++) {
        Y1 = Y2;
        X1 = X2;
        Y2 = (i / 32.0f) - 1.0f;
        X2 = 1 - (Y2 * Y2);
        if(X2 > 0) X2 = R * sqrt(X2);
        
        if(i == 17) {
            glMaterialfv(GL_FRONT, GL_AMBIENT, white);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
        }
        if(i == 48) {
            glMaterialfv(GL_FRONT, GL_AMBIENT, red);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
        }
        
        glBegin(GL_QUAD_STRIP);
        for(j = 0;j < 6.2831f;j += (6.283f / 64)) {
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

void drawParall(float X, float Y, float Z, float Lx, float Ly, float Lz, const float *R)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(X, Y, Z);
    
    if(R != NULL) {
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

void drawXZPlane(float Y)
{
    int i;
    float Dim = 20;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, green2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, green2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMateriali(GL_FRONT, GL_SHININESS, 16);
    
    glBegin(GL_LINES);
    glNormal3f(0, 1, 0);
    for(i = -Dim;i < Dim;i++) {
        glVertex3f(i, Y, -Dim);
        glVertex3f(i, Y, Dim);
    }
    for(i = -Dim;i < Dim;i++) {
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

