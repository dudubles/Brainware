// Copyright (c) 2024 dudubles

// Title  : mesh.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <bware/base.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Primitive::Primitive() {
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glGenBuffers(1, &ebo_);
}

void Primitive::Draw() {
  glBindVertexArray(vao_);

  glDrawElements(mode_, indices_count_, type_,
                 pointer_); // TODO: Implement mode_
}

Mesh::Mesh() { type_ = ResourceType::kMeshResource; }

void Mesh::Draw() {
  for (Primitive primitive : primitives_) {
    primitive.Draw();
  }
}

} // namespace brainware
