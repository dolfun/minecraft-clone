#pragma once
#ifndef CHUNKMESH_H_INCLUDED
#define CHUNKMESH_H_INCLUDED

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct ChunkMesh {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> tex_coords;
    std::vector<glm::vec3> tex_indices;
    std::vector<glm::vec3> orientations;
    std::vector<unsigned int> indices;
};

#endif