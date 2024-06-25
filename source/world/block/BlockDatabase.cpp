#include "BlockDatabase.h"

BlockDatabase::BlockDatabase() {
    blocks[(int)BlockID::air        ] = std::make_unique<BlockData>("air");
    blocks[(int)BlockID::grass      ] = std::make_unique<BlockData>("grass");
    blocks[(int)BlockID::dirt       ] = std::make_unique<BlockData>("dirt");
    blocks[(int)BlockID::stone      ] = std::make_unique<BlockData>("stone");
    blocks[(int)BlockID::cobblestone] = std::make_unique<BlockData>("cobblestone");
    blocks[(int)BlockID::wood_log   ] = std::make_unique<BlockData>("wood_log");
    blocks[(int)BlockID::leaf       ] = std::make_unique<BlockData>("leaf");
}

BlockDatabase& BlockDatabase::get() {
    static BlockDatabase database;

    return database;
}

void BlockDatabase::loadTextures(int mipmap, int anisotropic_filtering) {
    for (int i = 0; i < blocks.size(); ++i)
        blocks[i]->loadTextures();
    texture_array.loadAllTextures(WorldConstants::texture_size, WorldConstants::texture_size, mipmap, anisotropic_filtering);
}

const BlockData& BlockDatabase::getBlockData(BlockID ID) const {
    return *blocks[(int)ID];
}

TextureArray& BlockDatabase::getTexArray() {
    return texture_array;
}