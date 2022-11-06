#include "../includes/window.h"

Context* createContext(int width, int heigth, const char* title)
{
    Context* callback = reinterpret_cast<Context*>(malloc(sizeof(Context)));
    if (!glfwInit())
    {
        fprintf(stderr, "%s ", "failed to initialize 'GLFW'.\n");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    callback->m_window  = glfwCreateWindow(width, heigth, title, nullptr, nullptr);
    if (callback->m_window == nullptr)
    {
        fprintf(stderr, "%s ", "failed to initialize 'GLFW' Window.\n");
        glfwTerminate();
    }
    glfwMakeContextCurrent(callback->m_window);
    return callback;
}