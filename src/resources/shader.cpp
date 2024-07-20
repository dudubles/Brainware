// Copyright (c) 2024 dudubles

// Title  : shader.cpp
// Author : @Dudubles
// Date   : 07/15/24

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include <bware/base.hpp>
#include <bware/resources/shader.hpp>

namespace brainware {

void Shader::UploadMvp(glm::mat4 model, glm::mat4 view, glm::mat4 projection) {
  int uniform_location = glGetUniformLocation(id_, "mvp");

  if (uniform_location < 0) {
    return;
  }

  glm::mat4 result = projection * view * model;
  glUniformMatrix4fv(uniform_location, 1, GL_FALSE, glm::value_ptr(result));
}

void Shader::Bind() { glUseProgram(id_); }

Shader::Shader(const char *vertex_path, const char *fragment_path) {
  type_ = ResourceType::kShaderResource;

  std::cout << "[BRAINWARE] [DEBUG] Creating new shader...\n";

  std::string vertex_code;
  std::string fragment_code;

  std::ifstream vertex_file;
  std::ifstream fragment_file;

  vertex_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fragment_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {

    vertex_file.open(vertex_path);
    fragment_file.open(fragment_path);

    std::stringstream vertex_stream;
    std::stringstream fragment_stream;

    vertex_stream << vertex_file.rdbuf();
    fragment_stream << fragment_file.rdbuf();

    vertex_file.close();
    fragment_file.close();

    vertex_code = vertex_stream.str();
    fragment_code = fragment_stream.str();

  } catch (std::ifstream::failure e) {
    std::cout << "[BRAINWARE] [ERROR] Could not read file of shader\n";
    return;
  }

  const char *c_vertex_code = vertex_code.c_str();
  const char *c_fragment_code = fragment_code.c_str();

  unsigned int vertex_id;
  unsigned int fragment_id;

  int success;
  char info_log[512];

  vertex_id = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_id, 1, &c_vertex_code, NULL);
  glCompileShader(vertex_id);

  glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex_id, 512, NULL, info_log);
    std::cout << "[BRAINWARE] [ERROR] Could not compile vertex shader: \n"
              << info_log << "\n";
  };

  fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_id, 1, &c_fragment_code, NULL);
  glCompileShader(fragment_id);

  glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment_id, 512, NULL, info_log);
    std::cout << "[BRAINWARE] [ERROR] Could not compile fragment shader: \n"
              << info_log << "\n";
  };

  id_ = glCreateProgram();
  glAttachShader(id_, vertex_id);
  glAttachShader(id_, fragment_id);
  glLinkProgram(id_);

  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id_, 512, NULL, info_log);
    std::cout << "[BRAINWARE] [ERROR] Could not link shaders in program: \n"
              << info_log << "\n";
    glDeleteProgram(id_);
  } else {
    std::cout << "[BRAINWARE] [DEBUG] Shader created successfully\n";
  }

  glDeleteShader(vertex_id);
  glDeleteShader(fragment_id);
}

} // namespace brainware
