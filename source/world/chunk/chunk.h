#pragma once
#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include <array>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include "../Block/Block.h"
#include "../../Model/Model.h"
#include "../Generation/Terrain/Generator.h"

class ChunkManager;

class Chunk {
public:
    Block& getBlock(int x, int y, int z);
    void setBlock(BlockID id, int x, int y, int z);

    static void setPositionMode(bool is_x_global, bool is_y_global, bool is_z_global);

    void generateChunk(Generator& generator);
    void buildMesh(ChunkManager& manager);

    const Model& getModel() const;

    bool isMeshBuilt() const;
    bool isChunkGenerated() const;

    int getMaxHeight(int x, int z);

    void playAnimation(bool loading);
    const glm::mat4& getAnimationMatrix(float dt);

    glm::ivec3 position;
private:
    friend class ChunkManager;
    Block blocks[WorldConstants::chunk_size][WorldConstants::chunk_size][WorldConstants::chunk_size];
    Model model;
    
    bool is_mesh_built = false, is_chunk_generated = false;
    static glm::bvec3 is_global;

    float loading_direction = 0.0f;
    glm::mat4 model_matrix = glm::mat4(1.0f);
};

#endif