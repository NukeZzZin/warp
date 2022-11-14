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
    typedef struct WindowProps
    {
        unsigned int s_width;
        unsigned int s_height;
        const char* s_title;
    } WindowProps;
    class WindowContext
    {
        protected:
        GLFWwindow* m_GLFWindow;
        WindowProps m_DATAWindow;
        BOOL s_initialized = FALSE;
        public:
        WindowContext(unsigned int, unsigned int, const char*);
        virtual ~WindowContext();

        void CreateContext();
        void DestroyContext();
        void CreateHandlers();
        void DestroyHandlers();

        inline void SwapBuffers() const { return glfwSwapBuffers(m_GLFWindow); };
        inline BOOL WindowShouldClose() const { return glfwWindowShouldClose(m_GLFWindow); };
        inline unsigned int GetWindowWidth() const { return m_DATAWindow.s_width; };
        inline unsigned int GetWindowHeigth() const { return m_DATAWindow.s_height; };
        inline const char* GetWindowTitle() const { return m_DATAWindow.s_title; };
        inline GLFWwindow* GetWindowInstance() const { return m_GLFWindow; };
    };
}

#endif