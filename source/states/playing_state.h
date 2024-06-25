#pragma once
#ifndef PLAYINGSTATE_H_INCLUDED
#define PLAYINGSTATE_H_INCLUDED

#include "StateBase.h"
#include "../Application.h"
#include "../Input/Keyboard.h"
#include "../Input/Mouse.h"
#include "../Entity/Player.h"
#include "../Entity/Camera.h"
#include "../World/World.h"

class StatePlaying : public StateBase {
public:
    StatePlaying(Application& application, const Config& config, const Camera& camera);
    void init();
    void handleInput();
    void update(float dt);
    void render(RenderEngine& render_engine);
    ~StatePlaying() = default;
private:
    Keyboard keyboard;
    Mouse mouse;
    Player player;
    World world;
};

#endif