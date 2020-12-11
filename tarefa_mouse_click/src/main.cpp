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
 * Pega evento de clicke
 */
void clickeMouse(GLFWwindow *window, int button, int action, int mods);

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
    glClear(GL_COLOR_BUFFER_BIT);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
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

    glClearColor(0.40f, 0.41f, 0.54f, 1.0f); // Especifica cor de fundo

    //Configuração do registro de callbacks do glfw
    glfwSetKeyCallback(window, processarTeclado); // Callback teclado
    glfwSetWindowSizeCallback(window, ajustarJanela); // Redimensionamento
    glfwSetCursorPosCallback(window, processarMovimentoMouse); // Mudança no posicionamento do mouse
    glfwSetMouseButtonCallback(window, clickeMouse); // Clique do mouse

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

    glOrtho(0.0f, w, 0.0f, h, -1.0f, 1.0f); // def. do viewing box
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
    } else if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

/**
 * Processar movimento do mouse
 */
void processarMovimentoMouse(GLFWwindow *window, double xpos, double ypos) {
    std::cout << "O mouse foi movimentado. X: " << xpos << " Y:" << ypos << std::endl;
}

/**
 * Pega evento de clicke
 */
void clickeMouse(GLFWwindow *window, int button, int action, int mods) {

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "Clique com o botão esquero" << std::endl;

        int largura, altura;
        double xpos, ypos;

        glfwGetWindowSize(window, &largura, &altura);
        glfwGetCursorPos(window, &xpos, &ypos);

        ypos = altura - ypos;

        std::cout << "Posicao do mouse X:" << xpos << " Y:" << ypos << std::endl;
        if (posicaoClick.flag) {
            std::cout << "Segundo click, desenhando" << std::endl;
            posicaoClick.flag = false;

            std::cout << "P1(" << xpos << ", " << ypos << "), P2(" << posicaoClick.xpos << ", " << posicaoClick.ypos << ")" << std::endl;
            phDesenhaRetangulo(xpos, posicaoClick.xpos, ypos, posicaoClick.ypos, 0.189f, 0.147f, 0.249f);
            glfwSwapBuffers(window);
            phDesenhaRetangulo(xpos, posicaoClick.xpos, ypos, posicaoClick.ypos, 0.189f, 0.147f, 0.249f);
            glfwSwapBuffers(window);
        } else {
            std::cout << "Primeiro click" << std::endl;
            posicaoClick.flag = true;
            posicaoClick.xpos = xpos;
            posicaoClick.ypos = ypos;
        }


    }
}