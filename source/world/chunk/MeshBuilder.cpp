#include "MeshBuilder.h"
#include <vector>
#include <iostream>

struct Face {
    Block block;
    glm::vec3 normal = glm::vec3(0.0f);
    bool is_null = true;

    bool operator==(const Face& face) {
        return (this->block.getData().getTexIndex() == face.block.getData().getTexIndex()) &&
               (this->block.getOrientation() == face.block.getOrientation()) &&
               (this->normal == face.normal);
    }
} null_face;

void setFaceData(Face& face, const Block& block);
void addFaceToMesh(ChunkMesh& mesh, const Face& face, glm::vec3 pos, glm::vec3 dj, glm::vec3 dk, glm::vec3 trans_position);
bool isEmpty(Chunk& chunk);

ChunkMesh MeshBuilder::buildMesh(ChunkManager& manager, Chunk& chunk, glm::vec3 position, bool (*check)(const Block&)) {
    constexpr int chunk_size = WorldConstants::chunk_size;
    ChunkMesh chunk_mesh;
    Face mask[chunk_size][chunk_size];

    if (isEmpty(chunk)) return chunk_mesh;

    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        glm::ivec3 pos(0), dir(0);
        dir[i] = 1;
        
        for (pos[i] = -1; pos[i] < chunk_size;) {
            for (pos[j] = 0; pos[j] < chunk_size; ++pos[j]) {
                for (pos[k] = 0; pos[k] < chunk_size; ++pos[k]) {
                    Face face1, face2;

                    if (pos[i] >= 0) setFaceData(face1, chunk.getBlock(pos.x, pos.y, pos.z));
                    if (pos[i] < chunk_size - 1) setFaceData(face2, chunk.getBlock(pos.x + dir.x, pos.y + dir.y, pos.z + dir.z));

                    if (check(face1.block) == check(face2.block))
                        mask[pos[j]][pos[k]] = null_face;
                    else if (check(face1.block)) {
                        face1.normal = dir;
                        mask[pos[j]][pos[k]] = face1;
                    }
                    else if (check(face2.block)) {
                        face2.normal = -dir;
                        mask[pos[j]][pos[k]] = face2;
                    }
                }
            }
            ++pos[i];
            for (int n = 0; n < chunk_size; ++n) {
                for (int m = 0; m < chunk_size; ++m) {
                    if (!mask[m][n].is_null) {
                        int width, height;
                        for (width = 1; m + width < chunk_size && mask[m][n] == mask[m + width][n]; ++width);

                        bool to_break = false;
                        for (height = 1; n + height < chunk_size; ++height) {
                            for (int l = 0; l < width; ++l) {
                                if (!(mask[m][n] == mask[m + l][n + height])) {
                                    to_break = true;
                                    break;
                                }
                            }
                            if (to_break) break;
                        }

                        pos[j] = m;
                        pos[k] = n;
                        glm::ivec3 dj(0), dk(0);
                        dj[j] = width;
                        dk[k] = height;
                        
                        addFaceToMesh(chunk_mesh, mask[m][n], pos, dj, dk, (float)WorldConstants::chunk_size * position);

                        for (int b = 0; b < height; ++b)
                            for (int a = 0; a < width; ++a)
                                mask[m + a][n + b] = null_face;
                    };
                }
            }
        }
    }
    return chunk_mesh;
}

void setFaceData(Face& face, const Block& block) {
    face.is_null = false;
    face.block = block;
}

void addFaceToMesh(ChunkMesh& mesh, const Face& face, glm::vec3 pos, glm::vec3 dj, glm::vec3 dk, glm::vec3 trans_position) {
    glm::vec3 normal = face.normal;
    int vertex_count = mesh.vertices.size();

    std::array<glm::vec3, 4> vertices = {
        pos,
        pos + dj,
        pos + dj + dk,
        pos + dk,
    };

    for (auto& vertex : vertices) {
        mesh.vertices.push_back(vertex + trans_position);
        mesh.normals.push_back(normal);

        glm::vec2 tex_coord;
        if      (normal.x != 0.0f) tex_coord = glm::vec2(vertex.z, vertex.y);
        else if (normal.y != 0.0f) tex_coord = glm::vec2(vertex.x, vertex.z);
        else if (normal.z != 0.0f) tex_coord = glm::vec2(vertex.x, vertex.y);

        if (tex_coord.x == -1.0f) tex_coord.x = 0.0f;
        if (tex_coord.y == -1.0f) tex_coord.y = 0.0f;
        mesh.tex_coords.push_back(tex_coord);
        mesh.tex_indices.push_back(face.block.getData().getTexIndex());
        mesh.orientations.push_back(face.block.getOrientationVector());
    }

    std::vector<unsigned int> indices;
    if (normal.x == 1.0f || normal.y == 1.0f || normal.z == 1.0f)
         indices = { 0, 1, 2, 2, 3, 0, };
    else indices = { 0, 2, 1, 2, 0, 3, };
    for (auto index : indices)
        mesh.indices.push_back(vertex_count + index);
} 

bool isEmpty(Chunk& chunk) {
    for (int z = 0; z < WorldConstants::chunk_size; ++z)
        for (int y = 0; y < WorldConstants::chunk_size; ++y)
            for (int x = 0; x < WorldConstants::chunk_size; ++x)
                if (chunk.getBlock(x, y, z).getID() != BlockID::air) return false;
    return true;
}