# CMake version
cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)
project(Toon)

# C++ Language Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Builds/CMake")

# Declare project

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Set enable output of compile commands during generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile options
include(CompileOptions)

# Build type - Release by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Overrides
set(CMAKE_MACOSX_RPATH ON)

add_subdirectory(Libraries/googletest EXCLUDE_FROM_ALL)
add_subdirectory(Libraries/glfw EXCLUDE_FROM_ALL)
# add_subdirectory(Libraries/thrust EXCLUDE_FROM_ALL)

add_subdirectory(ToonEngine)
add_subdirectory(ToonEditor)
add_subdirectory(ToonRendersystem_GL3Plus)
add_subdirectory(TestSolution)

add_dependencies(ToonEngine ToonRendersystem_GL3Plus)
add_dependencies(ToonEditor ToonEngine ToonRendersystem_GL3Plus)
add_dependencies(TestSolution ToonEditor ToonEngine ToonRendersystem_GL3Plus)