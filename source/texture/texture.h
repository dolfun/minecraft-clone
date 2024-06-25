#pragma once
#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <string>

class Texture {
public:
    Texture() = default;
    Texture(std::string path);
    void loadTexture(std::string path);
    void bindTexture() const;

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
    Texture(Texture&&) = delete;
    Texture& operator=(Texture&&) = delete;

    ~Texture();
private:
    unsigned int texture_id;
};

#endif