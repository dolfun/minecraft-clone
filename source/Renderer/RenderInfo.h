#pragma once
#ifndef RENDERINFO_H_INCLUDED
#define RENDERINFO_H_INCLUDED

struct RenderInfo {
    unsigned int VAO = 0;
    unsigned int indices_count = 0;

    inline void reset() {
        VAO = 0;
        indices_count = 0;
    }
};

#endif