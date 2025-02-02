// Copyright (c) 2024 dudubles

// Title  : base.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_CORE_H_
#define BWARE_CORE_H_

#include <string>
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
  kTransform,
};

class Component {
public:
  ComponentType type_ = kCustomComponent;
};

enum GameObjectType {
  kCustomGameObject,
  kModel,  // core/model.hpp
  kCamera, // core/camera.hpp
};

class GameObject {
public:
  GameObject();

  GameObjectType type_ = kCustomGameObject;
  std::string name_ = "GameObject";

  int id_;

  GameObject *parent_;

  std::vector<GameObject *> children_;

  std::vector<Component *> components_; // Not really needed (at least for now)

  virtual void Update() {};

private:
  static int id_increment;
};

} // namespace brainware

#endif // !BWARE_CORE_H_
