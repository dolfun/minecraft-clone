#pragma once
#ifndef GENERATION_H_INCLUDED
#define GENERATION_H_INCLUDED

class Chunk;

class Generator {
public:
    virtual void generateChunk(Chunk& chunk) = 0;
};

#endif