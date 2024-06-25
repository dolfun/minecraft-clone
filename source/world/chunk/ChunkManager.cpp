#include "ChunkManager.h"
#include "../Generation/Terrain/OverworldGenerator.h"

ChunkManager::ChunkManager() {
    generator = std::make_unique<OverworldGenerator>();
}

ChunkColumn& ChunkManager::getChunkColumn(int x, int z) {
    vecXZ key {x, z};
    if (!ChunkColumnGenerated(x, z)) {
        ChunkColumn column;
        column.position = {x, z};
        column.updateChunkPosition();
        chunk_map.emplace(key, std::move(column));
    }

    return chunk_map[key];
}

ChunkMap& ChunkManager::getChunkMap() {
    return chunk_map;
}

void ChunkManager::loadChunk(int x, int y, int z) {
    auto& chunk = getChunkColumn(x, z).getChunk(y);
    if (!chunk.isChunkGenerated()) chunk.generateChunk(*generator);
}

bool ChunkManager::ChunkColumnLoaded(int x, int z) const {
    return chunk_map.find({x, z}) != chunk_map.end();
}

bool ChunkManager::ChunkColumnGenerated(int x, int z) const {
    if (!ChunkColumnLoaded(x, z))
        return false;

    return chunk_map.at({x, z}).isGenerated();
}
