// Copyright (c) 2024 dudubles

// Title  : mesh.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <bware/base.hpp>
#include <bware/components/transform.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Transform::Transform() { type_ = kTransform; }

glm::mat4 Transform::GetMatrix() {
  glm::mat4 result = glm::mat4(1.0f);

  result = glm::translate(result, position_);

  result =
      glm::rotate(result, glm::radians(rotation_[0]), glm::vec3(1, 0, 0)); // X
  result =
      glm::rotate(result, glm::radians(rotation_[1]), glm::vec3(0, 1, 0)); // Y
  result =
      glm::rotate(result, glm::radians(rotation_[2]), glm::vec3(0, 0, 1)); // Z

  result = glm::scale(result, scaling_);

  return result;
}

} // namespace brainware
