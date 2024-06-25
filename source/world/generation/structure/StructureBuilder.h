#pragma once
#ifndef STRUCTUREBUILDER_H_INCLUDED
#define STRUCTUREBUILDER_H_INCLUDED

#include <vector>
#include "../../Block/BlockID.h"

class Chunk;

class StructureBuilder {
    struct Block {
        Block(BlockID id, int x, int y, int z) : id (id), x(x), y(y), z(z) {}

        BlockID id;
        int x, y, z;
    };
public:
    void build(Chunk& chunk, bool to_override = false);

    void makeColumn(BlockID id, int x, int y, int z, int height);
    void makeRowX  (BlockID id, int x, int y, int z, int length);
    void makeRowZ  (BlockID id, int x, int y, int z, int length);
    void fillLayer (BlockID id, int y, int x_start, int x_end, int z_start, int z_end);

    void addBlock(BlockID id, int x, int y, int z);
private:
    std::vector<Block> blocks;
};

#endif