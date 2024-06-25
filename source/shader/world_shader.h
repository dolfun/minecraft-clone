#pragma once
#ifndef WORLDSHADER_H_INCLUDED
#define WORLDSHADER_H_INCLUDED

#include "Shader.h"

class WorldShader : public Shader {
public:
    WorldShader();
    void setModelMatrix(const glm::mat4& model) const;
    void setViewMatrix(const glm::mat4& view) const;
    void setProjectionMatrix(const glm::mat4& projection) const;
    void bindTextureArray() const;
};

#endif