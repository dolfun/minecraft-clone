#pragma once
#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>
#include <GL/glew.h>
#include "../Renderer/RenderInfo.h"
#include "ChunkMesh.h"

class Model {
public:
    Model() = default;

    template <class T>
    Model(const T& mesh) {
        addData(mesh);
    }

    ~Model();

    Model(const Model& model) = delete;
    Model operator=(const Model& model) = delete;
    Model(Model&& model);
    Model& operator=(Model&& model);

    void deleteData();

    const RenderInfo& getRenderInfo() const;
    void bindVAO() const;

    void uploadData(const ChunkMesh& mesh);

protected:
    void genVAO();

    template<class U>
    void addVBO(int dimensions, const std::vector<U>& data) {
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(U), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(vbo_count, dimensions, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(vbo_count++);
        buffers.push_back(VBO);
    }

    void addEBO(const std::vector<unsigned int>& indices);

private:
    RenderInfo render_info;

    int vbo_count = 0;
    std::vector<unsigned int> buffers;
};

#endif