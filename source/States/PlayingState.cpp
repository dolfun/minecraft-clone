#include "PlayingState.h"

StatePlaying::StatePlaying(Application& application, const Config& config, const Camera& camera) : StateBase(application), world(camera, config) {
    application.getCamera().hookEntity(player);
}

void StatePlaying::init() {

}

void StatePlaying::handleInput() {
    player.handleInput(keyboard, mouse);
}

void StatePlaying::update(float dt) {
    player.update(dt);
    world.update();
}

void StatePlaying::render(RenderEngine& render_engine) {
    world.render(render_engine, application.getCamera());
}