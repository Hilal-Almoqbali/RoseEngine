# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hilal/Development/GameEngineDevelopment/FishEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test

# Include any dependencies generated for this target.
include src/Engine/core/window-sys/CMakeFiles/window_sys.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Engine/core/window-sys/CMakeFiles/window_sys.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Engine/core/window-sys/CMakeFiles/window_sys.dir/progress.make

# Include the compile flags for this target's objects.
include src/Engine/core/window-sys/CMakeFiles/window_sys.dir/flags.make

src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.o: src/Engine/core/window-sys/CMakeFiles/window_sys.dir/flags.make
src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.o: /home/hilal/Development/GameEngineDevelopment/FishEngine/src/Engine/core/window-sys/window-sys.cpp
src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.o: src/Engine/core/window-sys/CMakeFiles/window_sys.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.o"
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.o -MF CMakeFiles/window_sys.dir/window-sys.cpp.o.d -o CMakeFiles/window_sys.dir/window-sys.cpp.o -c /home/hilal/Development/GameEngineDevelopment/FishEngine/src/Engine/core/window-sys/window-sys.cpp

src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/window_sys.dir/window-sys.cpp.i"
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hilal/Development/GameEngineDevelopment/FishEngine/src/Engine/core/window-sys/window-sys.cpp > CMakeFiles/window_sys.dir/window-sys.cpp.i

src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/window_sys.dir/window-sys.cpp.s"
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hilal/Development/GameEngineDevelopment/FishEngine/src/Engine/core/window-sys/window-sys.cpp -o CMakeFiles/window_sys.dir/window-sys.cpp.s

# Object files for target window_sys
window_sys_OBJECTS = \
"CMakeFiles/window_sys.dir/window-sys.cpp.o"

# External object files for target window_sys
window_sys_EXTERNAL_OBJECTS =

src/Engine/core/window-sys/libwindow_sys.a: src/Engine/core/window-sys/CMakeFiles/window_sys.dir/window-sys.cpp.o
src/Engine/core/window-sys/libwindow_sys.a: src/Engine/core/window-sys/CMakeFiles/window_sys.dir/build.make
src/Engine/core/window-sys/libwindow_sys.a: src/Engine/core/window-sys/CMakeFiles/window_sys.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libwindow_sys.a"
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys && $(CMAKE_COMMAND) -P CMakeFiles/window_sys.dir/cmake_clean_target.cmake
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/window_sys.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Engine/core/window-sys/CMakeFiles/window_sys.dir/build: src/Engine/core/window-sys/libwindow_sys.a
.PHONY : src/Engine/core/window-sys/CMakeFiles/window_sys.dir/build

src/Engine/core/window-sys/CMakeFiles/window_sys.dir/clean:
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys && $(CMAKE_COMMAND) -P CMakeFiles/window_sys.dir/cmake_clean.cmake
.PHONY : src/Engine/core/window-sys/CMakeFiles/window_sys.dir/clean

src/Engine/core/window-sys/CMakeFiles/window_sys.dir/depend:
	cd /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hilal/Development/GameEngineDevelopment/FishEngine /home/hilal/Development/GameEngineDevelopment/FishEngine/src/Engine/core/window-sys /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys /home/hilal/Development/GameEngineDevelopment/FishEngine/build_test/src/Engine/core/window-sys/CMakeFiles/window_sys.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/Engine/core/window-sys/CMakeFiles/window_sys.dir/depend

