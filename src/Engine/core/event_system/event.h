#pragma once
#include <iostream>
#include <functional>
#include <GLFW/glfw3.h>

namespace fish
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
	};
	
    class event//TODO(hilal): finish this
    {
        public:
        event(GLFWwindow window);
        ~event();
        //keyboard
        bool are_key_is(unsigned int in_key_code, unsigned int in_key_action, unsigned int in_other_key_action = false);
        //mouse
        glm::vec2 get_mouse_pos();//TODO(hilal): impliment glm
        bool are_mouse_button_is(unsigned int in_button_code, unsigned int in_button_mode, unsigned int in_other_button_action = false);
        glm::vec2 get_mouse_scrool_offset();//TODO(hilal): impliment glm
        //application
        void close();
        void resize();
        private:
        struct key_events
        {
            unsigned int key_code;
            unsigned int key_action;
        } key;
        struct mouse_events
        {
            double xpos;
            double ypos;
            unsigned int button_code;
            unsigned int button_action;
            double xoffset;
            double yoffset;
        } mouse;
    };
}