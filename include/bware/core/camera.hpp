// Copyright (c) 2024 dudubles

// Title  : camera.hpp
// Author : @Dudubles
// Date   : 07/20/24

#ifndef BWARE_CORE_CAMERA_H_
#define BWARE_CORE_CAMERA_H_

#include <glm/glm.hpp>

#include <bware/base.hpp>
#include <bware/components/transform.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

enum ProjectionType {
  kPerspective,
};

class Camera : public GameObject {
public:
  Camera();

  Transform transform_;

  ProjectionType projection_ = kPerspective;
  float fov_ = 45.0f;
  float aspect_width_ = 1280.0f;
  float aspect_height_ = 720.0f;

  glm::mat4 GetProjectionMatrix();
};

} // namespace brainware

#endif // !BWARE_CORE_CAMERA_H_
