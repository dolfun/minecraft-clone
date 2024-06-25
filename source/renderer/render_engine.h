#pragma once
#ifndef RENDERENGINE_H_INCLUDED
#define RENDERENGINE_H_INCLUDED

#include "../World/Chunk/Chunk.h"
#include "../Entity/Camera.h"
#include "WorldRenderer.h"

class RenderEngine {
public:
    void renderChunk(Chunk& chunk);
    void render(const Camera& camera);
    void resizeCallback(int window_x, int window_y);
    void setDebugState(bool state);
private:
    WorldRenderer world_renderer;
    bool debug = false;
};

#endif