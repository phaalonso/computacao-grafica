#include <GLFW/glfw3.h>
#include <iostream>
#include "phDesenharBasico.hpp" // Nas configs do projeto, inclue o diretorio

void aplicarConfigInicial() {
    std::cout << "Aplicando configuração inicial" << std::endl;

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glOrtho(0.0f, 200.0f, 0.0f, -1.0f, -1.0f, 1.0f);
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

}

void desenharCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    phDesenharRetanguloTeste();
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    else
        std::cout << "Funcionou glfw" << std::endl;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "View e projecao ortogonal", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Aplicando configuração inicia*/
    aplicarConfigInicial();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        desenharCena();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
