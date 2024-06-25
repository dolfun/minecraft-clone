#pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <glm/vec3.hpp>
#include "BlockID.h"
#include "BlockData.h"

class Block {
public:
    const BlockID getID() const;
    const BlockData& getData() const;
    void setID(BlockID ID);
    void setOrientation(char orientation);
    void setOrientation(glm::ivec3& vec);
    char getOrientation() const;
    glm::ivec3 getOrientationVector() const;
private:
    BlockID ID = BlockID::air;
    char orientation = 'u';
};

/*Orientation - 
u - up
d - down
l - left
r - right
f - front
b - back*/

#endif