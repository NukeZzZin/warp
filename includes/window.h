#ifndef _GAME_WINDOW_HEDEAR_
#define _GAME_WINDOW_HEDEAR_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <gl/glew.h>
#include <glfw/glfw3.h>

struct WinContext
{
    GLFWwindow* m_window;
};
WinContext* createContext(int width, int heigth, const char* title);

#endif