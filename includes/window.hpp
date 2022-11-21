#ifndef _GAME_WINDOW_HEDEAR_
#define _GAME_WINDOW_HEDEAR_

#define GLFW_INCLUDE_NONE

#define MAJOR_VERSION 3
#define MINOR_VERSION 3

#define SWAP_INTERVAL_DEFAULT 1

#include <stdio.h>
#include <windows.h>

#include <glfw/glfw3.h>
#include <gl/glew.h>

namespace Warp
{
    class Window
    {
        protected:
            GLFWwindow* m_GLFWindow;
            BOOL s_initialized = FALSE;
            unsigned int s_width = 1024;
            unsigned int s_height = 768;
            const char* s_title = "Window's";
        public:
            Window(unsigned int, unsigned int, const char*);
            virtual ~Window();

            void CreateContext();
            void DestroyContext();
            void CreateHandlers();
            void DestroyHandlers();

            inline unsigned int GetWindowWidth() const { return s_width; };
            inline unsigned int GetWindowHeigth() const { return s_height; };
            inline const char* GetWindowTitle() const { return s_title; };
            inline GLFWwindow* GetWindowInstance() const { return m_GLFWindow; };
    };
}

#endif