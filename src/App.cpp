#include "App.h"
#include "UI.h"

#include <GLFW/glfw3.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>

static void glfwErrorCallback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

App::App() : window_(nullptr), ui_(nullptr)
{
    init();
}

App::~App()
{
    cleanup();
}

void App::run()
{
    render();
}

void App::init()
{
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Decide GL+GLSL versions #version 330
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create windows with graphics context
    window_ = glfwCreateWindow(1280, 720, "Story Flow", nullptr, nullptr);
    if (!window_)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);

    // Setup Dear ImGui context
    ui_ = new UI(window_);
}

void App::render()
{
    while (!glfwWindowShouldClose(window_))
    {
        glfwPollEvents();

        ui_->newFrame();
        ui_->render();
        ui_->endFrame();

        glfwSwapBuffers(window_);
    }
}

void App::cleanup()
{
    delete ui_;
    glfwDestroyWindow(window_);
    glfwTerminate();
}
