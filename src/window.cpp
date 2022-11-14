#include "../includes/window.hpp"

Warp::WindowContext::WindowContext(unsigned int width, unsigned int height, const char* title)
{
    this->m_GLFWindow = nullptr;
    this->m_DATAWindow.s_width = width;
    this->m_DATAWindow.s_height = height;
    this->m_DATAWindow.s_title = title;

    glfwSetErrorCallback([](int error_code, const char* description) {
        fprintf(stderr, "error registered a (%d - error code) and (%s - error description).\n", error_code, description);
    });

    this->CreateContext();
}

Warp::WindowContext::~WindowContext()
{
    this->DestroyContext();
    this->s_initialized = FALSE;
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
    glfwSetWindowUserPointer(m_GLFWindow, this);
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

void Warp::WindowContext::DestroyContext()
{
    this->DestroyHandlers();
    fprintf(stdout, "window closing registered a (pointer = 0x%p) - (name = %s)\n", this->m_GLFWindow, this->m_DATAWindow.s_title);
    if (this->m_GLFWindow != nullptr)
    {
        glfwDestroyWindow(this->m_GLFWindow);
        this->m_GLFWindow = nullptr;
    }
    glfwTerminate();
}

// TODO: finish implementing a handlers - (Warp::WindowContext::CreateHandlers)

void Warp::WindowContext::CreateHandlers()
{
    glfwSetWindowRefreshCallback(m_GLFWindow, [](GLFWwindow* window) {
        Warp::WindowContext* windowContext = reinterpret_cast<WindowContext*>(glfwGetWindowUserPointer(window));
        int width, height;
		glfwGetWindowSize(window, &width, &height);
        windowContext->m_DATAWindow.s_width = width;
        windowContext->m_DATAWindow.s_height = height;
        glViewport(0, 0, static_cast<int>(windowContext->m_DATAWindow.s_width), static_cast<int>(windowContext->m_DATAWindow.s_height));
        glScissor(0, 0, static_cast<int>(windowContext->m_DATAWindow.s_width), static_cast<int>(windowContext->m_DATAWindow.s_height));
        fprintf(stdout, "window viewport change registered a (width = %d) - (height = %d)\n", windowContext->m_DATAWindow.s_width, windowContext->m_DATAWindow.s_height);
    });

    glfwSetKeyCallback(m_GLFWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        fprintf(stdout, "key callback registered a (key = %d) - (scancode = %d) - (action = %d) - (mods = %d)\n", key, scancode, action, mods);
    });
}

// TODO: finish implementing a handlers - (Warp::WindowContext::DestroyHandlers)

void Warp::WindowContext::DestroyHandlers()
{
    glfwSetWindowRefreshCallback(m_GLFWindow, nullptr);
    glfwSetKeyCallback(m_GLFWindow, nullptr);
}