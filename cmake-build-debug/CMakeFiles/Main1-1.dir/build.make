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
include CMakeFiles/Main1-1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main1-1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main1-1.dir/flags.make

CMakeFiles/Main1-1.dir/ch1/Main1-1.c.o: CMakeFiles/Main1-1.dir/flags.make
CMakeFiles/Main1-1.dir/ch1/Main1-1.c.o: ch1/Main1-1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steady/桌面/workspace/Data-Structure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Main1-1.dir/ch1/Main1-1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Main1-1.dir/ch1/Main1-1.c.o   -c /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/ch1/Main1-1.c

CMakeFiles/Main1-1.dir/ch1/Main1-1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Main1-1.dir/ch1/Main1-1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/ch1/Main1-1.c > CMakeFiles/Main1-1.dir/ch1/Main1-1.c.i

CMakeFiles/Main1-1.dir/ch1/Main1-1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Main1-1.dir/ch1/Main1-1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/ch1/Main1-1.c -o CMakeFiles/Main1-1.dir/ch1/Main1-1.c.s

# Object files for target Main1-1
Main1__1_OBJECTS = \
"CMakeFiles/Main1-1.dir/ch1/Main1-1.c.o"

# External object files for target Main1-1
Main1__1_EXTERNAL_OBJECTS =

Main1-1: CMakeFiles/Main1-1.dir/ch1/Main1-1.c.o
Main1-1: CMakeFiles/Main1-1.dir/build.make
Main1-1: CMakeFiles/Main1-1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/steady/桌面/workspace/Data-Structure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Main1-1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main1-1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main1-1.dir/build: Main1-1

.PHONY : CMakeFiles/Main1-1.dir/build

CMakeFiles/Main1-1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main1-1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main1-1.dir/clean

CMakeFiles/Main1-1.dir/depend:
	cd /home/steady/桌面/workspace/Data-Structure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/steady/桌面/workspace/Data-Structure /home/steady/桌面/workspace/Data-Structure /home/steady/桌面/workspace/Data-Structure/cmake-build-debug /home/steady/桌面/workspace/Data-Structure/cmake-build-debug /home/steady/桌面/workspace/Data-Structure/cmake-build-debug/CMakeFiles/Main1-1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main1-1.dir/depend

