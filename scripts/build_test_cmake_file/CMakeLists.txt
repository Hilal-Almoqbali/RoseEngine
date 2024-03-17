cmake_minimum_required(VERSION 3.26)
project(test)
add_subdirectory(3rdParty)
add_subdirectory(./src/Engine/core/window-sys/)
#add_subdirectory(./src/Engine/core/event_system/)
add_subdirectory(./src/Engine/debug_sys/logging_sys/)

add_executable(test_window_system ./test/window_system/test_window.cpp )
target_link_libraries(test_window_system PUBLIC window_sys)
#target_link_libraries(test_window_system PUBLIC event)
target_link_libraries(test_window_system PUBLIC glfw)
target_link_libraries(test_window_system PUBLIC glad)
target_link_libraries(test_window_system PUBLIC glm)
target_include_directories(test_window_system PUBLIC ${INCLUDE})

add_executable(logging_system_test ./test/logging_system/logging_system_test.cpp)
target_link_libraries(logging_system_test PUBLIC logging_system)

#sandbox
#add_subdirectory(./src/Engine/)#build core
#add_subdirectory(./test/sand_box/)#build sand box

