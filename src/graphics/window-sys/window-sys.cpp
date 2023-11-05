#include<window-sys.h>
#include<iostream>
namespace fish{
window_sys::window_sys(window_data data)
{
    glfwInit();
    if(data.Graphics_API)
    {
        std::cout<<"we dosent support vulkan yet\n";
    }
    else
    {
        glfwWindowHint(GLFW_CENTER_CURSOR, data.CenterCursor);
        glfwWindowHint(GLFW_MAXIMIZED, data.maximized);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    if(data.window_mode == 0)
    {
        std::cout<<"info: makeing a windowed window\n";
        m_window = glfwCreateWindow(data.width, data.hight, data.window_name.c_str(), NULL, NULL);
    }
    if(data.window_mode == 1)
        {
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
            m_window = glfwCreateWindow(mode->width, mode->height, data.window_name.c_str(), glfwGetPrimaryMonitor(), NULL);
        }
    if(data.window_mode == 2)
        {
            m_window = glfwCreateWindow(data.width, data.hight, data.window_name.c_str(), glfwGetPrimaryMonitor(), NULL);
        }
        
    if (!m_window){std::cout<<"window system failure\n --recomed to cheack opengl version if it was not 3.x.x\n";};
    glfwSwapInterval(data.VSync_mode);
    glfwMakeContextCurrent(m_window);
    if(data.Graphics_API)
    {
        std::cout<<"we dosent support vulkan yet\n";
    }
    else
    {
        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int hight)
            {
                glViewport(0, 0, width, hight);
            });
    }
}
}