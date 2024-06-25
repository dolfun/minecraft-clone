#pragma once
#ifndef CHUNKMANAGER_H_INCLUDED
#define CHUNKMANAGER_H_INCLUDED

#include "ChunkColumn.h"
#include <memory>
#include <unordered_map>

typedef std::unordered_map<vecXZ, ChunkColumn> ChunkMap;

class ChunkManager {
public:
    ChunkManager();

    ChunkColumn& getChunkColumn(int x, int z);
    ChunkMap& getChunkMap();

    void loadChunk(int x, int y, int z);

    bool ChunkColumnGenerated(int x, int z) const;
    bool ChunkColumnLoaded(int x, int z) const;
private:
    ChunkMap chunk_map;
    std::unique_ptr<Generator> generator;
};

#endif