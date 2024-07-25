// Copyright (c) 2024 dudubles

// Title  : texture.cpp
// Author : @Dudubles
// Date   : 07/24/24

#include <bware/resources/texture.hpp>
#include <glad/glad.h>

namespace brainware {

void Texture::Bind() { glBindTexture(GL_TEXTURE_2D, id_); }

} // namespace brainware
