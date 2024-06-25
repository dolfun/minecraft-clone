#pragma once
#ifndef FLATWORLDGENERATOR_H_INCLUDED
#define FLATWORLDGENERATOR_H_INCLUDED

#include "Generator.h"

class FlatWorldGenerator : public Generator {
public:
    void generateChunk(Chunk& chunk);
};

#endif