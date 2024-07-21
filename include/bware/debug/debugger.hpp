// Copyright (c) 2024 dudubles

// Title  : debugger.hpp
// Author : @Dudubles
// Date   : 07/19/24

#ifndef BWARE_DEBUG_DEBUGGER_H_
#define BWARE_DEBUG_DEBUGGER_H_

#include <bware/components/transform.hpp>

#include <bware/base.hpp>
#include <bware/resources/mesh.hpp>

namespace debugger {

void InitializeDebugTools(GLFWwindow *window);
void RenderTools();

class DebugTool {
public:
  DebugTool();
  ~DebugTool();

  static void RenderAll();

  virtual void Render() {};

private:
  static std::vector<DebugTool *> tools_list_;
};

} // namespace debugger

#endif // !BWARE_DEBUG_DEBUGGER_H_
