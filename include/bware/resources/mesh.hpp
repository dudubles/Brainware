// Copyright (c) 2024 dudubles

#pragma once

#include "bware/core.hpp"

#ifndef BWARE_MESH

namespace brainware {

class Mesh : Resource {
public:
  Mesh();

private:
  unsigned int vbo_;
  unsigned int ebo_;
  unsigned int vao_;
};

} // namespace brainware

#endif // !BWARE_MESH
