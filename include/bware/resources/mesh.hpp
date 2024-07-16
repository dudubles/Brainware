// Copyright (c) 2024 dudubles

// Title  : mesh.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_RESOURCES_MESH_H_
#define BWARE_RESOURCES_MESH_H_

#include "glm/ext/vector_float3.hpp"
#include <glm/glm.hpp>

#include <bware/base.hpp>

#include <vector>

namespace brainware {

struct Vertex {
  glm::vec3 position_;
  glm::vec2 tex_coords_;
};

class Mesh : Resource {
public:
  Mesh();

  unsigned int vao_;

  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;

  void SetupGL();

private:
  unsigned int vbo_;
  unsigned int ebo_;
};

} // namespace brainware

#endif // !BWARE_RESOURCES_MESH_H_
