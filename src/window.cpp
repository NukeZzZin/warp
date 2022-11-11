#include "../includes/window.hpp"

Warp::Window::WinContext* Warp::Window::createContext(unsigned int width, unsigned int heigth, const char* title)
{
    Warp::Window::WinContext* callback = reinterpret_cast<Warp::Window::WinContext*>(malloc(sizeof(Warp::Window::WinContext*)));
    if (!glfwInit())
    {
        fprintf(stderr, "%s\n", "failed to initialize GLFW.");
        return nullptr;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // ? glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    callback->s_width = width;
    callback->s_heigth = heigth;
    callback->s_title = title;
    callback->m_window = glfwCreateWindow(callback->s_width, callback->s_heigth, callback->s_title, nullptr, nullptr);
    if (callback->m_window == nullptr)
    {
        fprintf(stderr, "%s\n", "failed to initialize GLFW Window.");
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(callback->m_window);
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "%s\n", "failed to initialize GLEW.");
        glfwDestroyWindow(callback->m_window);
        glfwTerminate();
        return nullptr;
    }
    glfwSwapInterval(SWAP_INTERVAL_DEFAULT);
    callback->s_initialized = true;
    return callback;
}

void Warp::Window::destroyContext(Warp::Window::WinContext* context)
{
    glfwDestroyWindow(context->m_window);
    glfwTerminate();
}
