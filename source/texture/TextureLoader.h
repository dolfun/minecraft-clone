#pragma once
#ifndef TEXTURELOADER_H_INCLUDED
#define TEXTURELOADER_H_INCLUDED

#include <string>

class TextureLoader {
public:
    static unsigned char* loadData(std::string path, int& width, int& height, int& components, bool flip = true);
    static void freeData(unsigned char* data);
    TextureLoader() = delete;
    TextureLoader(const TextureLoader&) = delete;
    TextureLoader& operator=(const TextureLoader&) = delete;
    TextureLoader(TextureLoader&&) = delete;
    TextureLoader& operator=(TextureLoader&&) = delete;
};

#endif