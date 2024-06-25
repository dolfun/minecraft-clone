#pragma once
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "StructureBuilder.h"

struct TreeInfo {
    int tree_height_min;
    int tree_height_max;
    int leaf_span;
};

void makeTree(Chunk& chunk, const TreeInfo& info, int x, int y, int z);

#endif