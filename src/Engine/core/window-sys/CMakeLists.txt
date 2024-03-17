
add_library(window_sys STATIC ${CMAKE_CURRENT_SOURCE_DIR}/window-sys.cpp)
target_include_directories(window_sys PUBLIC ./)
target_link_libraries(window_sys PUBLIC glfw)
target_link_libraries(window_sys PUBLIC glad)
target_link_libraries(window_sys PUBLIC glm)