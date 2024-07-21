// Copyright (c) 2024 dudubles

// Title  : base.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <algorithm>

#include <bware/base.hpp>

namespace brainware {

// Initialize resource list, this is to keep track
// of every resource loaded into the game.
std::vector<Resource *> Resource::resource_list_;

Resource::Resource() { resource_list_.push_back(this); }

Resource::~Resource() {

  auto resource_pos =
      std::find(resource_list_.begin(), resource_list_.end(), this);

  if (resource_pos != resource_list_.end()) {
    resource_list_.erase(resource_pos);
  }
}

int GameObject::id_increment = 0;
GameObject::GameObject() {
  id_increment++;
  id_ = id_increment;
}

} // namespace brainware
