#include "../includes/window.h"

int main(int argc, char** argv)
{
    Context* context = createContext(800, 600, "Window");
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    int frameCount = 0;
    while (!glfwWindowShouldClose(context->m_window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(context->m_window);
        glfwSwapInterval(1);
    }
    return EXIT_SUCCESS;
}