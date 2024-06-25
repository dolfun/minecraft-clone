#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const Config& config) : config(config), Entity(glm::vec3(0.0f), glm::vec3(0.0f)) {
    fov = config.fov;
}

void Camera::update() {
    float yoffset = 0.6f;
    position = entity->position;
    position.y += yoffset;

    front = entity->front;
    right = entity->right;
    up = entity->up;

    view = glm::lookAt(position, position + front, up);
    float far_point = 500.0f;
    projection = glm::perspective(glm::radians(fov), static_cast<float>(config.window_x) / static_cast<float>(config.window_y), 0.1f, far_point);
}

void Camera::hookEntity(const Entity& entity) {
    this->entity = &entity;
}

const glm::mat4& Camera::getViewMatrix() const {
    return view;
}

const glm::mat4& Camera::getProjectionMatrix() const {
    return projection;
}