#pragma once

#include "UI.h"
#include <GLFW/glfw3.h>

class App
{
public:
    void run();

    App();
    ~App();

private:
    void init();
    void render();
    void cleanup();

    GLFWwindow *window_;
    UI *ui_;
};
