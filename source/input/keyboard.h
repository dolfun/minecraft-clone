#pragma once
#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include "Key.h"

class Keyboard {
public:
    bool isKeyDown(Key key);
    bool keyReleased(Key key);
};

class ToggleKey {
public:
    ToggleKey() = default;
    ToggleKey(Key key);
    ToggleKey(Key key, float seconds);
    void setKey(Key key, float seconds = -1.0f);
    bool getCurrentState();
private:
    Key key;
    float seconds;
    bool current_state = false;
    bool is_togglable = false;
};

#endif