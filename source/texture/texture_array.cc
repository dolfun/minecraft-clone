#include "TextureArray.h"
#include "TextureLoader.h"
#include <GL/glew.h>
#include <iostream>

void TextureArray::addTexturePath(std::string path) {
    paths.push_back(path);
    ++current_index;
}

void TextureArray::loadAllTextures(int tex_width, int tex_height, int mipmap, float anisotropic_filtering) {
    if (ID) return;
    unsigned int format = GL_RGBA;

    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D_ARRAY, ID);

    if (mipmap) {
        for (int i = 0; i < mipmap; ++i) {
            glTexImage3D(GL_TEXTURE_2D_ARRAY, i, format, tex_width, tex_height, paths.size(), 0, format, GL_UNSIGNED_BYTE, nullptr);
            tex_width /= 2; if (tex_width < 1) tex_width = 1;
            tex_height /= 2; if (tex_height < 1) tex_height = 1;
        }
    } else glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, format, tex_width, tex_height, paths.size(), 0, format, GL_UNSIGNED_BYTE, nullptr);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);

    if (mipmap && anisotropic_filtering > 1.0f && (GL_EXT_texture_filter_anisotropic || GL_ARB_texture_filter_anisotropic)) {
        float max_level;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &max_level);
        if (anisotropic_filtering <= max_level)
            glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAX_ANISOTROPY_EXT, anisotropic_filtering);
    }

     int zoffset = 0;
    for (auto path : paths) {
        int width, height, components;
        unsigned char* data = TextureLoader::loadData(path, width, height, components);

        if (data) glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, zoffset++, width, height, 1, format, GL_UNSIGNED_BYTE, data);
        else std::cerr << "Failed to load texture - " << path << std::endl;
        TextureLoader::freeData(data);
    }
    if (mipmap) {
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
    }
}

void TextureArray::bindTextureArray() const {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, ID);
}

int TextureArray::getCurrentIndex() const {
    return current_index;
}

TextureArray::~TextureArray() {
    glDeleteTextures(1, &ID);
}