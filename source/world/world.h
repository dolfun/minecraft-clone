#pragma once
#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "../Config.h"
#include "../Renderer/RenderEngine.h"
#include "../Entity/Camera.h"
#include "Chunk/ChunkManager.h"

class World {
public:
    World(const Camera& camera, const Config& config);
    void render(RenderEngine& render_engine, const Camera& camera);

    void update();
    void loadChunks();

    World(const World& world) = delete;
    World operator=(const World& world) = delete;
    World(World&& world);
    World& operator=(World&& world);
private:
    int render_distance;
    ChunkManager manager;
    const Camera* camera;
};

#endif