#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "../renderer/renderer.h"
#include "../handler/window_handler.h"

class Application
{

public:
    Application();
    ~Application();
    void Run();

private:
    Renderer *renderer = nullptr;
    const int width = 800;
    const int height = 800;
    GLFWwindow *window;
};