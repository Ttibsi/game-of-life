#define GL_SILENCE_DEPRECATION

#include "../include/GLFW/glfw3.h"
#include "../include/templates.h"

#include <iostream>

// https://stackoverflow.com/a/67585643

void renderContent(GLFWwindow *window) {
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Render code here
        Triangle2d tri_1 = {{0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0}};

        GLuint buffer_obj;
        glGenBuffers(1, &buffer_obj);
        glBindBuffer(GL_ARRAY_BUFFER, buffer_obj);
        glBufferData(GL_ARRAY_BUFFER, (6 * sizeof(float)), &tri_1,
                     GL_STATIC_DRAW);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(void) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "GAME OF LIFE", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Background colour
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // std::cout << glGetString(GL_VERSION) << '\n';

    renderContent(window);

    glfwTerminate();
    return 0;
}
