#include <iostream>
#include <GLFW/glfw3.h>

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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        // Limpa a tela

        // Especifica a cor de preenchimento do fundo
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //  r, g, b, a
        glClear(GL_COLOR_BUFFER_BIT);

        // Criando um poligono -----

        glColor3f(0.0f, 1.0f, 0.0f); 
        glBegin(GL_TRIANGLES);

        glVertex3f(0.0f,  0.25f, 0.0f); // x, y e z
        glVertex3f(-0.2f, -0.25f, 0.0f);
        glVertex3f(0.2f, -.25f, 0.0f);

        glEnd();
        //----

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
