#ifndef _GAME_WINDOW_HEDEAR_
#define _GAME_WINDOW_HEDEAR_

#define GLFW_INCLUDE_NONE

#define MAJOR_VERSION 3
#define MINOR_VERSION 3

// #define WINDOW_TITLE "Warp"
// #define WINDOW_WIDTH 1024
// #define WINDOW_HEIGTH 768

#define SWAP_INTERVAL_DEFAULT 1

#include <stdio.h>
#include <windows.h>

#include <glfw/glfw3.h>
#include <gl/glew.h>
#include <gl/gl.h>

namespace Warp
{
    namespace Window
    {
        typedef struct WinContext
        {
            GLFWwindow* m_window;
            unsigned int s_width, s_heigth;
            const char* s_title;
            bool s_initialized;
        } WinContext;
        // * initialize a window context.
        WinContext* createContext(unsigned int width, unsigned int heigth, const char* title);
        // * destroy a window context.
        void destroyContext(WinContext* context);
    }
}

#endif