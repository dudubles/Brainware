// Copyright (c) 2024 dudubles

// Title  : model.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_CORE_MODEL_H_
#define BWARE_CORE_MODEL_H_

#include <glm/glm.hpp>

#include <vector>

#include <bware/base.hpp>
#include <bware/components/transform.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

class Model : public GameObject {
public:
  Model();

  Transform transform_;

  std::vector<Mesh> meshes_;

  void FromFile(const char *path);

private:
};

} // namespace brainware

#endif // !BWARE_CORE_MODEL_H_
