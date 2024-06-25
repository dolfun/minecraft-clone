#pragma once
#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <glm/vec3.hpp>

class Entity {
public:
    Entity(glm::vec3 position, glm::vec3 front) {
        this->position = position;
        this->front    = front;
        up             = glm::vec3(0.0f, 1.0f, 0.0f);
        velocity       = glm::vec3(0.0f);
    }

    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 velocity;
};

#endif