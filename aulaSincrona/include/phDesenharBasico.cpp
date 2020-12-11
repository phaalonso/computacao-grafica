#include <GLFW/glfw3.h>
#include "phDesenharBasico.hpp"

void phDesenharRetanguloTeste() {

    /** poligono verde - unidades de 0 a 200 approx no Viewing Box **/
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(20.0, 90.0, 0.0);
    glVertex3f(80.0, 90.0, 0.0);
    glVertex3f(80.0, 60.0, 0.0);
    glVertex3f(20.0, 60.0, 0.0);
    glEnd();

    /** poligono vermelho - unidades de -1.0 a 1.0 no Viewing Box */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.8, 0.8, 0.0);
    glVertex3f(-0.2, 0.8, 0.0);
    glVertex3f(-0.2, 0.2, 0.0);
    glVertex3f(-0.8, 0.2, 0.0);
    glEnd();
}
