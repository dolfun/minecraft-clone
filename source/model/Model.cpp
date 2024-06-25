#include "Model.h"


Model::~Model() {
    deleteData();
}

Model::Model(Model&& model) : render_info(model.render_info), vbo_count(model.vbo_count), buffers(std::move(model.buffers)) {
    model.render_info.reset();
    model.vbo_count = 0;
}

Model& Model::operator=(Model&& model) {
    this->render_info = model.render_info;
    this->vbo_count = model.vbo_count;
    this->buffers = std::move(model.buffers);

    model.render_info.reset();
    model.vbo_count = 0;

    return *this;
}

void Model::deleteData() {
    if (render_info.VAO)
        glDeleteVertexArrays(1, &render_info.VAO);
    if (buffers.size() > 0)
        glDeleteBuffers(buffers.size(), buffers.data());
    buffers.clear();
    vbo_count = 0;
    render_info.reset();
}

const RenderInfo& Model::getRenderInfo() const  {
    return render_info;
}

void Model::bindVAO() const {
    glBindVertexArray(render_info.VAO);
}

void Model::uploadData(const ChunkMesh& mesh) {
    deleteData();
    genVAO();
    addVBO<glm::vec3>(3, mesh.vertices);
    addVBO<glm::vec3>(3, mesh.normals);
    addVBO<glm::vec2>(2, mesh.tex_coords);
    addVBO<glm::vec3>(3, mesh.tex_indices);
    addVBO<glm::vec3>(3, mesh.orientations);
    addEBO(mesh.indices);
}

void Model::genVAO() {
    if(render_info.VAO != 0)
        deleteData();
    
    glGenVertexArrays(1, &render_info.VAO);
    glBindVertexArray(render_info.VAO);
}

void Model::addEBO(const std::vector<unsigned int>& indices) {
    render_info.indices_count = indices.size();

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}