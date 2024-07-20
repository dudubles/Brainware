// Copyright (c) 2024 dudubles

// Title  : model_inspector.hpp
// Author : @Dudubles
// Date   : 07/19/24

#ifndef BWARE_DEBUG_MODEL_INSPECTOR_H_
#define BWARE_DEBUG_MODEL_INSPECTOR_H_

#include <bware/core/model.hpp>

#include <bware/base.hpp>
#include <bware/resources/mesh.hpp>

namespace debugger {

class Inspector {
public:
  void Begin(brainware::GameObject object);
};

} // namespace debugger

#endif // !BWARE_DEBUG_MODEL_INSPECTOR_H_
