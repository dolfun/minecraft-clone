#include "Mouse.h"

Mouse::Mouse() {
    int scr_x, scr_y;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &scr_x, &scr_y);
    last_pos = glm::vec2((double)scr_x / 2.0f, (double)scr_y / 2.0f);
    current_pos = last_pos;
}

glm::vec2 Mouse::getCursorPos() {
    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    glm::vec2 position(xpos, ypos);
    return position;
}

glm::vec2 Mouse::getOffset() {
    current_pos = getCursorPos();
    glm::vec2 offset(current_pos.x - last_pos.x, last_pos.y - current_pos.y);
    last_pos = current_pos;
    return offset;
}

bool Mouse::getMousePress(MouseButton button) {
    if (glfwGetMouseButton(glfwGetCurrentContext(), (int)button ) == GLFW_PRESS)
        return true;
    return false;
}

bool Mouse::getMouseRelease(MouseButton button) {
    if (glfwGetMouseButton(glfwGetCurrentContext(), (int)button ) == GLFW_RELEASE)
        return true;
    return false;
}