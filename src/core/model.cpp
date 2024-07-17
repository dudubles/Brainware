// Copyright (c) 2024 dudubles

// Title  : model.cpp
// Author : @Dudubles
// Date   : 07/16/24

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <bware/base.hpp>
#include <bware/resources/mesh.hpp>

#include <iostream>

#include <bware/core/model.hpp>

namespace brainware {

Model::Model() { type_ = kModel; }

void Model::FromFile(const char *path) {
  std::cout << "[BRAINWARE] [DEBUG] Loading 3d file from path: " << path
            << std::endl;
}

} // namespace brainware
