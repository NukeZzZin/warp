#include "../includes/window.h"

int main(int argc, char** argv)
{
    warp::Window* window = warp::createWindow(800, 600, "Window");
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    while (!glfwWindowShouldClose(window->m_window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(window->m_window);
        glfwSwapInterval(1);
    }
    return EXIT_SUCCESS;
}