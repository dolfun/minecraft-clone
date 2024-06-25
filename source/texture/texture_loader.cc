#include "TextureLoader.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

unsigned char* TextureLoader::loadData(std::string path, int& width, int& height, int& components, bool flip) {
    stbi_set_flip_vertically_on_load(flip);
    return stbi_load(path.c_str(), &width, &height, &components, 0);
}

void TextureLoader::freeData(unsigned char* data) {
    stbi_image_free(data);
}