# CMAKE file for brainware engine compilation
message("======================= BRAINWARE COMPILATION =======================")

cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
include(CMakePrintHelpers)

project("bware")

set(BWARE_TESTING ON)
set(BWARE_DEBUG_TOOLS ON)

# =================================== BRAINWARE STATIC LIBRARY ====================================

message("-- Setup Brainware static library compilation settings")

file(GLOB_RECURSE BWARE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c
)

# REMOVE DEBUG TOOLS IF SET TO OFF
if (NOT BWARE_DEBUG_TOOLS)

  file(GLOB_RECURSE EXCLUDE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/debug/*.cpp
    ${PROJECT_SOURCE_DIR}/src/debug/*.c
  )

  foreach(EXCLUDE_FILE ${EXCLUDE_SOURCES})
    list(REMOVE_ITEM BWARE_SOURCES ${EXCLUDE_FILE})
  endforeach()

endif()

add_library(${PROJECT_NAME} STATIC ${BWARE_SOURCES})

file(GLOB_RECURSE BWARE_LIBRARIES
    ${PROJECT_SOURCE_DIR}/lib/*.a
)

target_include_directories(${PROJECT_NAME} PUBLIC

  ${PROJECT_SOURCE_DIR}/include/
  ${PROJECT_SOURCE_DIR}/include/imgui/ # ImGui compatibility

)

target_link_libraries(${PROJECT_NAME} ${BWARE_LIBRARIES})

# ======================================= BRAINWARE TESTING =======================================

if (BWARE_TESTING)

message("-- Setup Brainware testing unit compilation settings")

file(GLOB_RECURSE BWARE_TESTING_SOURCES
  ${PROJECT_SOURCE_DIR}/test/*.cpp
  ${PROJECT_SOURCE_DIR}/test/*.c
)

add_executable(test${PROJECT_NAME} ${BWARE_TESTING_SOURCES})

target_include_directories(test${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(test${PROJECT_NAME}

  ${PROJECT_SOURCE_DIR}/lib/libglfw3.a # TODO: Remove after having engine be able to control OpenGL all by itself
  ${PROJECT_SOURCE_DIR}/build/libbware.a

)

endif()

# =================================================================================================
