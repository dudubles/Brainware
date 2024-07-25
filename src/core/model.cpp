// Copyright (c) 2024 dudubles

// Title  : model.cpp
// Author : @Dudubles
// Date   : 07/16/24

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <tiny_gltf.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>
#include <vector>

#include <bware/base.hpp>
#include <bware/core/model.hpp>
#include <bware/resources/mesh.hpp>

namespace brainware {

Model::Model() { type_ = kModel; }

Mesh LoadMeshGLTF(tinygltf::Model *model, tinygltf::Mesh *mesh) {
  Mesh result_mesh;

  for (tinygltf::Primitive primitive : mesh->primitives) {
    Primitive result_primitive;

    result_primitive.mode_ = primitive.mode;

    glBindVertexArray(result_primitive.vao_);

    bool vbo_defined =
        false; // HACK: As of right now we only support 1 buffer per primitive
    for (auto const &[attr_name, accessor_index] : primitive.attributes) {
      tinygltf::Accessor accessor = model->accessors[accessor_index];
      tinygltf::BufferView buffer_view =
          model->bufferViews[accessor.bufferView];

      if (!vbo_defined) {
        glBindBuffer(buffer_view.target, result_primitive.vbo_);
        tinygltf::Buffer buffer = model->buffers[buffer_view.buffer];

        glBufferData(buffer_view.target, buffer_view.byteLength,
                     &buffer.data.at(0) + buffer_view.byteOffset,
                     GL_STATIC_DRAW);
      }

      // In tinygltf accessor.type actually returns the size of each component
      int size = accessor.type;
      int byte_stride =
          accessor.ByteStride(model->bufferViews[accessor.bufferView]);

      if (attr_name == "POSITION") {
        // LAYOUT 0 -> POSITION
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, size, accessor.componentType,
                              accessor.normalized ? GL_TRUE : GL_FALSE,
                              byte_stride, (char *)NULL + accessor.byteOffset);
      }

      if (attr_name.find("TEXCOORD_")) {
        // LAYOUT 1 -> UV COORDINATES
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, size, accessor.componentType,
                              accessor.normalized ? GL_TRUE : GL_FALSE,
                              byte_stride, (char *)NULL + accessor.byteOffset);
      }
    }

    tinygltf::Accessor indices_accessor = model->accessors[primitive.indices];
    tinygltf::BufferView indices_buffer_view =
        model->bufferViews[indices_accessor.bufferView];
    tinygltf::Buffer indices_buffer =
        model->buffers[indices_buffer_view.buffer];

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, result_primitive.ebo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_view.byteLength,
                 &indices_buffer.data.at(0) + indices_buffer_view.byteOffset,
                 GL_STATIC_DRAW);

    result_primitive.indices_count_ = indices_accessor.count;
    result_primitive.type_ =
        indices_accessor.componentType; // Usually UNSIGNED INT
    result_primitive.pointer_ = (char *)NULL + indices_accessor.byteOffset;

    result_mesh.primitives_.push_back(result_primitive);
  }

  return result_mesh;
}

void Model::FromFile(const char *path) {
  std::cout << "[BRAINWARE] [DEBUG] Loading 3D model from path: " << path
            << std::endl;

  tinygltf::Model model;
  tinygltf::TinyGLTF loader;
  std::string err;
  std::string warn;

  bool success = loader.LoadASCIIFromFile(&model, &err, &warn, path);

  if (!warn.empty()) {
    std::cout << "[BRAINWARE] [WARN] " << warn << std::endl;
  }

  if (!err.empty()) {
    std::cout << "[BRAINWARE] [ERROR] Error trying to load model: " << err
              << std::endl;
    return;
  }

  if (!success) {
    printf("Failed to parse glTF\n");
    return;
  }

  for (tinygltf::Mesh mesh : model.meshes) {
    meshes_.push_back(LoadMeshGLTF(&model, &mesh));
  }

  std::cout << "[BRAINWARE] [DEBUG] 3D model loaded succesfully, path: " << path
            << std::endl;
}

} // namespace brainware
