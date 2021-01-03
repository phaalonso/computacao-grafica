#ifndef PHDESENHOBASICO_INCLUDE
#define PHDESENHOBASICO_INCLUDE

#include <GLFW/glfw3.h>

typedef struct phPonto {
    GLfloat x, y, z;
    GLubyte r, g, b;
} phPonto;

void phDesenharRetangulo(float minX, float minY, float maxX, float maxY);
void phDesenhaCirculo(float x, float y, float z, float raio, float r, float g, float b);
void phDesenharPontosElementos();
void phDesenharPonto(phPonto *ponto, int tamanho);
void phDesenharCubo();
void phDesenharPiramide();
void phDesenharEixosOrigem(float tomCinza);

#endif