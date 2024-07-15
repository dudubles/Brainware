cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project("bware")

set(${BWARE_TESTING} TRUE)

# =================================== BRAINWARE STATIC LIBRARY ====================================

add_library(${PROJECT_NAME} STATIC

  ${PROJECT_SOURCE_DIR}/src/core.cpp
  ${PROJECT_SOURCE_DIR}/src/resources/shader.cpp
  ${PROJECT_SOURCE_DIR}/src/resources/mesh.cpp

  ${PROJECT_SOURCE_DIR}/src/glad.c # This could be a separate lib but for now its ok

)

target_include_directories(${PROJECT_NAME} PUBLIC

  ${PROJECT_SOURCE_DIR}/include/

)

target_link_libraries(${PROJECT_NAME}

  ${PROJECT_SOURCE_DIR}/lib/libglfw3.a 

)

# ======================================= BRAINWARE TESTING =======================================

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

# =================================================================================================
