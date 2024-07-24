#version 460 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 tex_coord;

uniform mat4 mvp;

out vec2 tex_coord_frag;

void main()
{
    gl_Position = mvp * vec4(position, 1.0);
    tex_coord_frag = tex_coord;
}
