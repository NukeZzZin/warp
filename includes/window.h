#ifndef _GAME_WINDOW_HEDEAR_
#define _GAME_WINDOW_HEDEAR_

#include <stdio.h>
#include <windows.h>
#include <glfw/glfw3.h>

struct Context
{
    GLFWwindow* m_window;
};
Context* createContext(int width, int heigth, const char* title);

#endif