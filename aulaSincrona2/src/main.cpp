#include <GLFW/glfw3.h>
#include <iostream>
#include "phDesenharBasico.hpp" // Nas configs do projeto, inclue o diretorio

/**
 * Função para definições premiliares do projeto
 */
void aplicarConfigInicial(GLFWwindow *window);

/**
 * Função para entrada de teclado
 */
void processarTeclado(GLFWwindow *window, int key, int scancode, int action, int mode);

/**
 * Função para redimensionamento de janela
 */
void ajustarJanela(GLFWwindow *window, int w, int h);

/**
 * Processar movimento do mouse
 */
void processarMovimentoMouse(GLFWwindow *window, double xpos, double ypos);

/**
 * Função para desenhar cena
 */
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
    aplicarConfigInicial(window);

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

void aplicarConfigInicial(GLFWwindow *window) {
    int largura, altura;
    std::cout << "Aplicando configuração inicial" << std::endl;

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Especifica cor de fundo

    //Configuração do registro de callbacks do glfw
    glfwSetKeyCallback(window, processarTeclado); // Callback teclado
    glfwSetWindowSizeCallback(window, ajustarJanela); // Redimensionamento
    glfwSetCursorPosCallback(window, processarMovimentoMouse);

    glfwGetWindowSize(window, &largura, &altura);
    ajustarJanela(window, largura, altura);
}

/**
 * Função para redimensionamento de janela
 */
void ajustarJanela(GLFWwindow *window, int w, int h) {
    std::cout << "Redimensionamento da janela. Width: " << w << " Height: " << h << std::endl;

    // Indicação da nova área útil da janela redimensionada (em pixel)
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); // Uma alteração que envolve a projeção é necessária
    glLoadIdentity();

    glOrtho(0.0f, 200.0f, 0.0f, 100.0f, -1.0f, 1.0f); // def. do viewing box
}

/**
 * Função para entrada de teclado
 */
void processarTeclado(GLFWwindow *window, int key, int scancode, int action, int mode) {
    std::cout << "Uma tecla foi pressionada " << key << std::endl;

    // Esc foi pressionado
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        std::cout << "A tecla esc foi pressionada " << key << std::endl;

        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

/**
 * Processar movimento do mouse
 */
void processarMovimentoMouse(GLFWwindow *window, double xpos, double ypos) {
    std::cout << "O mouse foi movimentado. X: " << xpos << " Y:" << ypos << std::endl;
}