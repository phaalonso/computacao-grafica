#include <GLFW/glfw3.h>
#include <iostream>
#include "desenhoBasico.hpp"

static float zoomOut = 0.0f;

/**
 * Função para definições premiliares do projeto
 */
void aplicarConfigInicial(GLFWwindow *window);

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

/**
 * Função para redimensionamento de janela
 */
void ajustarJanela(GLFWwindow *window, int w, int h);

void desenharCena()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, 0.0f - zoomOut);

    phDesenharEsfera(1);
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
    window = glfwCreateWindow(640, 480, "View e projecao ortogonal", NULL, NULL);
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

    glfwSetScrollCallback(window,  scroll_callback);

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

    glFrustum(-5.0, 5.0, -5.0, 5.0, -1, 1); // Exemplo slide
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    zoomOut += yoffset / 10;
    std::cout << "zoomOut: " << zoomOut << std::endl;
}