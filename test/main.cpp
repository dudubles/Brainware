// This file is just for testing

#include "bware/base.hpp"
#include "bware/core/model.hpp"
#include "bware/debug/debugger.hpp"
#include "bware/debug/inspector.hpp"
#include <windows.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <bware/resources/shader.hpp>

#include <iostream>

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(1280, 720, "Brainware", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 1280, 720);

  debugger::InitializeDebugTools(window);

  brainware::Shader myshader(
      "C:/Users/tiago/Desktop/Brainware/resource/shaders/vertex.glsl",
      "C:/Users/tiago/Desktop/Brainware/resource/shaders/fragment.glsl");

  brainware::Model mymodel;
  debugger::Inspector inspector;
  bool loaded;

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0, .0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    debugger::StartFrame();

    inspector.Begin((brainware::GameObject)mymodel);

    debugger::EndFrame();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
