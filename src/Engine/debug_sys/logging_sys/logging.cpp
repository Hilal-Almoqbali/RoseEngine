#include<logging.h>

    std::shared_ptr<spdlog::logger> rose::log::s_CoreLogs;
    std::shared_ptr<spdlog::logger> rose::log::s_ClientLogs;

void rose::log::init()
{
    spdlog::set_pattern("%^[%T.%e] [%l] [%n]:%$ %v");
    s_CoreLogs = spdlog::stdout_color_mt("Core");
    s_CoreLogs->set_level(spdlog::level::trace);
    s_ClientLogs = spdlog::stdout_color_mt("Client");
    s_ClientLogs->set_level(spdlog::level::trace);
}

