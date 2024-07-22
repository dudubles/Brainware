// Copyright (c) 2024 dudubles

// Title  : mesh.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <bware/base.hpp>
#include <bware/components/transform.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Transform::Transform() { type_ = kTransform; }

void Transform::UpdateMatrix() {
  matrix_ = glm::mat4(1.0f);

  // Transform = Translation * Rotation * Scale
  // https://gamedev.stackexchange.com/questions/29260/transform-matrix-multiplication-order

  // Position (Translation)
  matrix_ = glm::translate(matrix_, position_);

  // Rotation (Rotation)
  matrix_ = glm::translate(matrix_, pivot_);
  matrix_ = glm::rotate(matrix_, glm::radians(rotation_.x),
                        glm::vec3(1.0f, 0.0f, 0.0f));
  matrix_ = glm::rotate(matrix_, glm::radians(rotation_.y),
                        glm::vec3(0.0f, 1.0f, 0.0f));
  matrix_ = glm::rotate(matrix_, glm::radians(rotation_.z),
                        glm::vec3(0.0f, 0.0f, 1.0f));

  // Orientation (Rotation but in the YXZ order)
  matrix_ = glm::rotate(matrix_, glm::radians(orientation_.y),
                        glm::vec3(0.0f, 1.0f, 0.0f));
  matrix_ = glm::rotate(matrix_, glm::radians(orientation_.x),
                        glm::vec3(1.0f, 0.0f, 0.0f));
  matrix_ = glm::rotate(matrix_, glm::radians(orientation_.z),
                        glm::vec3(0.0f, 0.0f, 1.0f));
  matrix_ = glm::translate(matrix_, -pivot_);

  // Scale (Scale)
  matrix_ = glm::scale(matrix_, scaling_);
}

} // namespace brainware
