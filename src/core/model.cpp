// Copyright (c) 2024 dudubles

// Title  : model.cpp
// Author : @Dudubles
// Date   : 07/16/24

#include <iostream>

#include <bware/base.hpp>
#include <bware/core/model.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Model::Model() { type_ = kModel; }

void Model::FromFile(const char *path) {
  std::cout << "[BRAINWARE] [DEBUG] Loading 3d file from path: " << path
            << std::endl;
}

} // namespace brainware
