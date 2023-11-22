#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace rose{
class log
{
    public:
    static void init();
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){return s_CoreLogs;};
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return s_ClientLogs;};
    
    private:
    static std::shared_ptr<spdlog::logger> s_CoreLogs;
    static std::shared_ptr<spdlog::logger> s_ClientLogs;
};
}

#define CORE_TRACE(...) rose::log::GetCoreLogger()->trace(__VA_ARGS__);
#define CORE_INFO(...)  rose::log::GetCoreLogger()->info(__VA_ARGS__);
#define CORE_WARN(...)  rose::log::GetCoreLogger()->warn(__VA_ARGS__);
#define CORE_ERROR(...) rose::log::GetCoreLogger()->error(__VA_ARGS__);

#define CLIENT_TRACE(...) rose::log::GetClientLogger()->trace(__VA_ARGS__);
#define CLIENT_INFO(...)  rose::log::GetClientLogger()->info(__VA_ARGS__);
#define CLIENT_WARN(...)  rose::log::GetClientLogger()->warn(__VA_ARGS__);
#define CLIENT_ERROR(...) rose::log::GetClientLogger()->error(__VA_ARGS__);