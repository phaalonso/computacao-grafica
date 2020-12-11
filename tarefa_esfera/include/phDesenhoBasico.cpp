#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include "desenhoBasico.hpp"

void desenharPonto(double u, double v, double raio)
{
    double x, y, z;
    x = cos(u) * sin(v) * raio;
    y = cos(v) * raio;
    z = sin(u) * sin(v) * raio;
    glVertex3f(x, y, z);
}

void phDesenharEsfera(int raio)
{
    double u, v;
    glColor3ub(200, 60, 250);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);

    for (u = 0; u <= 2 * M_PI; u += 0.1)
    {
        for (v = 0; v <= M_PI; v += 0.1)
        {
            ///primeiro triangulo
            desenharPonto(u, v, raio);

            u += 0.1;
            desenharPonto(u, v, raio);

            u -= 0.1;
            v += 0.1;
            desenharPonto(u, v, raio);

            ///segundo triangulo
            v -= 0.1;
            u += 0.1;
            desenharPonto(u, v, raio);

            v += 0.1;
            desenharPonto(u, v, raio);

            u -= 0.1;
            desenharPonto(u, v, raio);
            v -= 0.1;
        }
    }

    glEnd();
}