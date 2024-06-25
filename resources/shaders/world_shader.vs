#version 400 core
layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_tex_coord;
layout (location = 3) in vec3 in_block_index;
layout (location = 4) in vec3 in_orientation;

out vec3 pos;
out vec3 normal;
out vec2 tex_coord;
out vec3 block_index;
out vec3 orientation;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(in_pos, 1.0f);
    pos = in_pos;
    normal = in_normal;
    tex_coord = in_tex_coord;
    block_index = in_block_index;
    orientation = in_orientation;
}