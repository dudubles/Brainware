// Copyright (c) 2024 dudubles

// Title  : model_inspector.cpp
// Author : @Dudubles
// Date   : 07/19/24

#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <bware/base.hpp>
#include <bware/core/camera.hpp>
#include <bware/core/model.hpp>
#include <bware/debug/inspector.hpp>
#include <bware/resources/mesh.hpp>

namespace debugger {

void Inspector::Render() {
  if (object_ == NULL) {
    return;
  }

  ImGui::Begin(
      ("Inspector (ID: " + std::to_string(object_->id_) + ")").c_str());

  ImGui::SeparatorText("General");

  std::string type = "Unknown";

  if (object_->type_ == brainware::kModel) {
    type = "Model";
  }

  if (object_->type_ == brainware::kCamera) {
    type = "Camera";
  }

  ImGui::Text("Name: %s", object_->name_.c_str());
  ImGui::Text("Type: %s", type.c_str());
  ImGui::Spacing();

  ImGui::SeparatorText("Properties");

  if (object_->type_ == brainware::kModel) {
    brainware::Model *model_cast = dynamic_cast<brainware::Model *>(object_);

    if (ImGui::CollapsingHeader("Transform")) {
      ImGui::InputFloat3("Position",
                         glm::value_ptr(model_cast->transform_.position_));
      ImGui::SliderFloat3("Orientation",
                          glm::value_ptr(model_cast->transform_.orientation_),
                          -180.0f, 180.0f);
      ImGui::InputFloat3("Scale",
                         glm::value_ptr(model_cast->transform_.scaling_));

      ImGui::InputFloat3("Pivot",
                         glm::value_ptr(model_cast->transform_.pivot_));
    }
  }

  if (object_->type_ == brainware::kCamera) {
    brainware::Camera *camera_cast = dynamic_cast<brainware::Camera *>(object_);

    if (ImGui::CollapsingHeader("Transform")) {
      ImGui::InputFloat3("Position",
                         glm::value_ptr(camera_cast->transform_.position_));
      ImGui::SliderFloat3("Orientation",
                          glm::value_ptr(camera_cast->transform_.orientation_),
                          -180.0f, 180.0f);
      ImGui::InputFloat3("Scale",
                         glm::value_ptr(camera_cast->transform_.scaling_));
    }

    if (ImGui::CollapsingHeader("Camera")) {
      ImGui::InputFloat("FOV", &camera_cast->fov_);
      ImGui::InputFloat("Aspect Ratio Width", &camera_cast->aspect_width_);
      ImGui::InputFloat("Aspect Ratio Height", &camera_cast->aspect_height_);
    }
  }

  ImGui::SeparatorText("Components");

  ImGui::End();
}

} // namespace debugger
