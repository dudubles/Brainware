// Copyright (c) 2024 dudubles

#pragma once

#include "bware/core.hpp"

#ifndef BWARE_RESOURCES_SHADER_H_
#define BWARE_RESOURCES_SHADER_H_

namespace brainware {

class Shader : Resource {
public:
  Shader(const char *vertex_path, const char *fragment_path);

  unsigned int id_;
};

} // namespace brainware

#endif // !BWARE_RESOURCES_SHADER_H_
