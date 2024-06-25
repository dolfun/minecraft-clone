#include "WorldShader.h"
#include <glad/glad.h>

WorldShader::WorldShader() {
    std::string vertex_shader_path("resources/shaders/WorldShader.vs"), fragment_shader_path("resources/shaders/WorldShader.fs");
    load(vertex_shader_path, GL_VERTEX_SHADER);
    load(fragment_shader_path, GL_FRAGMENT_SHADER);
    attach();
}

void WorldShader::setModelMatrix(const glm::mat4& model) const {
    setMat4("model", model);
}

void WorldShader::setViewMatrix(const glm::mat4& view) const {
    setMat4("view", view);
}

void WorldShader::setProjectionMatrix(const glm::mat4& projection) const {
    setMat4("projection", projection);
}

void WorldShader::setCameraPos(const glm::vec3& camera_pos) const {
    setVec3("camera_pos", camera_pos);
}

void WorldShader::bindTextureArray() const {
    setInt("texture_array", 0);
}