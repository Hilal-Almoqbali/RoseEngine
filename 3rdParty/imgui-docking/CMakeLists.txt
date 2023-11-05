cmake_minimum_required(VERSION 3.26)
project(imgui)
FILE(GLOB SRC
  "./*.cpp"
  "./backends/*.cpp"
)
add_library(imgui STATIC ${SRC})
target_include_directories(imgui PUBLIC ./ ./backends/)
target_link_libraries(imgui PUBLIC glfw)