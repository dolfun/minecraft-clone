#include "FlatWorldGenerator.h"
#include "../Structure/Tree.h"
#include "../../Chunk/Chunk.h"
#include "../../../Utility/Random.h"

void FlatWorldGenerator::generateChunk(Chunk& chunk) {
    constexpr int chunk_size = WorldConstants::chunk_size;
    Chunk::setPositionMode(false, true, false);

    for (int x = 0; x < chunk_size; ++x) {
        for (int z = 0; z < chunk_size; ++z) {
            chunk.setBlock(BlockID::stone, x, 0, z);

            int y_terrain = 20;
            for (int i = 1; i < y_terrain; ++i)
                chunk.setBlock(BlockID::dirt, x, i, z);
            
            chunk.setBlock(BlockID::grass, x, y_terrain, z);
        }
    }
    
    Chunk::setPositionMode(false, false, false);
}
