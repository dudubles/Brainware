#version 460 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv_coords;

uniform mat4 mvp;

out vec2 uv_frag;

void main()
{
    gl_Position = mvp * vec4(position, 1.0);
    uv_frag = uv_coords;
}
