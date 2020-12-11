#include <GLFW/glfw3.h>
#include <iostream>
#include "desenhoBasico.hpp"

/**
 * Função para definições premiliares do projeto
 */
void aplicarConfigInicial(GLFWwindow *window);

/**
 * Função para redimensionamento de janela
 */
void ajustarJanela(GLFWwindow *window, int w, int h);

void desenharCena()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT);
    phDesenhaCirculo(0, 0, -70, 60, 0.5, 0.0, 0.0);
    phDesenhaCirculo(0, 0, -65, 50, 0.5, 0.5, 0.0);
    phDesenhaCirculo(0, 0, -60, 40, 0.0, 0.5, 0.0);
    phDesenhaCirculo(0, 0, -55, 30, 0.0, 0.2, 0.8);
    phDesenhaCirculo(0, 0, -50, 20, 0.0, 0.0, 0.5);
    phDesenhaCirculo(0, 0, -45, 10, 0.5, 0.0, 0.5);
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    else
        std::cout << "Funcionou glfw" << std::endl;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 600, "View e projecao ortogonal", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Aplicando configuração inicia*/
    aplicarConfigInicial(window);
    glClear(GL_COLOR_BUFFER_BIT);

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

void aplicarConfigInicial(GLFWwindow *window)
{
    std::cout << "Aplicando configuração inicial" << std::endl;

    glClearColor(0.40f, 0.40f, 0.40f, 1.0f); // Especifica cor de fundo

    //Configuração do registro de callbacks do glfw
    ajustarJanela(window, 200, 200);
}

/**
 * Função para redimensionamento de janela
 */
void ajustarJanela(GLFWwindow *window, int w, int h)
{
    std::cout << "Redimensionamento da janela. Width: " << w << " Height: " << h << std::endl;

    // Indicação da nova área útil da janela redimensionada (em pixel)
    // glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); // Uma alteração que envolve a projeção é necessária

    glFrustum(-5.0, 5.0, -5.0, 5.0, 5, 100); // Exemplo slide
}
