// Copyright (c) 2024 dudubles

// Title  : texture.hpp
// Author : @Dudubles
// Date   : 07/22/24

#ifndef BWARE_RESOURCES_TEXTURE_H
#define BWARE_RESOURCES_TEXTURE_H

#include <bware/base.hpp>

#include <glm/glm.hpp>

namespace brainware {

class Texture : public Resource {
public:
  void Bind();

private:
  unsigned int id_;
};

} // namespace brainware

#endif // !BWARE_RESOURCES_TEXTURE_H
