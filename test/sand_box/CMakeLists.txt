add_executable(sandbox ./sandboxapp.cpp )
target_link_libraries(sandbox PUBLIC RoseCore)
target_include_directories(sandbox PUBLIC ${INCLUDE} ../../src/Engine/)