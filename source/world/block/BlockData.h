#pragma once
#ifndef BLOCKDATA_H_INCLUDED
#define BLOCKDATA_H_INCLUDED

#include <string>
#include <glm/glm.hpp>
#include "BlockID.h"

enum class BlockMeshType {
    cube = 0,
    half_slab = 1,
};

enum class BlockShaderType {
    chunk = 0,
    flora = 1,
};

struct BlockData {
    BlockData(std::string name);
    
    const BlockID& getID() const;
    const BlockMeshType& getBlockMeshType() const;
    const BlockShaderType& getBlockShaderType() const;
    bool isOpaque() const;
    const glm::ivec3& getTexIndex() const;

    BlockData(const BlockData&) = delete;
    BlockData& operator=(const BlockData&) = delete;
    BlockData(BlockData&&) = delete;
    BlockData& operator=(BlockData&&) = delete;
private:
    friend class BlockDatabase;
    void loadTextures();

    BlockID ID;
    BlockMeshType mesh_type;
    BlockShaderType shader_type;
    bool is_opaque;

    glm::ivec3 tex_index;

    std::string tex_names[4]; // 0 - all, 1 - top, 2 - side, 3 - bottom
};

#endif