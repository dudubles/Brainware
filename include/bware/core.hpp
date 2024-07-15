// Copyright (c) 2024 dudubles

#pragma once

#include <vector>

#ifndef BWARE_CORE

namespace brainware {

#define BRAINWARE_RESOURCE_SHADER 0; // resources/shader.hpp
#define BRAINWARE_RESOURCE_MESH 1;   // resources/mesh.hpp

class Resource {
public:
  Resource();
  ~Resource();

  unsigned int type_;

private:
  static std::vector<Resource *> resource_list_;
};

class Component {
public:
  unsigned int type_;
};

class GameObject {
public:
  unsigned int type_;

  GameObject *parent_;

  std::vector<GameObject *> children_;
  std::vector<Component *> components_;

  virtual void Update();
};

} // namespace brainware

#endif // !BWARE_CORE
