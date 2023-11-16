#include <event.h>

namespce fish
{
    event::event(GLFWwindow window)
    {
        if (glfwRawMouseMotionSupported()){glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);}
        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                key.keycode=key;
                key.key_action=action;
            });
        glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
            {
                mouse.xpos=xpos;
                mouse.ypos=ypos;
            });
        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
            {
                mouse.button_code = button;
                button_action = action;
            });
        glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset)
            {
                mouse.xoffset=xoffset;
                mouse.yoffset=yoffset;
            });
    }
    bool event::are_key_is(unsigned int in_key_code, unsigned int in_key_action, unsigned int in_other_key_action = false) 
    {return key.keycode==in_key_code & key.key_action==in_key_action||in_other_key_action? true:false}
    
    bool event::are_mouse_button_is(unsigned int in_button_code, unsigned int in_button_mode, unsigned int in_other_button_action = false)
    {return mouse.button_code==in_button_code & mouse.button_action==in_button_action||in_other_button_action? true:false}
    
    
}