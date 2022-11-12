#include "../includes/window.hpp"

Warp::WindowContext::WindowContext(unsigned int width, unsigned int height, const char* title)
{
    this->m_DATAWindow.s_width = width;
    this->m_DATAWindow.s_height = height;
    this->m_DATAWindow.s_title = title;
    this->CreateContext();
}

Warp::WindowContext::~WindowContext()
{
    this->s_initialized = this->DestroyContext();
}

BOOL Warp::WindowContext::CreateContext()
{
    if (!glfwInit())
    {
        fprintf(stderr, "%s\n", "failed to initialize GLFW.");
        return FALSE;
    }
    // ! glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    // ? glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_NONE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // ? glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    m_GLFWindow = glfwCreateWindow(this->m_DATAWindow.s_width, this->m_DATAWindow.s_height, this->m_DATAWindow.s_title, nullptr, nullptr);
    if (m_GLFWindow == nullptr)
    {
        fprintf(stderr, "%s\n", "failed to initialize GLFW Window.");
        glfwTerminate();
        return FALSE;
    }
    glfwMakeContextCurrent(m_GLFWindow);
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "%s\n", "failed to initialize GLEW.");
        glfwDestroyWindow(m_GLFWindow);
        glfwTerminate();
        return FALSE;
    }
    glfwSwapInterval(SWAP_INTERVAL_DEFAULT);
    this->s_initialized = TRUE;
    return TRUE;
}

BOOL Warp::WindowContext::DestroyContext()
{
    if (s_initialized == TRUE)
        glfwTerminate();
    else
        return FALSE;
    if (m_GLFWindow != nullptr)
        glfwDestroyWindow(m_GLFWindow);
    else
        return FALSE;
    return TRUE;
}
