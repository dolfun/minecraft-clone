#include "WorldRenderer.h"
#include <GL/glew.h>
#include "../Utility/Clock.h"
#include <iostream>

void WorldRenderer::addChunk(Chunk& chunk) {
    chunks.push_back(&chunk);
}

void WorldRenderer::render(const Camera& camera) {
    world_shader.bindProgram();

    world_shader.setViewMatrix(camera.getViewMatrix());
    world_shader.setProjectionMatrix(camera.getProjectionMatrix());

    glEnable(GL_CULL_FACE);
    for (auto chunk : chunks) {
        if (chunk->getModel().getRenderInfo().VAO) {
            world_shader.setModelMatrix(chunk->getAnimationMatrix(Clock::getDeltaTime()));
            glBindVertexArray(chunk->getModel().getRenderInfo().VAO);
            glDrawElements(GL_TRIANGLES, chunk->getModel().getRenderInfo().indices_count, GL_UNSIGNED_INT, nullptr);
        }
    }

    chunks.clear();
}