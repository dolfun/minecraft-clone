#include <glm/gtc/matrix_transform.hpp>
#include "Chunk.h"
#include "MeshBuilder.h"

glm::bvec3 Chunk::is_global = {false, false, false};

bool checkOpacity(const Block& block) {
    return block.getData().isOpaque() &&
           block.getData().getBlockShaderType() == BlockShaderType::chunk &&
           block.getData().getBlockMeshType() == BlockMeshType::cube;
}

Block& Chunk::getBlock(int x, int y, int z) {
    constexpr int chunk_size = WorldConstants::chunk_size;
    return blocks[x % chunk_size][y % chunk_size][z % chunk_size];
}

void Chunk::setBlock(BlockID id, int x, int y, int z) {
    constexpr int chunk_size = WorldConstants::chunk_size;
    glm::ivec3 pos = position;
    if (is_global.x) pos.x = x / chunk_size;
    if (is_global.y) pos.y = y / chunk_size;
    if (is_global.z) pos.z = z / chunk_size;
    if (pos == position)
        blocks[x % chunk_size][y % chunk_size][z % chunk_size].setID(id);
}

void Chunk::setPositionMode(bool is_x_global, bool is_y_global, bool is_z_global) {
    is_global = {is_x_global, is_y_global, is_z_global};
}

void Chunk::generateChunk(Generator& generator) {
    generator.generateChunk(*this);
    is_chunk_generated = true;
}

void Chunk::buildMesh(ChunkManager& manager) {
    auto mesh = MeshBuilder::buildMesh(manager, *this, position, checkOpacity);
    if (mesh.vertices.size() != 0)
        model.uploadData(mesh);
    is_mesh_built = true;
}

const Model& Chunk::getModel() const {
    return model;
}

bool Chunk::isMeshBuilt() const {
    return is_mesh_built;
}

bool Chunk::isChunkGenerated() const {
    return is_chunk_generated;
}

int Chunk::getMaxHeight(int x, int z) {
    int y;
    for (int y = WorldConstants::chunk_size - 1; y >= 0; ++y)
        if (getBlock(x, y, z).getID() != BlockID::air) break;
    return y;
}

void Chunk::playAnimation(bool loading) {
    if (loading) loading_direction = 1;
    else loading_direction = -1;
}

const glm::mat4& Chunk::getAnimationMatrix(float dt) {
    if (loading_direction) {
        glm::vec3 direction = glm::vec3(0.0f, 1.0f, 0.0f);
        direction *= loading_direction;
        model_matrix = glm::translate(model_matrix, direction * dt);

        loading_direction *= 0.8f;
        if (loading_direction < 0.1f) loading_direction = 0.0f;
    } else model_matrix = glm::mat4(1.0f);
    return model_matrix;
}