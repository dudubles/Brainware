#include <algorithm>
#include <bware/core.hpp>

std::vector<brainware::Resource *> brainware::Resource::resource_list_;

brainware::Resource::Resource() { this->resource_list_.push_back(this); }

brainware::Resource::~Resource() {

  auto resource_pos =
      std::find(resource_list_.begin(), resource_list_.end(), this);

  if (resource_pos != resource_list_.end()) {
    resource_list_.erase(resource_pos);
  }
}
