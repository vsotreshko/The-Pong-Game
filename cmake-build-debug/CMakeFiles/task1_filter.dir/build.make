# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vsotreshko/Documents/5.Semester/The-Pong-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task1_filter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task1_filter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task1_filter.dir/flags.make

CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.o: CMakeFiles/task1_filter.dir/flags.make
CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.o: ../src/task1_filter/task1_filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/src/task1_filter/task1_filter.cpp

CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/src/task1_filter/task1_filter.cpp > CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.i

CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/src/task1_filter/task1_filter.cpp -o CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.s

# Object files for target task1_filter
task1_filter_OBJECTS = \
"CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.o"

# External object files for target task1_filter
task1_filter_EXTERNAL_OBJECTS =

task1_filter: CMakeFiles/task1_filter.dir/src/task1_filter/task1_filter.cpp.o
task1_filter: CMakeFiles/task1_filter.dir/build.make
task1_filter: libppgso.a
task1_filter: /usr/lib/x86_64-linux-gnu/libglfw.so
task1_filter: /usr/lib/x86_64-linux-gnu/libGLEW.so
task1_filter: /usr/lib/x86_64-linux-gnu/libGL.so
task1_filter: /usr/lib/x86_64-linux-gnu/libGLU.so
task1_filter: CMakeFiles/task1_filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task1_filter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task1_filter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task1_filter.dir/build: task1_filter

.PHONY : CMakeFiles/task1_filter.dir/build

CMakeFiles/task1_filter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task1_filter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task1_filter.dir/clean

CMakeFiles/task1_filter.dir/depend:
	cd /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vsotreshko/Documents/5.Semester/The-Pong-Game /home/vsotreshko/Documents/5.Semester/The-Pong-Game /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles/task1_filter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task1_filter.dir/depend

