#pragma once
#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

enum class MouseButton {
    BUTTON_LEFT = GLFW_MOUSE_BUTTON_LEFT,
    BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
    BUTTON_RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
};

class Mouse {
public:
    Mouse();
    glm::vec2 getCursorPos();
    glm::vec2 getOffset();
    bool getMousePress(MouseButton button);
    bool getMouseRelease(MouseButton button);
private:
    glm::vec2 last_pos;
    glm::vec2 current_pos;
};

#endif