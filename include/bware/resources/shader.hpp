// Copyright (c) 2024 dudubles

// Title  : shader.hpp
// Author : @Dudubles
// Date   : 07/15/24

#ifndef BWARE_RESOURCES_SHADER_H_
#define BWARE_RESOURCES_SHADER_H_

#include <bware/base.hpp>

#include <glm/glm.hpp>

namespace brainware {

class Shader : public Resource {
public:
  Shader(const char *vertex_path, const char *fragment_path);

  void Bind();
  void UploadMvp(glm::mat4 model, glm::mat4 view, glm::mat4 projection);

  unsigned int id_;
};

} // namespace brainware

#endif // !BWARE_RESOURCES_SHADER_H_
