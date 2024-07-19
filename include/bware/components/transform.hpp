// Copyright (c) 2024 dudubles

// Title  : transform.hpp
// Author : @Dudubles
// Date   : 07/19/24

#ifndef BWARE_COMPONENTS_TRANSFORM_H_
#define BWARE_COMPONENTS_TRANSFORM_H_

#include <glm/glm.hpp>

#include <vector>

#include <bware/base.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

struct Vector3 {
  // Not following UNDERSCORE guideline

  float x;
  float y;
  float z;
};

class Transform : Component {
public:
  Transform();

  Vector3 position_;
  Vector3 rotation_;
  Vector3 scaling_;

  glm::mat4 GetModelMatrix();
};

} // namespace brainware

#endif // !BWARE_COMPONENTS_TRANSFORM_H_
