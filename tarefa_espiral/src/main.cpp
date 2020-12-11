#include <GLFW/glfw3.h>
#include <iostream>
#include "desenhoBasico.hpp"

struct posicaoClick
{
    int flag = 0;
    double xpos;
    double ypos;
};

struct posicaoClick posicaoClick;

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
    glClear(GL_COLOR_BUFFER_BIT);
    /*
        Minima ideia de como isso funciona
    */
    // phDesenharEspiralX();
    phDesenharEspiralY();
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
