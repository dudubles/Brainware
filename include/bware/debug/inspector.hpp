// Copyright (c) 2024 dudubles

// Title  : model_inspector.hpp
// Author : @Dudubles
// Date   : 07/19/24

#ifndef BWARE_DEBUG_MODEL_INSPECTOR_H_
#define BWARE_DEBUG_MODEL_INSPECTOR_H_

#include <bware/base.hpp>
#include <bware/core/model.hpp>
#include <bware/debug/debugger.hpp>
#include <bware/resources/mesh.hpp>

namespace debugger {

class Inspector : public DebugTool {
public:
  void Render() override;
  brainware::GameObject *object_;
};

} // namespace debugger

#endif // !BWARE_DEBUG_MODEL_INSPECTOR_H_
