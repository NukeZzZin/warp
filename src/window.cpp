#include "../includes/window.h"

WinContext* createContext(int width, int heigth, const char* title)
{
    WinContext* callback = reinterpret_cast<WinContext*>(malloc(sizeof(WinContext)));
    if (!glfwInit())
    {
        fprintf(stderr, "%s", "failed to initialize GLFW.\n");
        return nullptr;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    callback->m_window  = glfwCreateWindow(width, heigth, title, nullptr, nullptr);
    if (callback->m_window == nullptr)
    {
        fprintf(stderr, "%s", "failed to initialize GLFW Window.\n");
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(callback->m_window);
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "%s", "failed to initialize GLEW.\n");
        glfwDestroyWindow(callback->m_window);
        glfwTerminate();
        return nullptr;
    }
    glfwSwapInterval(1);
    return callback;
}