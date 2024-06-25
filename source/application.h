#pragma once
#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>
#include <memory>
#include "Context.h"
#include "Input/Keyboard.h"
#include "Renderer/RenderEngine.h"
#include "States/StateBase.h"
#include "Entity/Camera.h"
#include "Utility/Clock.h"
#include "Config.h"

class Application {
public:
    Application(const Config& config);

    template<typename T, typename... Args> 
    void pushState(Args&&... args) {
        states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        auto& s = states.back();
        s->init();
    }
    void popState();

    Camera& getCamera();
    void start();
private:
    Camera camera;
    const Config& config;
    Context context;
    RenderEngine render_engine;
    std::vector<std::unique_ptr<StateBase>> states;
    bool is_popstate;

    Keyboard keyboard;
    ToggleKey debug_key;
    void handleInput();
    void screenResizeCallback();
    int window_x, window_y;
};

#endif