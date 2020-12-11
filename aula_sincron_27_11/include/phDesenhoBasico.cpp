#include <iostream>
#include <GLFW/glfw3.h>
#include "desenhoBasico.hpp"

void phDesenhaRetangulo(float minX, float maxX, float minY, float maxY, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    glVertex3f(minX, minY, 0.0f);
    glVertex3f(minX, maxY, 0.0f);
    glVertex3f(maxX, maxY, 0.0f);
    glVertex3f(maxX, minY, 0.0f);

    glEnd();
}

void phDesenharTriangulo(float xbase1, float xbase2, float ybase, float xtopo, float ytopo, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    glVertex3f(xbase1, ybase, 0.0f);
    glVertex3f(xbase2, ybase, 0.0f);
    glVertex3f(xtopo, ytopo, 0.0f);

    glEnd();
}

void phDesenharPontos()
{
    glColor3ub(255, 255, 0.0); // -azul = amarelo
    glPointSize(5.0);          // modificador - tamanho dos pontos
    glBegin(GL_POINTS);
    glVertex3f(20.0, 20.0, 0.0);
    glVertex3f(160.0, 20.0, 0.0);
    glVertex3f(100.0, 90.0, 0.0);
    glVertex3f(160.0, 80.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glEnd();
}

void bcvDesenharQuads()
{
    glColor3ub(200, 200, 0.0); // -azul = amarelo
    glLineWidth(2.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // modificador - desenhar somente linhas (depuracao)
    glBegin(GL_QUADS);
    glVertex3f(20.0, 20.0, 0.0);
    glVertex3f(160.0, 20.0, 0.0);
    // glVertex3f(100.0, 90.0, 0.0);
    glVertex3f(160.0, 80.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glEnd();
}

/**
Experimento array e primitiva linhas: GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP
Observar que:
- GL_LINES usa quantidade de pontos pares: v0,v1; v2,v3; ...; vn-2,vn-1
- GL_LINE_STRIP une os pontos consecutivos: v0,v1; v1,v2; v2,v3; ...; vn-2,vn-1 (polygonal line ou polyline)
- GL_LINE_LOOP somilar ao anterior, mas une ao final: v0,v1; v1,v2; v2,v3; ...; vn-2,vn-1; vn-1,v0 (loop polygonal line loop)
*/
void bcvDesenharLinhas()
{
    glColor3f(0.0, 0.5, 1.0); // azul
    glLineWidth(3.0);
    glBegin(GL_LINES); // experimento: alternar entre GL_LINES, GL_LINE_STRIP e GL_LINE_LOOP; adicionar mais um vertice (impar)
    glVertex3f(20.0, 20.0, 0.0);
    glVertex3f(160.0, 20.0, 0.0);
    glVertex3f(160.0, 80.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glEnd();
}

/**
Experimento triangulos: GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
Observar que:
- GL_TRIANGLES usa trios de vertices para compor triangulos: v0,v1,v2; v3,v4,v5; ... ;vn−3;vn−2;vn−1
- GL_TRIANGLE_STRIP usa trios, repetindo os vértices: v0,v1,v2; v1,v3,v2; v2,v4,v3; ... ;vn−3;vn−1;vn−2
-- Neste caso, a ordem eh importante!
Observar o uso de glPolygonMode

*/
void bcvDesenharTriangulos()
{

    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.5); // rosa
    glLineWidth(2.0);
    glPointSize(5.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_LINE, GL_POINT, GL_FILL

    glBegin(GL_TRIANGLES);       // experimento: alternar para GL_TRIANGLES e GL_TRIANGLE_STRIP
    glVertex3f(10.0, 10.0, 0.0); // triangulo 1
    glVertex3f(70.0, 10.0, 0.0);
    glVertex3f(70.0, 30.0, 0.0);

    glColor3f(1.0, 1.0, 0.5); // triangulo 2 - amarelo
    glVertex3f(70.0, 35.0, 0.0);
    glVertex3f(35.0, 30.0, 0.0);
    glVertex3f(35.0, 35.0, 0.0);

    glEnd();
}

/**
Experimento sequencia de triangulos: GL_TRIANGLE_FAN
Observar que:
- GL_TRIANGLE_FAN usa trios de vertices para compor triangulos ao redor de v0:
v0,v1,v2; v0,v2,v3; ... ;v0;vn−2;vn−1
*/
void bcvDesenharTriangulosSeq()
{
    glColor3f(0.20, 0.8, 0.5); // rosa
    glLineWidth(2.0);
    glPointSize(5.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // GL_LINE, GL_POINT, GL_FILL

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(10.0, 10.0, 0.0);
    glVertex3f(15.0, 90.0, 0.0);
    glVertex3f(55.0, 75.0, 0.0);
    glVertex3f(80.0, 30.0, 0.0);
    glVertex3f(90.0, 10.0, 0.0);
    glEnd();
}

/**
Experimento simples - explicando efeito de clipping na projecao ortogonal
*/
void bcvDesenharTrianguloClipping()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // GL_LINE, GL_POINT, GL_FILL
    glColor3f(0.0, 0.0, 0.5);                  // azul
    glLineWidth(3.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(20.0, 20.0, 1.5); // experimento: mudar "nariz" do triangulo para glVertex3f(20.0, 20.0, 1.5);
    glVertex3f(160.0, 20.0, 0.0);
    glVertex3f(160.0, 80.0, 0.0);
    glEnd();
}