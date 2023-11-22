cmake_minimum_required(VERSION 3.26)
add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(imgui)
add_subdirectory(spdlog)
set(INCLUDE
    ./glfw/include/
    ./glad/include/
    ./spdlog/include/
    ./glm/
)