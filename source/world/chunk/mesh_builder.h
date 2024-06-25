#pragma once
#ifndef MESHBUILDER_H_INCLUDED
#define MESHBUILDER_H_INCLUDED

#include "Chunk.h"
#include "../../Model/ChunkMesh.h"
#include "ChunkManager.h"
#include <glm/glm.hpp>

namespace MeshBuilder {
    ChunkMesh buildMesh(ChunkManager& manager, Chunk& chunk, glm::vec3 position, bool (*check)(const Block&));
};

#endif