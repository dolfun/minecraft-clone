#pragma once
#ifndef OVERWORLDGENERATOR_H_INCLUDED
#define OVERWORLDGENERATOR_H_INCLUDED

#include "Generator.h"

class OverworldGenerator : public Generator {
public:
    void generateChunk(Chunk& chunk);
};

#endif