// Copyright (c) 2024 dudubles

// Title  : core.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_CORE_H_
#define BWARE_CORE_H_

#include <vector>

namespace brainware {

enum ResourceType {
  kCustomResource,
  kShaderResource, // resources/shader.hpp
  kMeshResource,   // resources/mesh.hpp
};

class Resource {
public:
  Resource();
  ~Resource();

  ResourceType type_;

private:
  static std::vector<Resource *> resource_list_;
};

enum ComponentType {
  kCustomComponent,
};

class Component {
public:
  ComponentType type_;
};

enum GameObjectType {
  kCustomGameObject,
};

class GameObject {
public:
  GameObjectType type_;

  GameObject *parent_;

  std::vector<GameObject *> children_;
  std::vector<Component *> components_;

  virtual void Update();
};

} // namespace brainware

#endif // !BWARE_CORE_H_
