#pragma once
#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define WINDOWED_WINDOW 0
#define WINDOWED_FULL_SCREEN_WINDOW 1
#define FULL_SCREEN 2
#define OPENGL_WINDOW_API 0
#define VULKAN_WINDOW_API 1
struct window_data
    {
        std::string window_name;
        unsigned int width,hight;
        unsigned int window_mode = WINDOWED_WINDOW;
        bool Graphics_API = OPENGL_WINDOW_API;
        bool VSync_mode = 1;
    };
class window_sys
{
    public:
    window_sys(window_data data);
    ~window_sys(){} //TODO: add delete window here.
    bool window_isnt_closed(void) {return !glfwWindowShouldClose(m_window);}
    void update_frame_buffer()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
    private:
    GLFWwindow* m_window;
};
