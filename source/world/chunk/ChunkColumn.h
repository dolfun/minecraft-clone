#pragma once
#ifndef CHUNKCOLUMN_H_INCLUDED
#define CHUNKCOLUMN_H_INCLUDED

#include <array>
#include "Chunk.h"
#include "../../Math/vecXZ.h"

class ChunkColumn {
public:
    ChunkColumn();

    Chunk& getChunk(int y);

    void updateChunkPosition();
    bool isGenerated() const;
    
    vecXZ position;
private:
    std::array<Chunk, WorldConstants::chunk_column_height> chunks;
};

#endif