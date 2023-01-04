#include <GLFW/glfw3.h>

#pragma once

class Window{
    private:
        GLFWwindow* m_Window;
        static void error_callback(int error, const char* description);

    public:
        Window(int w, int h, const char* title);
        void update();
        ~Window();
};