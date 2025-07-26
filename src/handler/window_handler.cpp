#include "window_handler.h"

int WindowHandler::width = 0;
int WindowHandler::height = 0;
GLFWwindow *WindowHandler::window = nullptr;

void WindowHandler::setWidth(int w)
{
    width = w;
}
void WindowHandler::setHeight(int h)
{
    height = h;
}
int WindowHandler::getWidth()
{
    return width;
}

int WindowHandler::getHeight()
{
    return height;
}
GLFWwindow *WindowHandler::getWindow()
{
    return window;
}
void WindowHandler::setWindow(GLFWwindow *win)
{
    window = win;
}
