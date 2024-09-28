cmake_minimum_required(VERSION 3.10)

project(StoryFlow VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source/header files for the app
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include)

# Lib directories
link_directories(${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/lib)

# Add executable
add_executable(StoryFlow ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(StoryFlow PRIVATE opengl32 freetype glfw3dll imgui)
# dependencies
# target_link_libraries(StoryFlow PRIVATE)