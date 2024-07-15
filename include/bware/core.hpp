// Copyright (c) 2024 dudubles

#pragma once

#include <vector>

#ifndef BWARE_CORE

namespace brainware {

#define BRAINWARE_RESOURCE_SHADER 0; // resources/shader.hpp
#define BRAINWARE_RESOURCE_MESH 1;   // resources/mesh.hpp

class Resource {
public:
  Resource();
  ~Resource();

  unsigned int type_;

private:
  static std::vector<Resource *> resource_list_;
};

} // namespace brainware

#endif // !BWARE_CORE
