cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project("bware")

set(BWARE_TESTING ON)

# =================================== BRAINWARE STATIC LIBRARY ====================================

add_library(${PROJECT_NAME} STATIC

  ${PROJECT_SOURCE_DIR}/src/core.cpp
  ${PROJECT_SOURCE_DIR}/src/resources/shader.cpp
  ${PROJECT_SOURCE_DIR}/src/resources/mesh.cpp

  # Dear ImGui
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui.cpp
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui_demo.cpp
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui_draw.cpp
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui_impl_glfw.cpp
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui_impl_opengl3.cpp
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui_tables.cpp
  ${PROJECT_SOURCE_DIR}/src/imgui/imgui_widgets.cpp

  ${PROJECT_SOURCE_DIR}/src/glad.c
)

target_include_directories(${PROJECT_NAME} PUBLIC

  ${PROJECT_SOURCE_DIR}/include/
  ${PROJECT_SOURCE_DIR}/include/imgui/

)

target_link_libraries(${PROJECT_NAME}

  ${PROJECT_SOURCE_DIR}/lib/libglfw3.a
  ${PROJECT_SOURCE_DIR}/lib/libassimp.a

)

# ======================================= BRAINWARE TESTING =======================================

if (BWARE_TESTING)

add_executable(test${PROJECT_NAME}

  ${PROJECT_SOURCE_DIR}/src/testing/main.cpp

)

target_include_directories(test${PROJECT_NAME} PUBLIC

  ${PROJECT_SOURCE_DIR}/include/

)

target_link_libraries(test${PROJECT_NAME}

  ${PROJECT_SOURCE_DIR}/lib/libglfw3.a
  ${PROJECT_SOURCE_DIR}/build/libbware.a

)

endif()

# =================================================================================================
