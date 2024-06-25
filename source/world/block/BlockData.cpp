#include "BlockData.h"
#include "BlockDatabase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <rapidjson/document.h>

BlockData::BlockData(std::string name) {
    std::ifstream json_file("resources/blocks/data/" + name + ".json");
    std::string json_str;

    if (json_file.is_open()) {
        std::stringstream buffer;
        buffer << json_file.rdbuf();
        json_file.close();
        json_str = buffer.str();
    }
    else std::cerr << "Failed to open json file - " << name << std::endl;

    rapidjson::Document document;
    document.Parse(json_str.c_str());

    if (document.IsObject() && name == document["BlockName"].GetString()) {
        ID = (BlockID)document["BlockID"].GetInt();
        mesh_type = (BlockMeshType)document["MeshType"].GetInt();
        shader_type = (BlockShaderType)document["ShaderType"].GetInt();
        is_opaque = document["Opacity"].GetBool();

        if (document.HasMember("Texture1"))
            tex_names[0] = document["Texture1"]["All"].GetString();
        else if (document.HasMember("Texture3")) {
            tex_names[1] = document["Texture3"]["Top"].GetString();
            tex_names[2] = document["Texture3"]["Side"].GetString();
            tex_names[3] = document["Texture3"]["Bottom"].GetString();

            tex_index = glm::ivec3(-1);
        }
    }
    else std::cerr << "Invalid json file - " << name << std::endl;
}

void BlockData::loadTextures() {
    if (ID == BlockID::air) return;
    if (tex_index == glm::ivec3(-1)) {
        tex_index[0] = BlockDatabase::get().getTexArray().getCurrentIndex();
        BlockDatabase::get().getTexArray().addTexturePath("resources/blocks/texture/" + tex_names[1] + ".png");
        tex_index[1] = BlockDatabase::get().getTexArray().getCurrentIndex();
        BlockDatabase::get().getTexArray().addTexturePath("resources/blocks/texture/" + tex_names[2] + ".png");
        tex_index[2] = BlockDatabase::get().getTexArray().getCurrentIndex();
        BlockDatabase::get().getTexArray().addTexturePath("resources/blocks/texture/" + tex_names[3] + ".png");
    }
    else {
        tex_index = glm::ivec3(BlockDatabase::get().getTexArray().getCurrentIndex());
        BlockDatabase::get().getTexArray().addTexturePath("resources/blocks/texture/" + tex_names[0] + ".png");
    }
}

const BlockID& BlockData::getID() const {
    return ID;
}
const BlockMeshType& BlockData::getBlockMeshType() const { 
    return mesh_type; 
}

const BlockShaderType& BlockData::getBlockShaderType() const {
    return shader_type;
}

bool BlockData::isOpaque() const { 
    return is_opaque; 
}

const glm::ivec3& BlockData::getTexIndex() const { 
    return tex_index; 
}