// Copyright (c) 2024 dudubles

#pragma once

#include "bware/core.hpp"

#ifndef BWARE_RESOURCES_MESH_H_
#define BWARE_RESOURCES_MESH_H_

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

#endif // !BWARE_RESOURCES_MESH_H_
