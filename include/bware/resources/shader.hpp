// Copyright (c) 2024 dudubles

// Title  : shader.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_RESOURCES_SHADER_H_
#define BWARE_RESOURCES_SHADER_H_

#include <bware/base.hpp>

namespace brainware {

class Shader : public Resource {
public:
  Shader(const char *vertex_path, const char *fragment_path);

  unsigned int id_;
};

} // namespace brainware

#endif // !BWARE_RESOURCES_SHADER_H_
