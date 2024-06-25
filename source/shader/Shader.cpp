#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

void Shader::bindProgram() {
    glUseProgram(shader_program);
}

void Shader::load(std::string path, unsigned int shader_type) {
    unsigned int shader;
    std::string source;
    std::ifstream shader_file(path);

    if (shader_file.is_open()) {
        std::stringstream buffer;
        buffer << shader_file.rdbuf();
        shader_file.close();
        source = buffer.str();
    }
    else std::cerr << "Failed to open file - " << path << std::endl;
    
    shader = glCreateShader(shader_type);
    const char* source_c_str = source.c_str();
    glShaderSource(shader, 1, &source_c_str, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << std::string(infoLog) << std::endl;
    }
    shaders.push_back(shader);
}

void Shader::attach() {
    shader_program = glCreateProgram();
    for (int i = 0; i < shaders.size(); i++)
        glAttachShader(shader_program, shaders[i]);
    glLinkProgram(shader_program);

    int success;
    char infoLog[512];
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        std::cerr << infoLog << std::endl;
    }

    for (int i = 0; i < shaders.size(); i++)
        glDeleteShader(shaders[i]);
}

void Shader::setBool(const std::string& name, bool value) const {         
    glUniform1i(glGetUniformLocation(shader_program, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, int value) const { 
    glUniform1i(glGetUniformLocation(shader_program, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, float value) const { 
    glUniform1f(glGetUniformLocation(shader_program, name.c_str()), value);
}
void Shader::setVec2(const std::string& name, const glm::vec2& value) const { 
    glUniform2fv(glGetUniformLocation(shader_program, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string& name, const glm::vec3& value) const { 
    glUniform3fv(glGetUniformLocation(shader_program, name.c_str()), 1, &value[0]);
}
void Shader::setVec4(const std::string& name, const glm::vec4& value) const { 
    glUniform3fv(glGetUniformLocation(shader_program, name.c_str()), 1, &value[0]);
}
void Shader::setMat2(const std::string& name, const glm::mat2& mat) const {
    glUniformMatrix2fv(glGetUniformLocation(shader_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::setMat3(const std::string& name, const glm::mat3& mat) const {
    glUniformMatrix3fv(glGetUniformLocation(shader_program, name.c_str()), 1, GL_FALSE, &mat[0][0]); 
}
void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
    glUniformMatrix4fv(glGetUniformLocation(shader_program, name.c_str()), 1, GL_FALSE, &mat[0][0]); 
}