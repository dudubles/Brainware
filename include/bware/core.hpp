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

  static std::vector<Resource *>
      resource_list_; // Its in public for testing, but it should be private
  unsigned int type_;

private:
};

} // namespace brainware

#endif // !BWARE_CORE
