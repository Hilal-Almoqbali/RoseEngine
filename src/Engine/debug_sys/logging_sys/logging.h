#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace fish{
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

#define CORE_TRACE(...) fish::log::GetCoreLogger()->trace(__VA_ARGS__);
#define CORE_INFO(...)  fish::log::GetCoreLogger()->info(__VA_ARGS__);
#define CORE_WARN(...)  fish::log::GetCoreLogger()->warn(__VA_ARGS__);
#define CORE_ERROR(...) fish::log::GetCoreLogger()->error(__VA_ARGS__);

#define CLIENT_TRACE(...) fish::log::GetClientLogger()->trace(__VA_ARGS__);
#define CLIENT_INFO(...)  fish::log::GetClientLogger()->info(__VA_ARGS__);
#define CLIENT_WARN(...)  fish::log::GetClientLogger()->warn(__VA_ARGS__);
#define CLIENT_ERROR(...) fish::log::GetClientLogger()->error(__VA_ARGS__);