#include "Texture.h"
#include "TextureLoader.h"
#include <glad/glad.h>
#include <iostream>

Texture::Texture(std::string path) {
    loadTexture(path);
}

void Texture::loadTexture(std::string path) {
    glGenTextures(1, &texture_id);

    int width, height, components;
    unsigned char* data = TextureLoader::loadData(path, width, height, components);
    if (data) {
        unsigned int format;
        if (components == 1)
            format = GL_RED;
        else if (components == 3)
            format = GL_RGB;
        else if (components == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else std::cerr << "Failed to load texture - " << path << std::endl;

    TextureLoader::freeData(data);
}

void Texture::bindTexture() const {
    glBindTexture(GL_TEXTURE_2D, texture_id);
}

Texture::~Texture() {
    glDeleteTextures(1, &texture_id);
}