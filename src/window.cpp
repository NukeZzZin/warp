#include "../includes/window.h"

warp::Window* warp::createWindow(int width, int heigth, const char* title)
{
    warp::Window* callback;
    callback = reinterpret_cast<warp::Window*>(malloc(sizeof(warp::Window)));
    if (!glfwInit())
    {
        std::cerr << "failed to initialize 'GLFW'." << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    callback->m_monitor = glfwGetPrimaryMonitor();
    callback->m_video = glfwGetVideoMode(callback->m_monitor);
    callback->m_window  = glfwCreateWindow(width, heigth, title, nullptr, nullptr);
    if (callback->m_window == nullptr)
    {
        std::cerr << "failed to initialize 'GLFW' Window." << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(callback->m_window);
    return callback;
}