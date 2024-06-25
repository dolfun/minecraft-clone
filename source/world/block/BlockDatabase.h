#pragma once
#ifndef BLOCKDATABASE_H_INCLUDED
#define BLOCKDATABASE_H_INCLUDED

#include "BlockData.h"
#include "../../Texture/TextureArray.h"
#include <memory>

class BlockDatabase {
public:
    static BlockDatabase& get();
    void loadTextures();
    const BlockData& getBlockData(BlockID ID) const;
    TextureArray& getTexArray();

    BlockDatabase(const BlockDatabase&) = delete;
    BlockDatabase& operator=(const BlockDatabase&) = delete;
    BlockDatabase(BlockDatabase&&) = delete;
    BlockDatabase& operator=(BlockDatabase&&) = delete;
private:
    BlockDatabase();

    std::array<std::unique_ptr<BlockData>, (int)BlockID::number_of_blocks> blocks;
    TextureArray texture_array;
};

#endif