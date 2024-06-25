#version 400 core
out vec4 out_color;

in vec3 pos;
in vec3 normal;
in vec2 tex_coord;
in vec3 block_index;
in vec3 orientation;

uniform sampler2DArray texture_array;

vec4 getFragColor();

void main() {
    out_color = getFragColor();
    if (out_color.a < 0.1f) discard;
}

vec4 getFragColor() {
    float index;
    vec2 my_tex_coord;

    for (int i = 0; i < 3; ++i) {
        float e = orientation[i];
        if (e != 0.0f) {
            if      (normal[i] ==  1.0f * e) index = block_index[0];
            else if (normal[i] == -1.0f * e) index = block_index[2];
            else                             index = block_index[1];
            
            if      (i == 0) my_tex_coord = tex_coord.yx * e;
            else if (i == 1) my_tex_coord = tex_coord.xy * e;
            else {
                if (normal.x != 0) my_tex_coord = tex_coord.yx * e;
                else               my_tex_coord = tex_coord.xy * e;
            }
        }
    }

    return texture(texture_array, vec3(my_tex_coord, index));
}