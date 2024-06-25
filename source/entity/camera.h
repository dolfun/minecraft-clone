#pragma once
#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <glm/glm.hpp>
#include "Entity.h"
#include "../Config.h"

class Camera : public Entity {
public:
    Camera(const Config& config);
    void update();
    void hookEntity(const Entity& enitity);
    const glm::mat4& getViewMatrix() const;
    const glm::mat4& getProjectionMatrix() const;
private:
    const Entity* entity;
    float fov;
    glm::mat4 projection, view;
    float far_point;
    Config config;
};

#endif