#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include "desenhoBasico.hpp"

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

void phDesenhaCirculo(float x, float y, float raio) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 0.5);                
    glLineWidth(3.0);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y, 0.0f);

    float x1 = 0.0f;
    float y1 = 0.0f;

    for(int i = 0; i < 360; i ++) {
        x1 =  x + cosf(i) * raio;
        y1 =  y + sinf(i) * raio;

        // std::cout << "X1:" << x1 << std::endl;
        // std::cout << "Y1:" << y1 << std::endl;

        glVertex3f(x1, y1, 0.0f);

    }
    

}