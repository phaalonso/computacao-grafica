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

void phDesenhaCirculo(float x, float y, float raio)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 0.5);
    glLineWidth(3.0);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y, 0.0f);

    float x1 = 0.0f;
    float y1 = 0.0f;

    for (int i = 0; i < 360; i++)
    {
        x1 = x + cosf(i) * raio;
        y1 = y + sinf(i) * raio;

        // std::cout << "X1:" << x1 << std::endl;
        // std::cout << "Y1:" << y1 << std::endl;

        glVertex3f(x1, y1, 0.0f);
    }
}

/**
Experimento para demonstracao da projecao perspectiva
**/
void phDesenharEspiralZ()
{

    float r = 10.0; // raio do espiral
    float t;        // angulo
    float x, y, z;

    glColor3f(0.0, 0.5, 0.0); // verde
    glLineWidth(2.0);

    // variando na faixa -10pi, 10pi
    glBegin(GL_LINE_STRIP);
    for (t = -5; t >= -70; t -= 0.01)
    {
        x = r * cos(t);
        y = r * sin(t);
        z = t;
        //std::cout << "Posicionando em (x,y,z): " << x << ", " << y << ", " << z << std::endl;
        glVertex3f(x, y, z); // observar efeito do valor da variacao de t. Ex: -5 <= t <= -100
        // lembrar que na proj perspectiva z=0 esta na origem do observador, por isso, deslocar para zoom out
    }
    glEnd();
}

/**
* Experimento para demonstracao da projecao perspectiva
*/
void phDesenharVaretas()
{
    glLineWidth(2.0);
    int i, j;

    glBegin(GL_LINES);
    for (i = -5; i <= 5; i++)
    {
        for (j = -5; j <= 5; j++)
        {
            glColor3f(sin(i), sin(j), sin(i + j)); // cor ~aleatoria
            glVertex3f(i, j, -20);
            glVertex3f(i, j, -100);
        }
    }
    glEnd();
}