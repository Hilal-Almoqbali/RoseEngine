#include<logging.h>

    std::shared_ptr<spdlog::logger> fish::log::s_CoreLogs;
    std::shared_ptr<spdlog::logger> fish::log::s_ClientLogs;

void fish::log::init()
{
    spdlog::set_pattern("%^[%T.%e] [%l] [%n]:%$ %v");
    s_CoreLogs = spdlog::stdout_color_mt("Core");
    s_CoreLogs->set_level(spdlog::level::trace);
    s_ClientLogs = spdlog::stdout_color_mt("Client");
    s_ClientLogs->set_level(spdlog::level::trace);
}

