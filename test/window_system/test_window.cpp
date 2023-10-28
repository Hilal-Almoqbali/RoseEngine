#include<window-sys.h>

int main(void)
{
    window_data window_info =
    {
    "window system test",
    600,
    400,
    WINDOWED_WINDOW,
    OPENGL_WINDOW_API,
    true
    };
    
    window_sys window(window_info);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){std::cout << "Failed to initialize GLAD" << std::endl;} // TODO: when you make the renderer move this line to there.    
    while(window.window_isnt_closed())
    {
        glClearColor(0.1, 0.2, 0.1, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        window.update_frame_buffer();
    }
    return 0;
}