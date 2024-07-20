// Copyright (c) 2024 dudubles

// Title  : model_inspector.cpp
// Author : @Dudubles
// Date   : 07/19/24

#include <imgui.h>
#include <iostream>
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <bware/base.hpp>
#include <bware/core/model.hpp>
#include <bware/debug/inspector.hpp>
#include <bware/resources/mesh.hpp>

namespace debugger {

void Inspector::Begin(brainware::GameObject object) {
  ImGui::Begin("Inspector");

  ImGui::SeparatorText("General");

  std::string type = "Unknown";
  if (object.type_ == brainware::kModel) {
    type = "Model";
  }

  ImGui::Text("Name: %s", object.name_.c_str());
  ImGui::Text("Type: %s", type.c_str());
  ImGui::Spacing();

  ImGui::SeparatorText("Components");

  if (1) {
    brainware::Model *model_cast =
        reinterpret_cast<brainware::Model *>(&object);

    if (ImGui::CollapsingHeader("Transform")) {
      ImGui::InputFloat3("Position", model_cast->transform_.position_);
      ImGui::InputFloat3("Rotation", model_cast->transform_.rotation_);
      ImGui::InputFloat3("Scale", model_cast->transform_.scaling_);
    }
  }

  ImGui::End();
}

} // namespace debugger
