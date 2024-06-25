#include "RenderEngine.h"
#include <glad/glad.h>

void RenderEngine::renderChunk(Chunk& chunk) {
    world_renderer.addChunk(chunk);
}

void RenderEngine::render(const Camera& camera) {
    glClearColor(0.40f, 0.76f, 0.96f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    if (debug) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    world_renderer.render(camera);
}

void RenderEngine::resizeCallback(int window_x, int window_y) {
    glViewport(0, 0, window_x, window_y);
}

void RenderEngine::setDebugState(bool state) {
    debug = state;
}
