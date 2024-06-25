#include "Tree.h"
#include "../../../Utility/Random.h"

void makeTree(Chunk& chunk, const TreeInfo& info, int x, int y, int z) {
    StructureBuilder builder;

    int height = Random::intInRange(info.tree_height_min, info.tree_height_max);
    builder.makeColumn(BlockID::wood_log, x, y, z, height);
    for (int i = info.tree_height_min; i <= height; ++i) {
        int leaf_span = info.leaf_span - (i - info.tree_height_min);
        builder.fillLayer(BlockID::leaf, y + i, x - leaf_span, x + leaf_span, z - leaf_span, z + leaf_span);
    }

    builder.build(chunk);
}