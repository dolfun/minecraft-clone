#include "StructureBuilder.h"
#include "../../Chunk/Chunk.h"

void StructureBuilder::build(Chunk& chunk, bool to_override) {
    Chunk::setPositionMode(false, true, false);
    for (auto& block : blocks) {
        if (!to_override && chunk.getBlock(block.x, block.y, block.z).getID() == BlockID::air)
            chunk.setBlock(block.id, block.x, block.y, block.z);
    }
    Chunk::setPositionMode(false, false, false);
}

void StructureBuilder::makeColumn(BlockID id, int x, int y, int z, int height) {
    for (int i = y; i < y + height; ++i) {
        addBlock(id, x, i, z);
    }
}

void StructureBuilder::makeRowX(BlockID id, int x, int y, int z, int length) {
    for (int i = x; i < x + length; ++i) {
        addBlock(id, i, y, z);
    }
}

void StructureBuilder::makeRowZ(BlockID id, int x, int y, int z, int length) {
    for (int i = z; i < z + length; ++i) {
        addBlock(id, x, y, i);
    }
}

void StructureBuilder::fillLayer(BlockID id, int y, int x_start, int x_end, int z_start, int z_end) {
    for (int x = x_start; x < x_end; ++x)
        for (int z = z_start; z < z_end; ++z)
            addBlock(id, x, y, z);
}

void StructureBuilder::addBlock(BlockID id, int x, int y, int z) {
    blocks.emplace_back(id, x, y, z);
}

