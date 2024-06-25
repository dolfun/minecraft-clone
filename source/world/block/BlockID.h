#pragma once
#ifndef BLOCKID_H_INCLUDED
#define BLOCKID_H_INCLUDED

#include "../WorldConstants.h"

typedef int block_id;

enum class BlockID : block_id {
    air = 0,
    grass = 1,
    dirt = 2,
    stone = 3,
    cobblestone = 4,
    wood_log = 5,
    leaf = 6,
    number_of_blocks,
};

#endif