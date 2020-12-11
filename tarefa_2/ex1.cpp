#include <iostream>
#include <GLFW/glfw3.h>

int main(void) {
    GLFWwindow* window;
	bool flag = true;

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

    while (!glfwWindowShouldClose(window)) {
		if (flag) 
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f); //  r, g, b, a
		 else {
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //  r, g, b, a
		
		flag = !flag;
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
