# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/steady/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6707.69/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/steady/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6707.69/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/steady/桌面/workspace/Data-Structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/steady/桌面/workspace/Data-Structure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/alog271.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alog271.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alog271.dir/flags.make

CMakeFiles/alog271.dir/ch2/Algo2-7.c.o: CMakeFiles/alog271.dir/flags.make
CMakeFiles/alog271.dir/ch2/Algo2-7.c.o: ch2/Algo2-7.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steady/桌面/workspace/Data-Structure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/alog271.dir/ch2/Algo2-7.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/alog271.dir/ch2/Algo2-7.c.o   -c /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/ch2/Algo2-7.c

CMakeFiles/alog271.dir/ch2/Algo2-7.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/alog271.dir/ch2/Algo2-7.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/ch2/Algo2-7.c > CMakeFiles/alog271.dir/ch2/Algo2-7.c.i

CMakeFiles/alog271.dir/ch2/Algo2-7.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/alog271.dir/ch2/Algo2-7.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/ch2/Algo2-7.c -o CMakeFiles/alog271.dir/ch2/Algo2-7.c.s

# Object files for target alog271
alog271_OBJECTS = \
"CMakeFiles/alog271.dir/ch2/Algo2-7.c.o"

# External object files for target alog271
alog271_EXTERNAL_OBJECTS =

alog271: CMakeFiles/alog271.dir/ch2/Algo2-7.c.o
alog271: CMakeFiles/alog271.dir/build.make
alog271: CMakeFiles/alog271.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/steady/桌面/workspace/Data-Structure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable alog271"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alog271.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alog271.dir/build: alog271

.PHONY : CMakeFiles/alog271.dir/build

CMakeFiles/alog271.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alog271.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alog271.dir/clean

CMakeFiles/alog271.dir/depend:
	cd /home/steady/桌面/workspace/Data-Structure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/steady/桌面/workspace/Data-Structure /home/steady/桌面/workspace/Data-Structure /home/steady/桌面/workspace/Data-Structure/cmake-build-debug /home/steady/桌面/workspace/Data-Structure/cmake-build-debug /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/CMakeFiles/alog271.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alog271.dir/depend

