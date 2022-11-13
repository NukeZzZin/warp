#include "../includes/window.hpp"

int main(int argc, char** argv)
{
    Warp::WindowContext WindowContext(1024, 768, "Window's");
    while (!WindowContext.GetWindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        WindowContext.SetSwapBuffers();
        glfwPollEvents();
    }
    WindowContext.DestroyContext();
    return EXIT_SUCCESS;
}