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
    static float zoomOut = 0.0f;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // phDesenharPontosElementos();

    // phPonto p1 = {0.0, 0.0, -100.0, 128, 128, 243}; // x, y, z, r, g, b
    // phDesenharPonto(&p1, 10);

    glMatrixMode(GL_MODELVIEW); // Habilitando modo de edição do modelo-visão
    glLoadIdentity(); // Carrega a matriz identidade
    
    glTranslatef(0.0f, 0.0f, -6.0f - zoomOut); //tx, ty, tz

    phDesenharCubo();

    zoomOut = zoomOut + 0.02;
    std::cout << "Zoom out: " << zoomOut << std::endl;
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
    glEnable(GL_DEPTH_BUFFER_BIT); // Habilitando profundidade

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
