#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
class WindowHandler
{
private:
    static int width;
    static int height;
    static GLFWwindow *window;

public:
    static int getWidth();
    static int getHeight();
    static GLFWwindow *getWindow();

    static void setWidth(int w);
    static void setWindow(GLFWwindow *win);
    static void setHeight(int h);
};