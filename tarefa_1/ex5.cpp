#include <iostream>
#include <GLFW/glfw3.h>

void desenhar_retangulo(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);

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
    window = glfwCreateWindow(960, 720, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    } else {
        std::cout << "Janela funcionou" << std::endl;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        // Limpa a tela

        // Especifica a cor de preenchimento do fundo
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //  r, g, b, a
        glClear(GL_COLOR_BUFFER_BIT);

		// Cria tiras vermelhas
		desenhar_retangulo(-1.0f, 0.50f, 1.0f, 0.0f);
		desenhar_retangulo(-1.0f, -0.50f, 1.0f, -1.0f);

		// Desenha quadrado azul
		glBegin(GL_POLYGON);

		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-0.25f, 1.0f, 0.0f);
		glVertex3f(-0.25f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 0.0f, 0.0f);

		glEnd();

		// Dseenha triangulo branco dentro do quadrado azul
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex3f(-0.65f, 0.85f, 0.0f);
		glVertex3f(-0.90f, 0.25f, 0.0f);
		glVertex3f(-0.35f, 0.25f, 0.0f);

		glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
