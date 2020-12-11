#ifndef PHDESENHOBASICO_INCLUDE
#define PHDESENHOBASICO_INCLUDE

#include <GLFW/glfw3.h>

typedef struct POINT
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} POINT;
struct RGB;

typedef struct RGB
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
} RGB;


void phDesenhaRetangulo(float minX, float maxX, float minY, float maxY, float r, float g, float b);

void phDesenharTriangulo(float xbase1, float xbase2, float ybase, float xtopo, float ytopo, float r, float g, float b);

void phDesenharPontos();

void bcvDesenharQuads();

void bcvDesenharLinhas();

void bcvDesenharTriangulos();

void bcvDesenharTriangulosSeq();

void bcvDesenharTrianguloClipping();

#endif