#include <iostream>
#include <GLFW/glfw3.h>

void desenhar_quadrado(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(x1, y1, 0.0f);
	glVertex3f(x2, y1, 0.0f);
	glVertex3f(x2, y2, 0.0f);
	glVertex3f(x1, y2, 0.0f);

	glEnd();
}

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    } else {
        std::cout << "Janela funcionou" << std::endl;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	GLfloat y;
	GLfloat x;
	int cont = 8;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //  r, g, b, a
        glClear(GL_COLOR_BUFFER_BIT);

		y = 1.0f;
		while (y >= -1.0) {
			if (cont % 2 == 0) {
				x = -1.0f;
				cont--;
			} else {
				x = -0.75f;
				cont--;
			}
			while (x <= 1.0) {
				desenhar_quadrado(x, y, x + 0.25f, y - 0.25f);

				//printf("X: %2f", x);
				//printf("Y: %2f", y);
				x += 0.50f;
			}
			y -= 0.25f;
		}

		cont = 8;

       /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
