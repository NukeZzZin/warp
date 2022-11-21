#include "../includes/window.hpp"

Warp::WindowContext::WindowContext(unsigned int width, unsigned int height, const char* title)
{
    this->m_GLFWindow = nullptr;
    this->s_width = width;
    this->s_height = height;
    this->s_title = title;

    glfwSetErrorCallback([](int error_code, const char* description) {
        fprintf(stderr, "[ERROR] - error registered a (error code = %d) and (error description = %s).\n", error_code, description);
    });

    this->CreateContext();
    this->CreateHandlers();
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
        fprintf(stderr, "[ERROR] - failed to initialize GLFW.\n");
        return;
    }
    // ! glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // ? glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    this->m_GLFWindow = glfwCreateWindow(this->s_width, this->s_height, this->s_title, nullptr, nullptr);
    if (this->m_GLFWindow == nullptr)
    {
        fprintf(stderr, "[ERROR] - failed to initialize GLFW Window.\n");
        glfwTerminate();
        return;
    }
    glfwSetWindowUserPointer(this->m_GLFWindow, this);
    glfwMakeContextCurrent(this->m_GLFWindow);
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "[ERROR] - failed to initialize GLEW.\n");
        glfwDestroyWindow(this->m_GLFWindow);
        glfwTerminate();
        return;
    }
    glfwSwapInterval(SWAP_INTERVAL_DEFAULT);
    this->s_initialized = TRUE;
}

void Warp::WindowContext::DestroyContext()
{
    this->DestroyHandlers();
    fprintf(stdout, "[INFO] - window closing registered a (pointer = 0x%p) - (name = %s).\n", this->m_GLFWindow, this->s_title);
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
    glfwSetWindowRefreshCallback(this->m_GLFWindow, [](GLFWwindow* window) {
        WindowContext* windowContext = static_cast<WindowContext*>(glfwGetWindowUserPointer(window));
        int width, height;
		glfwGetWindowSize(window, &width, &height);
        windowContext->s_width = width;
        windowContext->s_height = height;
        glViewport(0, 0, static_cast<int>(windowContext->s_width), static_cast<int>(windowContext->s_height));
        glScissor(0, 0, static_cast<int>(windowContext->s_width), static_cast<int>(windowContext->s_height));
        fprintf(stdout, "[INFO] - window viewport change registered a (width = %d) - (height = %d).\n", windowContext->s_width, windowContext->s_height);
    });

    glfwSetMouseButtonCallback(this->m_GLFWindow, [](GLFWwindow* window, int button, int action, int mods) {
        WindowContext* windowContext = static_cast<WindowContext*>(glfwGetWindowUserPointer(window));
        fprintf(stdout, "[INFO] - mouse callback registered a (button = %d) - (action = %d) - (mods = %d).\n", button, action, mods);
    });

    glfwSetKeyCallback(this->m_GLFWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        WindowContext* windowContext = static_cast<WindowContext*>(glfwGetWindowUserPointer(window));
        fprintf(stdout, "[INFO] - keyboard callback registered a (key = %d) - (scancode = %d) - (action = %d) - (mods = %d).\n", key, scancode, action, mods);
    });

    glfwSetCursorPosCallback(this->m_GLFWindow, [](GLFWwindow* window, double xpos, double ypos) {
        WindowContext* windowContext = static_cast<WindowContext*>(glfwGetWindowUserPointer(window));
        fprintf(stdout, "[INFO] - mouse callback registered a (xpos = %f) - (ypos = %f).\n", xpos, ypos);
    });
}

// TODO: finish implementing a handlers - (Warp::WindowContext::DestroyHandlers)

void Warp::WindowContext::DestroyHandlers()
{
    glfwSetWindowRefreshCallback(this->m_GLFWindow, nullptr);
    glfwSetMouseButtonCallback(this->m_GLFWindow, nullptr);
    glfwSetKeyCallback(this->m_GLFWindow, nullptr);
    glfwSetCursorPosCallback(this->m_GLFWindow, nullptr);
}