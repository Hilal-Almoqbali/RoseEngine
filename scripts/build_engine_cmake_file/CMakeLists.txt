cmake_minimum_required(VERSION 3.26)
project(engine)
add_subdirectory(3rdParty)

FILE(GLOB Engine_SRC
  "${CMAKE_SOURCE_DIR}/src/Engine/Graphics/*.cpp"
  "${CMAKE_SOURCE_DIR}/src/Engine/Editor/2D_Editor/*.cpp"
)
add_library(engine STATIC ${Engine_SRC})
#add_executable(test ./src/Engine/helloworld.cpp)
target_link_libraries(engine PUBLIC glfw)
target_link_libraries(engine PUBLIC glad)
target_link_libraries(engine PUBLIC imgui)
target_include_directories(engine PUBLIC ${INCLUDE})
target_include_directories(engine PUBLIC ./src/ ./src/**/ ./3rdParty/)
add_executable(test ./src/test.cpp)
target_link_libraries(test PUBLIC engine)
target_include_directories(engine PUBLIC ${INCLUDE})
target_include_directories(engine PUBLIC 
  ./src/ 
  ./src/Engine/Graphics 
  ./src/Engine/Editor/2D_Editor/
  ./3rdParty/
  )