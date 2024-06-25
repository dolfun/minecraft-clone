#include "Application.h"
#include "States/PlayingState.h"
#include "World/Block/BlockDatabase.h"
#include "Utility/Random.h"
#include <ctime>

Application::Application(const Config& config) : config(config), context(config), camera(config), debug_key(Key::KEY_G, 0.2f) {
    BlockDatabase::get().loadTextures(config.mipmap, config.anisotropic_filtering);
    Random::setSeed(static_cast<unsigned int>(std::time(nullptr)));
    pushState<StatePlaying>(*this, config, camera);
    is_popstate = false;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &window_x, &window_y);
}

void Application::popState() {
    is_popstate = true;
}

Camera& Application::getCamera() {
    return camera;
}

void Application::start() {
    while (!glfwWindowShouldClose(glfwGetCurrentContext()) && !states.empty()) {
        auto& state = *states.back();

        handleInput();
        state.handleInput();

        state.update(Clock::getDeltaTime());
        camera.update();

        state.render(render_engine);
        render_engine.render(getCamera());

        screenResizeCallback();

        if (is_popstate) {
            is_popstate = false;
            states.pop_back();
        }

        glfwSwapBuffers(glfwGetCurrentContext());
        glfwPollEvents();
    }
    glfwTerminate();
}

void Application::handleInput() {
    if (keyboard.isKeyDown(Key::KEY_ESCAPE)) popState();
    
    render_engine.setDebugState(debug_key.getCurrentState());
}

void Application::screenResizeCallback() {
    int current_x, current_y;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &current_x, &current_y);
    if (window_x != current_x || window_y != current_y) {
        window_x = current_x;
        window_y = current_y;

        render_engine.resizeCallback(window_x, window_y);
    }
}