#include "OverworldGenerator.h"
#include "../Structure/Tree.h"
#include "../../Chunk/Chunk.h"
#include "../../../Utility/Random.h"
#include <glm/gtc/noise.hpp>

void OverworldGenerator::generateChunk(Chunk& chunk) {
    constexpr int chunk_size = WorldConstants::chunk_size;
    Chunk::setPositionMode(false, true, false);

    for (int x = 0; x < chunk_size; ++x) {
        for (int z = 0; z < chunk_size; ++z) {
            chunk.setBlock(BlockID::stone, x, 0, z);

            int global_x = chunk.position.x * chunk_size + x;
            int global_z = chunk.position.z * chunk_size + z;
            float height = glm::perlin(glm::vec2(static_cast<float>(global_x) / static_cast<float>(chunk_size), static_cast<float>(global_z) / static_cast<float>(chunk_size)));

            int y_terrain = glm::abs(height) * 20;
            for (int i = 1; i < y_terrain; ++i)
                chunk.setBlock(BlockID::dirt, x, i, z);
            
            chunk.setBlock(BlockID::grass, x, y_terrain, z);
        }
    }
    
    Chunk::setPositionMode(false, false, false);
}
