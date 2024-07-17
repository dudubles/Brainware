// Copyright (c) 2024 dudubles

// Title  : base.hpp
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

  ResourceType type_ = kCustomResource;

private:
  static std::vector<Resource *> resource_list_;
};

enum ComponentType {
  kCustomComponent,
};

class Component {
public:
  ComponentType type_ = kCustomComponent;
};

enum GameObjectType {
  kCustomGameObject,
  kModel, // core/model.hpp
};

class GameObject {
public:
  GameObjectType type_ = kCustomGameObject;

  GameObject *parent_;

  std::vector<GameObject *> children_;

  std::vector<Component *> components_; // Not really needed (at least for now)

  virtual void Update() {};
};

} // namespace brainware

#endif // !BWARE_CORE_H_
