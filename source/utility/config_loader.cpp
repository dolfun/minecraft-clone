#include "ConfigLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <rapidjson/document.h>

Config loadConfig(std::string filename) {
    std::ifstream config_file(filename);
    std::string config_str;

    if (config_file.is_open()) {
        std::stringstream buffer;
        buffer << config_file.rdbuf();
        config_file.close();
        config_str = buffer.str();
    }
    else std::cerr << "Failed to open config file - " << filename << std::endl;

    rapidjson::Document document;
    document.Parse(config_str.c_str());
    
    Config config;

    if (document.IsObject()) {
        config.window_x = document["WindowWidth"].GetInt();
        config.window_y = document["WindowHeight"].GetInt();
        config.fullscreen = document["Fullscreen"].GetBool();
        config.title = document["Title"].GetString();
        config.gl_major_version = document["GL_MAJOR_VERSION"].GetInt();
        config.gl_minor_version = document["GL_MINOR_VERSION"].GetInt();
        config.MSAA = document["MSAA"].GetInt();
        config.mipmap = document["Mipmap"].GetInt();
        config.anisotropic_filtering = document["AnisotropicFiltering"].GetFloat();
        config.debug = document["debug"].GetBool();

        config.fov = document["FOV"].GetFloat();
        config.render_distance = document["RenderDistance"].GetInt();
    }
    else std::cerr << "Invalid json file - " << filename << std::endl;

    return config;
}