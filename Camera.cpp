#include "Camera.h"
#include "Mapa.h"
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

// Destrutor
Camera::~Camera(void) {}

// Construtor
Camera::Camera(float ratio) {
  glEnable(GL_CULL_FACE);

  float  cor[4], dir[4];

  // Habilita a iluminação com uma fonte de luz.
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  // Luz Ambiente e Difusa acompanham a cor atual.
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  // Habilita a normalização do vetor normal.
  glEnable(GL_NORMALIZE);

  cor[0] = 1.0f;
  cor[1] = 1.0f;
  cor[2] = 1.0f;
  cor[3] = 1.0f;
  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor);
  cor[0] = 0.0f;
  cor[1] = 0.0f;
  cor[2] = 0.0f;
  cor[3] = 1.0f;
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, razao, 0.005, 100);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 1.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  dir[0] = 0.0;
  dir[1] = 1.0;
  dir[2] = 1.0;
  dir[3] = 0.0;
  glLightfv(GL_LIGHT0, GL_POSITION, dir);
}

// Posiciona a câmera de forma a fornecer uma visão isométrica do mapa.
void Camera::Posicao(float x_at, float y_at, double angle, int view) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 1.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(-1.5, -26, 25,
            -1.5,   -9,    1,
            0.0f, 0.0f, 1.0f);
}
