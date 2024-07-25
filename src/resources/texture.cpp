// Copyright (c) 2024 dudubles

// Title  : texture.cpp
// Author : @Dudubles
// Date   : 07/24/24

#include <bware/resources/texture.hpp>
#include <glad/glad.h>

// HACK: Idk but this whole code is wrong i think

namespace brainware {

Texture::Texture() { glGenTextures(1, &id_); };

void Texture::SetUnit(int unit) { unit_ = unit; };

void Texture::Activate() {
  glActiveTexture(GL_TEXTURE0 + unit_);
  glBindTexture(GL_TEXTURE_2D, id_);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
};

} // namespace brainware
