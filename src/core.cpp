// Copyright (c) 2024 dudubles

// Title  : core.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <algorithm>

#include <bware/core.hpp>

namespace brainware {

std::vector<Resource *> Resource::resource_list_;

Resource::Resource() {
  type_ = ResourceType::kCustomResource; // Custom by default
  resource_list_.push_back(this);
}

Resource::~Resource() {

  auto resource_pos =
      std::find(resource_list_.begin(), resource_list_.end(), this);

  if (resource_pos != resource_list_.end()) {
    resource_list_.erase(resource_pos);
  }
}

} // namespace brainware
