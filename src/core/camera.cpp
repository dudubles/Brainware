// Copyright (c) 2024 dudubles

// Title  : camera.cpp
// Author : @Dudubles
// Date   : 07/20/24

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>

#include <bware/base.hpp>
#include <bware/core/camera.hpp>
#include <bware/core/model.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Camera::Camera() { type_ = kCamera; }

glm::mat4 Camera::GetProjectionMatrix() {
  glm::mat4 result;
  if (projection_ == kPerspective) {
    result = glm::perspective(fov_, aspect_width / aspect_height, 0.1f, 100.0f);
  }

  return result;
}

} // namespace brainware
