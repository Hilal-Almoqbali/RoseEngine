#include <iostream>
#include <logging.h>
class app
{
    public:
    void run()
    {
        fish::log::init();
        CORE_INFO("somting is happening!");
        CORE_WARN("somting is happening!");
        CORE_ERROR("somting is happening!");
        CORE_TRACE("somting is happening!");
        CLIENT_INFO("somting is happening!");
        CLIENT_WARN("somting is happening!");
        CLIENT_ERROR("somting is happening!");
        CLIENT_TRACE("somting is happening!");
    }
};
int main()
{
    app log_sys;
    log_sys.run();
    
    return 0;
}