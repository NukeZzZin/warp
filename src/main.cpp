#include "../includes/window.hpp"

int main(int argc, char** argv)
{
    Warp::Window::WinContext* WinContext = Warp::Window::createContext(1028, 768, "Window's Title");
    while(!glfwWindowShouldClose(WinContext->m_window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(WinContext->m_window);
        glfwPollEvents();
    }
    Warp::Window::destroyContext(WinContext);
    return EXIT_SUCCESS;
}