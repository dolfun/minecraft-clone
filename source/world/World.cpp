#include "World.h"

World::World(const Camera& camera, const Config& config) : camera(&camera) {
    render_distance = config.render_distance;
}

void World::update() {
    loadChunks();
}

void World::loadChunks() {
    int camera_x = camera->position.x / WorldConstants::chunk_size;
    int camera_z = camera->position.z / WorldConstants::chunk_size;

    for (int i = 0; i < render_distance; ++i) {
        int min_x = camera_x - i;
        int min_z = camera_z - i;
        int max_x = camera_x + i;
        int max_z = camera_z + i;
        for (int x = min_x; x < max_x; ++x) {
            for (int z = min_z; z < max_z; ++z) {
                for (int y = 0; y < WorldConstants::chunk_column_height; ++y) {
                    manager.loadChunk(x, y, z);
                    auto& chunk = manager.getChunkColumn(x, z).getChunk(y);
                    if (!chunk.isMeshBuilt()) {
                        chunk.buildMesh(manager);
                        chunk.playAnimation(true);
                    }
                }
            }
        }
    }
}

void World::render(RenderEngine& render_engine, const Camera& camera) {
    auto& chunk_map = manager.getChunkMap();
    constexpr int chunk_size = WorldConstants::chunk_size;
    for (auto itr = chunk_map.begin(); itr != chunk_map.end();) {
        auto& column = itr->second;

        int camera_x = camera.position.x;
        int camera_z = camera.position.z;

        int minX = (camera_x / chunk_size) - render_distance;
        int minZ = (camera_z / chunk_size) - render_distance;
        int maxX = (camera_x / chunk_size) + render_distance;
        int maxZ = (camera_z / chunk_size) + render_distance;

        auto location = column.position;

        if (minX > location.x || minZ > location.z || maxZ < location.z || maxX < location.x) {
            itr = chunk_map.erase(itr);
            continue;
        }
        else {
            for (int i = 0; i < WorldConstants::chunk_column_height; ++i)
                render_engine.renderChunk(column.getChunk(i));
            ++itr;
        }
    }
}