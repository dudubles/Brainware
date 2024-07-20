// Copyright (c) 2024 dudubles

// Title  : mesh.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_RESOURCES_MESH_H_
#define BWARE_RESOURCES_MESH_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>

#include <vector>

#include <bware/base.hpp>

namespace brainware {

class Primitive {
public:
  Primitive();

  GLenum mode_;
  unsigned int type_;
  size_t indices_count_;
  char *pointer_;

  unsigned int vao_;
  unsigned int vbo_;
  unsigned int ebo_;

  void Draw();
};

class Mesh : public Resource {
public:
  Mesh();

  std::vector<Primitive> primitives_;

  void Draw();
};

} // namespace brainware

#endif // !BWARE_RESOURCES_MESH_H_
