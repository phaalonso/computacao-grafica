#include <iostream>
#include <GLFW/glfw3.h>
#include "desenhoBasico.hpp"

void phDesenhaRetangulo(float minX, float maxX, float minY, float maxY, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    glVertex3f(minX, minY, 0.0f);
    glVertex3f(minX, maxY, 0.0f);
    glVertex3f(maxX, maxY, 0.0f);
    glVertex3f(maxX, minY, 0.0f);

    glEnd();
}

void phDesenharTriangulo(float xbase1, float xbase2, float ybase, float xtopo, float ytopo, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    glVertex3f(xbase1, ybase, 0.0f);
    glVertex3f(xbase2, ybase, 0.0f);
    glVertex3f(xtopo, ytopo, 0.0f);

    glEnd();
}
