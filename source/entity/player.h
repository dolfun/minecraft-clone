#pragma once
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "../Renderer/RenderEngine.h"
#include "../Input/Keyboard.h"
#include "../Input/Mouse.h"
#include "../Config.h"
#include "Entity.h"

enum class PlayerMovement {
    forward,
    backward,
    left,
    right,
};

class Player : public Entity {
public:
    Player();
    void handleInput(Keyboard& keyboard, Mouse& mouse);

    void update(float dt);
    void render(RenderEngine& render_engine);
    void setPosition(glm::vec3 poistion);
private:
    void processKeyboard(Keyboard& keyboard);
    void processMouse(Mouse& mouse);
    void move(PlayerMovement direction);
    void updateVectors();
    
    float speed;
    float yaw, pitch, sensitivity;
    bool is_sprinting = false;
    glm::vec3 acceleration;
    Config config;
};

#endif