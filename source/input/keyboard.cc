#include "Keyboard.h"
#include "../Utility/Clock.h"
#include <GLFW/glfw3.h>

bool Keyboard::isKeyDown(Key key) {
    if (glfwGetKey(glfwGetCurrentContext(), (int)key ) == GLFW_PRESS)
        return true;
    return false;
}

bool Keyboard::keyReleased(Key key) {
    if (glfwGetKey(glfwGetCurrentContext(), (int)key ) == GLFW_RELEASE)
        return true;
    return false;
}

ToggleKey::ToggleKey(Key key) {
    setKey(key);
}

ToggleKey::ToggleKey(Key key, float seconds) {
    setKey(key, seconds);
}

void ToggleKey::setKey(Key key, float seconds) {
    this->key = key;
    this->seconds = seconds;
}

bool ToggleKey::getCurrentState() {
    static float t1, t2;
    if (glfwGetKey(glfwGetCurrentContext(), (int)key ) == GLFW_PRESS && !is_togglable) {
        is_togglable = true;
        current_state = !current_state;
        t1 = Clock::getTime();
    }
    if (glfwGetKey(glfwGetCurrentContext(), (int)key ) == GLFW_RELEASE || (seconds != -1.0f && t2 - t1 >= seconds)) {
        is_togglable = false;
    }
    t2 = Clock::getTime();
        
    return current_state;
}