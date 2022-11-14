#include "../includes/window.hpp"

Warp::WindowContext::WindowContext(unsigned int width, unsigned int height, const char* title)
{
    this->m_DATAWindow.s_width = width;
    this->m_DATAWindow.s_height = height;
    this->m_DATAWindow.s_title = title;
    glfwSetErrorCallback([](int error_code, const char* description) {
        fprintf(stderr, "a error has dispatch with (%d - error code) and (%s - error description).\n", error_code, description);
    });
    this->CreateContext();
}

Warp::WindowContext::~WindowContext()
{
    this->DestroyContext();
}

void Warp::WindowContext::CreateContext()
{
    if (!glfwInit())
    {
        fprintf(stderr, "%s\n", "failed to initialize GLFW.");
        return;
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
        return;
    }
    glfwMakeContextCurrent(m_GLFWindow);
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "%s\n", "failed to initialize GLEW.");
        glfwDestroyWindow(m_GLFWindow);
        glfwTerminate();
        return;
    }
    glfwSwapInterval(SWAP_INTERVAL_DEFAULT);
    this->s_initialized = TRUE;
}

// TODO: finish implementing a handlers - (Warp::WindowContext::EnableHandlers)

void Warp::WindowContext::EnableHandlers()
{
    glfwSetKeyCallback(m_GLFWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        fprintf(stdout, "key callback registered a (key = %d) - (scancode = %d) - (action = %d) - (mods = %d)\n", key, scancode, action, mods);
    });
}

// TODO: finish implementing a handlers - (Warp::WindowContext::DisableHandlers)

void Warp::WindowContext::DisableHandlers()
{
    glfwSetKeyCallback(m_GLFWindow, nullptr);
}

void Warp::WindowContext::DestroyContext()
{
    if (s_initialized == TRUE)
        glfwTerminate();
    if (m_GLFWindow != nullptr)
        glfwDestroyWindow(m_GLFWindow);
}
