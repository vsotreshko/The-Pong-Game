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
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vsotreshko/Documents/5.Semester/The-Pong-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/shaders.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shaders.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shaders.dir/flags.make

shaders/color_vert_glsl.cpp: ../shader/color_vert.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/color_vert.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_vert_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_vert_glsl.h -DSYMBOL=color_vert_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/color_vert.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/color_vert_glsl.h: shaders/color_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/color_vert_glsl.h

shaders/color_frag_glsl.cpp: ../shader/color_frag.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/color_frag.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_frag_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_frag_glsl.h -DSYMBOL=color_frag_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/color_frag.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/color_frag_glsl.h: shaders/color_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/color_frag_glsl.h

shaders/convolution_vert_glsl.cpp: ../shader/convolution_vert.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/convolution_vert.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_vert_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_vert_glsl.h -DSYMBOL=convolution_vert_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/convolution_vert.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/convolution_vert_glsl.h: shaders/convolution_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/convolution_vert_glsl.h

shaders/convolution_frag_glsl.cpp: ../shader/convolution_frag.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/convolution_frag.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_frag_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_frag_glsl.h -DSYMBOL=convolution_frag_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/convolution_frag.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/convolution_frag_glsl.h: shaders/convolution_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/convolution_frag_glsl.h

shaders/diffuse_vert_glsl.cpp: ../shader/diffuse_vert.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/diffuse_vert.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_vert_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_vert_glsl.h -DSYMBOL=diffuse_vert_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/diffuse_vert.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/diffuse_vert_glsl.h: shaders/diffuse_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/diffuse_vert_glsl.h

shaders/diffuse_frag_glsl.cpp: ../shader/diffuse_frag.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/diffuse_frag.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_frag_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_frag_glsl.h -DSYMBOL=diffuse_frag_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/diffuse_frag.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/diffuse_frag_glsl.h: shaders/diffuse_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/diffuse_frag_glsl.h

shaders/texture_vert_glsl.cpp: ../shader/texture_vert.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/texture_vert.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_vert_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_vert_glsl.h -DSYMBOL=texture_vert_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/texture_vert.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/texture_vert_glsl.h: shaders/texture_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/texture_vert_glsl.h

shaders/texture_frag_glsl.cpp: ../shader/texture_frag.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Generating resource from /home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/texture_frag.glsl"
	/snap/clion/99/bin/cmake/linux/bin/cmake -DOUTPUT_C=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_frag_glsl.cpp -DOUTPUT_H=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_frag_glsl.h -DSYMBOL=texture_frag_glsl -DINPUT_FILE=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/shader/texture_frag.glsl -P /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake/bin2c.cmake

shaders/texture_frag_glsl.h: shaders/texture_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate shaders/texture_frag_glsl.h

CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.o: shaders/color_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_vert_glsl.cpp

CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_vert_glsl.cpp > CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_vert_glsl.cpp -o CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.o: shaders/color_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_frag_glsl.cpp

CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_frag_glsl.cpp > CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/color_frag_glsl.cpp -o CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.o: shaders/convolution_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_vert_glsl.cpp

CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_vert_glsl.cpp > CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_vert_glsl.cpp -o CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.o: shaders/convolution_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_frag_glsl.cpp

CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_frag_glsl.cpp > CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/convolution_frag_glsl.cpp -o CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.o: shaders/diffuse_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_vert_glsl.cpp

CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_vert_glsl.cpp > CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_vert_glsl.cpp -o CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.o: shaders/diffuse_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_frag_glsl.cpp

CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_frag_glsl.cpp > CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/diffuse_frag_glsl.cpp -o CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.o: shaders/texture_vert_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_vert_glsl.cpp

CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_vert_glsl.cpp > CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_vert_glsl.cpp -o CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.s

CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.o: CMakeFiles/shaders.dir/flags.make
CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.o: shaders/texture_frag_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.o -c /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_frag_glsl.cpp

CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_frag_glsl.cpp > CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.i

CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/shaders/texture_frag_glsl.cpp -o CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.s

# Object files for target shaders
shaders_OBJECTS = \
"CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.o" \
"CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.o"

# External object files for target shaders
shaders_EXTERNAL_OBJECTS =

libshaders.a: CMakeFiles/shaders.dir/shaders/color_vert_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/color_frag_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/convolution_vert_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/convolution_frag_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/diffuse_vert_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/diffuse_frag_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/texture_vert_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/shaders/texture_frag_glsl.cpp.o
libshaders.a: CMakeFiles/shaders.dir/build.make
libshaders.a: CMakeFiles/shaders.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX static library libshaders.a"
	$(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shaders.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shaders.dir/build: libshaders.a

.PHONY : CMakeFiles/shaders.dir/build

CMakeFiles/shaders.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shaders.dir/clean

CMakeFiles/shaders.dir/depend: shaders/color_vert_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/color_vert_glsl.h
CMakeFiles/shaders.dir/depend: shaders/color_frag_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/color_frag_glsl.h
CMakeFiles/shaders.dir/depend: shaders/convolution_vert_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/convolution_vert_glsl.h
CMakeFiles/shaders.dir/depend: shaders/convolution_frag_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/convolution_frag_glsl.h
CMakeFiles/shaders.dir/depend: shaders/diffuse_vert_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/diffuse_vert_glsl.h
CMakeFiles/shaders.dir/depend: shaders/diffuse_frag_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/diffuse_frag_glsl.h
CMakeFiles/shaders.dir/depend: shaders/texture_vert_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/texture_vert_glsl.h
CMakeFiles/shaders.dir/depend: shaders/texture_frag_glsl.cpp
CMakeFiles/shaders.dir/depend: shaders/texture_frag_glsl.h
	cd /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vsotreshko/Documents/5.Semester/The-Pong-Game /home/vsotreshko/Documents/5.Semester/The-Pong-Game /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug /home/vsotreshko/Documents/5.Semester/The-Pong-Game/cmake-build-debug/CMakeFiles/shaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shaders.dir/depend

