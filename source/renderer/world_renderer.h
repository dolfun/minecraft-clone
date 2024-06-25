#pragma once
#ifndef WORLDRENDERER_H_INCLUDED
#define WORLDRENDERER_H_INCLUDED

#include "../Shader/WorldShader.h"
#include "../World/Chunk/Chunk.h"
#include "../Entity/Camera.h"
#include "RenderInfo.h"
#include <vector>
#include <string>

class WorldRenderer {
public:
    void addChunk(Chunk& chunk);
    void render(const Camera& camera);
private:
    WorldShader world_shader;
    std::vector<Chunk*> chunks;
};

#endif