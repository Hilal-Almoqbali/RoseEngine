add_library(logging_system logging.cpp)
target_include_directories(logging_system PUBLIC ./)
target_link_libraries(logging_system PUBLIC spdlog)
