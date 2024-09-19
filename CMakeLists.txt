cmake_minimum_required(VERSION 3.10)
project(StoryFlow)

set(CMAKE_CXX_STANDARD 20)

# GLFW
add_subdirectory(deps/glfw)
target_link_libraries(StoryFlow glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(StoryFlow OpenGL::GL)

# Include directories
include_directories(
    deps/glfw/include
    deps/imgui
    deps/imgui/backends
    include
)

# Source files
set(SOURCES
    src/main.cpp
    src/App.cpp
    src/UI.cpp
)

# Add executable
add_executable(StoryFlow ${SOURCES})

# Link libraries
target_link_libraries(StoryFlow glfw ${OPENGL_gl_LIBRARY} )
