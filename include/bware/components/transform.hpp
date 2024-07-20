// Copyright (c) 2024 dudubles

// Title  : transform.hpp
// Author : @Dudubles
// Date   : 07/19/24

#ifndef BWARE_COMPONENTS_TRANSFORM_H_
#define BWARE_COMPONENTS_TRANSFORM_H_

#include <glm/glm.hpp>

#include <bware/base.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

class Transform : public Component {
public:
  Transform();

  float position_[3];
  float rotation_[3];
  float scaling_[3];

  glm::mat4 GetModelMatrix();
};

} // namespace brainware

#endif // !BWARE_COMPONENTS_TRANSFORM_H_
