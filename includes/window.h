#ifndef _GAME_WINDOW_HEDEAR_
#define _GAME_WINDOW_HEDEAR_

#include <iostream>
#include <windows.h>
#include <glfw/glfw3.h>

namespace warp
{
    typedef struct Window
    {
        GLFWwindow* m_window;
        GLFWmonitor* m_monitor;
        const GLFWvidmode* m_video;
    } Window;
    Window* createWindow(int width, int heigth, const char* title);
}

#endif