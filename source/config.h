#pragma once
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <string>

struct Config {
    int window_x = 800;
    int window_y = 600;
    bool fullscreen = false;
    std::string title;
    int gl_major_version = 4;
    int gl_minor_version = 0;
    int MSAA = 4;
    int mipmap = 0;
    float anisotropic_filtering = 1.0f;
    bool debug = false;

    float fov = 90.0f;
    int render_distance = 3;
};

#endif