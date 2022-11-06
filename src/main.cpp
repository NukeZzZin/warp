#include "../includes/window.h"

int main(int argc, char** argv)
{
    WinContext* context = createContext(1280, 720, "Game Development");
    if (context == nullptr)
    {
        fprintf(stderr, "%s", "failed to create WinContext.\n");
        return EXIT_FAILURE;
    }
    while (!glfwWindowShouldClose(context->m_window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // if (glfwGetKey(context->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        // {
        //     glfwSetWindowShouldClose(context->m_window, GL_TRUE);
        // }
        glfwSwapBuffers(context->m_window);
        glfwPollEvents();
    }
    glfwDestroyWindow(context->m_window);
    glfwTerminate();
    return EXIT_SUCCESS;
}