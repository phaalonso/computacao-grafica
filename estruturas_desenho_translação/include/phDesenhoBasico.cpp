#include <iostream>
#include <GLFW/glfw3.h>
#include "desenhoBasico.hpp"
#include <cmath>

void phDesenharRetangulo(float minX, float minY, float maxX, float maxY)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // GL_LINE, GL_POINT, GL_FILL
    glColor3f(0.0, 0.0, 0.5);
    glLineWidth(3.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(minX, minY, 0.0f);
    glVertex3f(minX, maxY, 0.0f);
    glVertex3f(maxX, minY, 0.0f);
    glVertex3f(maxX, maxY, 0.0f);
    glEnd();
}

void phDesenhaCirculo(float x, float y, float z, float raio, float r, float g, float b)
{
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(r, g, b);
    glLineWidth(0.1);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y, z);

    float x1 = 0.0f;
    float y1 = 0.0f;

    for (int i = 0; i < 360; i++)
    {
        x1 = x + cosf(i) * raio;
        y1 = y + sinf(i) * raio;

        // std::cout << "X1:" << x1 << std::endl;
        // std::cout << "Y1:" << y1 << std::endl;

        glVertex3f(x1, y1, z);
    }

    glEnd();
}

void phDesenharPontosElementos() {
    glPointSize(5.0f); // Tamanho do ponto
    glLineWidth(5.0f); // Tamanho do ponto

    // Experimento para o uso de glDrawElements
    float pontosCoords[4][3] = { //x, y, z
        {-5.0, 5.0, -100.0},
        {5.0, 5.0, -100.0},
        {5.0, -5.0, -5.0},
        {-5.0, -5.0, -5.0},
    };

    float pontosCor[4][3] = { //r, g, b
        {1.0, 0.0, 0.0},
        {0.0, 1.0, -100.0},
        {0.0, 0.0, -5.0},
        {0.0, 1.0, -5.0},
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, pontosCoords); // Size, tipo deslocamento inicial, ponteiro
    glColorPointer(3, GL_FLOAT, 0, pontosCor);
 
    //Desenha
    glDrawArrays(GL_LINES, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

/**
 * @Desenha ponto
 * 
 * @param ponto 
 * @param tamanho 
 */
void phDesenharPonto(phPonto *ponto, int tamanho) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, &ponto->x); // Tamanho, tipo, deslocamento inicial
    // glColorPointer(3, GL_FLOAT, 0, &ponto->r);
    glColorPointer(3, GL_UNSIGNED_BYTE, 0, &ponto->r);

    glPointSize(tamanho); // Tamanho do ponto
    glDrawArrays(GL_POINTS, 0, 1); // Desenha um ponto

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void phDesenharCubo() {
    glPolygonMode(GL_FRONT_AND_BACK,  GL_LINE);

    GLfloat verticesCubo[] = {
        -1, -1, -1,  -1, -1, 1,  -1, 1, 1, -1, 1,-1,
         1, -1, -1,   1, -1, 1,   1, 1, 1,  1, 1,-1,
        -1, -1, -1,  -1, -1, 1,   1,-1, 1,  1,-1,-1,
        -1,  1, -1,  -1,  1, 1,   1, 1, 1,  1, 1,-1,
        -1, -1, -1,  -1,  1,-1,   1, 1,-1,  1,-1,-1,
        -1, -1,  1,  -1,  1, 1,   1, 1, 1,  1,-1, 1
    };

    GLfloat coresCubo[] = {
        0, 0, 0,  0, 0, 1,  0, 1, 1,  0, 1, 0,
        1, 0, 0,  1, 0, 1,  1, 1, 1,  1, 1, 0,
        0, 0, 0,  0, 0, 1,  1, 0, 1,  1, 0, 0,
        0, 1, 0,  0, 1, 1,  1, 1, 1,  1, 1, 0,
        0, 0, 0,  0, 1, 0,  1, 1, 0,  1, 0, 0,
        0, 0, 1,  0, 1, 1,  1, 1, 1,  1, 0, 1
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, verticesCubo);
    glColorPointer(3, GL_FLOAT, 0, coresCubo);

    // Send data: 24 vertices
    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}