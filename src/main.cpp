#define GL_SILENCE_DEPRECATION

#include "../include/GLFW/glfw3.h"
#include "../include/apple.h"
#include "../include/templates.h"

#include <iostream>

// https://stackoverflow.com/a/67585643

// This is a openGL Shading Language file stored in a c-style string
const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

unsigned int renderShaders() {
    // Vertex Shader
    unsigned int vertexShader; // VBO
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Fragment Shader - used for specific shapes on the screen
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Error checking
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Link shaders to a shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // Linking Vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram);

    // After it's linked to the program, the shaders aren't needed and can be
    // deleted
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return vertexShader;
}

void vertexArrayObj(unsigned int VBO, Triangle2d my_tri) {
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(my_tri), &my_tri, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);
}

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

        auto VBO = renderShaders();
        vertexArrayObj(VBO, tri_1);

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
    //  4.1 INTEL-18.7.4

    renderContent(window);

    glfwTerminate();
    return 0;
}
