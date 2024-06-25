#include "Block.h"
#include "BlockDatabase.h"

const BlockID Block::getID() const {
    return ID;
}

const BlockData& Block::getData() const {
    return BlockDatabase::get().getBlockData(ID);
}

void Block::setID(BlockID ID) {
    this->ID = ID;
}

void Block::setOrientation(char orientation) {
    this->orientation = orientation;
}

void Block::setOrientation(glm::ivec3& vec) {
    if      (vec == glm::ivec3( 0,  1,  0)) orientation = 'u';
    else if (vec == glm::ivec3( 0, -1,  0)) orientation = 'd';
    else if (vec == glm::ivec3(-1,  0,  0)) orientation = 'l';
    else if (vec == glm::ivec3( 1,  0,  0)) orientation = 'r';
    else if (vec == glm::ivec3( 0,  0,  1)) orientation = 'f';
    else if (vec == glm::ivec3( 0,  0, -1)) orientation = 'b';
    else orientation = 'n';
}

char Block::getOrientation() const {
    return orientation;
}

glm::ivec3 Block::getOrientationVector() const {
    if (orientation == 'u') return glm::ivec3( 0,  1,  0);
    if (orientation == 'd') return glm::ivec3( 0, -1,  0);
    if (orientation == 'l') return glm::ivec3(-1,  0,  0);
    if (orientation == 'r') return glm::ivec3( 1,  0,  0);
    if (orientation == 'f') return glm::ivec3( 0,  0,  1);
    if (orientation == 'b') return glm::ivec3( 0,  0, -1);
    return glm::ivec3(0);
}