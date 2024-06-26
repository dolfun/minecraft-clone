#pragma once
#ifndef CONTEXT_H_INCLUDED
#define CONTEXT_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "config.h"

class Context {
public:
    Context(const Config& config);
private:
    GLFWwindow* window;
};

#endif