// Copyright (c) 2024 dudubles

// Title  : mesh.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <glm/gtc/matrix_transform.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <bware/base.hpp>
#include <bware/components/transform.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Transform::Transform() { type_ = kTransform; }

glm::mat4 Transform::GetModelMatrix() {
  glm::mat4 result = glm::mat4(1.0f);

  result =
      glm::translate(result, glm::vec3(position_.x, rotation_.y, scaling_.z));

  result =
      glm::rotate(result, glm::radians(rotation_.x), glm::vec3(1, 0, 0)); // X
  result =
      glm::rotate(result, glm::radians(rotation_.y), glm::vec3(0, 1, 0)); // Y
  result =
      glm::rotate(result, glm::radians(rotation_.z), glm::vec3(0, 0, 1)); // Z

  result = glm::scale(result, glm::vec3(scaling_.z, scaling_.y, scaling_.x));

  return result;
}

} // namespace brainware
