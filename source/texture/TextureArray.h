#pragma once
#ifndef TEXTUREARRAY_H_INCLUDED
#define TEXTUREARRAY_H_INCLUDED

#include <string>
#include <vector>

class TextureArray {
public:
    TextureArray() = default;
    void addTexturePath(std::string path);
    void loadAllTextures(int tex_width, int tex_height, int mipmap, float anisotropic_filtering);
    void bindTextureArray() const;
    int getCurrentIndex() const;

    TextureArray(const TextureArray&) = delete;
    TextureArray& operator=(const TextureArray&) = delete;
    TextureArray(TextureArray&&) = delete;
    TextureArray& operator=(TextureArray&&) = delete;

    ~TextureArray();
private:
    std::vector<std::string> paths;
    unsigned int ID;
    int current_index = 0;
};

#endif