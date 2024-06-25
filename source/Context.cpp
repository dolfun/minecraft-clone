#include "context.h"
#include "Utility/GLDebug.h"
#include <iostream>

Context::Context(const Config& config) {
    if (!glfwInit())
        std::cerr << "Failed to initialize GLFW." << std::endl;
    
    if (config.MSAA) glfwWindowHint(GLFW_SAMPLES, config.MSAA);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (config.debug) glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

    window = glfwCreateWindow(config.window_x, config.window_y, "minecraft-clone", config.fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

    if (window == NULL) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    gladLoadGL();

    if (config.debug) {
        std::cout << "Debug mode is on." << std::endl;
        GLint flags;
        glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(glDebugOutput, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
        }
    }

    if (config.MSAA) glEnable(GL_MULTISAMPLE);
}