cmake_minimum_required(VERSION 3.25.1)

project(Fish)
#if (WIN32)
#   add_definitions(-DFOO)
#endif (WIN32)


#if (UNIX)
#   add_definitions(-DFOO)
#endif (UNIX)


set(INCLUDE_FILES
  ./Engine
  ./3rdParty
)

set(SRC_FILES
PlayGround/sandbox.cc

)

message(STATUS "files that ready to compile are ${SRC_FILES}")
message(STATUS "include the folowing files ${INCLUDE_FILES}")

FILE(GLOB FishEngine_SRC
  "${CMAKE_SOURCE_DIR}/Engine/core/*.cc"
)

#
add_library(FishEngine SHARED ${FishEngine_SRC})
target_include_directories(FishEngine PUBLIC ./Engine/)



add_executable(sandbox ${SRC_FILES})
target_include_directories(sandbox PUBLIC ${INCLUDE_FILES})
target_link_libraries(sandbox FishEngine)
