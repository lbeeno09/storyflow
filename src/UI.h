#pragma once

#include <GLFW/glfw3.h>
#include "imgui.h"

class UI
{
  public:
    void newFrame();
    void render();
    void endFrame();

    UI(GLFWwindow *window);
    ~UI();

  private:
    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // window var should share the same pointer as App class' window
    GLFWwindow *window_;
    const char *glslVersion_;
};
