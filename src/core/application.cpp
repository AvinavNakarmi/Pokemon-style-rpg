#include "application.h"

Application::Application()
{
    std::cout << "Application created." << std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        throw std::runtime_error("Failed to initialize GLAD");
    }
    WindowHandler::setWidth(width);
    WindowHandler::setWidth(height);
    WindowHandler::setWindow(window);
    renderer = new Renderer();
}
void Application::Run()
{
    while (!glfwWindowShouldClose(window))
    {
        renderer->Draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}
Application::~Application()
{
    delete renderer;
    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "Application destroyed." << std::endl;
}