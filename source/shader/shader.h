#pragma once
#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/matrix.hpp>

struct ShaderInfo {
    unsigned int shader;
    unsigned int shader_type;
};

class Shader {
public:
    void bindProgram();
private:
    std::vector<unsigned int> shaders;
    unsigned int shader_program;
protected:
    void load(std::string path, unsigned int shader_type);
    void attach();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec2(const std::string& name, const glm::vec2& vec) const;
    void setVec3(const std::string& name, const glm::vec3& vec) const;
    void setVec4(const std::string& name, const glm::vec4& vec) const;
    void setMat2(const std::string& name, const glm::mat2& mat) const;
    void setMat3(const std::string& name, const glm::mat3& mat) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;
};

#endif