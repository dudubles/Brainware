#version 330 core
out vec4 FragColor;

in vec2 tex_coord_frag;

void main()
{
    vec3 ourColor = vec3(1.0, 1.0, 1.0);
    FragColor = vec4(ourColor, 1.0f);
}
