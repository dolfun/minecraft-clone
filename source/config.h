#pragma once
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

struct Config {
    int window_x = 800;
    int window_y = 600;
    bool fullscreen = false;
    int MSAA = 4;
    bool debug = false;

    float fov = 90.0f;
    int render_distance = 3;
};

#endif