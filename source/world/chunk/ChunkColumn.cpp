#include "ChunkColumn.h"

ChunkColumn::ChunkColumn() {
    for (int y = 0; y < WorldConstants::chunk_column_height; ++y) {
        chunks[y].position.y = y;
    }
}

Chunk& ChunkColumn::getChunk(int y) {
    return chunks[y];
}

void ChunkColumn::updateChunkPosition() {
    for (auto& chunk : chunks) {
        chunk.position.x = position.x;
        chunk.position.z = position.z;
    }
}

bool ChunkColumn::isGenerated() const {
    for (auto& chunk : chunks)
        if (chunk.isChunkGenerated()) return true;
    return false;
}