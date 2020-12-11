#include <GLFW/glfw3.h>
#include <iostream>
#include "desenhoBasico.hpp"

void aplicarConfigInicial() {
    std::cout << "Aplicando configuração inicial" << std::endl;

    glClearColor(150.0f, 150.0f, 150.0f, 1.0f);
    glOrtho(0.0f, 200.0f, 0.0f, 100.0f, -1.0f, 0.0f);
    // glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

}

void desenharCenaCasa() {
    phDesenhaRetangulo(60.0f, 140.0f, 20.0f, 50.0f, 0.0f, 102.0f, 204.0f);
    phDesenharTriangulo(60.0f, 140.0f, 50.0f, 100.0f, 70.0f, 255.0f, 0.0f, 0.0f );
    phDesenhaRetangulo(70.0f, 90.0f, 20.0f, 40.0f,  0.0f, 0.0f, 0.0f);
    phDesenhaRetangulo(100.0f, 130.0f, 30.0f, 40.0f, 0.0f, 0.0f, 0.0f );
}

void desenharCena()
{
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    desenharCenaCasa();
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Top", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    aplicarConfigInicial();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        desenharCena();

        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}