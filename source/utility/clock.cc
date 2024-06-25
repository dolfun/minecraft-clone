#include "Clock.h"
#include <GLFW/glfw3.h>

double Clock::previous_time = 0.0f;
double Clock::current_time = 0.0f;
double Clock::delta_time = 0.0f;

double Clock::getTime() {
    return glfwGetTime();
}

double Clock::getDeltaTime() {
    current_time = glfwGetTime();
    delta_time = current_time - previous_time;
    previous_time = current_time;
    return delta_time;
}