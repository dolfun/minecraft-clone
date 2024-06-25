#include "Player.h"

Player::Player() : Entity(glm::vec3(0.0f), glm::vec3(0.0f)) {
    position = glm::vec3(0.0f, 10.0f, 0.0f);
    velocity = acceleration = glm::vec3(0.0f);
    front = glm::vec3(1.0f, 0.0f, 0.0f);
    yaw = 90.0f;
    pitch = 0.0f;
    sensitivity = 0.1f;
    speed = 5.0f;
    updateVectors();
}

void Player::handleInput(Keyboard& keyboard, Mouse& mouse) {
    processKeyboard(keyboard);
    processMouse(mouse);
}

void Player::update(float dt) {
    position += velocity * dt;
    velocity *= 0.5f;
}

void Player::render(RenderEngine& render_engine) {
    
}

void Player::setPosition(glm::vec3 position) {
    this->position = position;
}

void Player::move(PlayerMovement direction) {
    float speed_factor = 1.0f;
    if (is_sprinting) speed_factor = 5.0f;
    
    if (direction == PlayerMovement::forward)
        velocity += front * speed * speed_factor;
    else if (direction == PlayerMovement::backward)
        velocity -= front * speed * speed_factor;
    else if (direction == PlayerMovement::left)
        velocity -= right * speed * speed_factor;
    else if (direction == PlayerMovement::right)
        velocity += right * speed * speed_factor;

}

void Player::processKeyboard(Keyboard& keyboard) {
    if (keyboard.isKeyDown(Key::KEY_W))
        move(PlayerMovement::forward);
    if (keyboard.isKeyDown(Key::KEY_S))
        move(PlayerMovement::backward);
    if (keyboard.isKeyDown(Key::KEY_A))
        move(PlayerMovement::left);
    if (keyboard.isKeyDown(Key::KEY_D))
        move(PlayerMovement::right);
    
    is_sprinting = keyboard.isKeyDown(Key::KEY_LEFT_SHIFT);
}

void Player::processMouse(Mouse& mouse) {
    glm::vec2 offset = mouse.getOffset();

    yaw   += offset.x * sensitivity;
    pitch += offset.y * sensitivity;

    auto bound = 89.0f;
    if (pitch >  bound) pitch =  bound;
    if (pitch < -bound) pitch = -bound;
    
    updateVectors();
}

void Player::updateVectors() {
    glm::vec3 new_front;
    glm::vec3 worldup(0.0f, 1.0f, 0.0f);
    new_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    new_front.y = sin(glm::radians(pitch));
    new_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(new_front);
    right = glm::normalize(glm::cross(front, worldup));
    up    = glm::normalize(glm::cross(right, front));
}