# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/olympichek/CppProjects/Tasks03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olympichek/CppProjects/Tasks03/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task06c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task06c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task06c.dir/flags.make

CMakeFiles/task06c.dir/task06c.cpp.o: CMakeFiles/task06c.dir/flags.make
CMakeFiles/task06c.dir/task06c.cpp.o: ../task06c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olympichek/CppProjects/Tasks03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task06c.dir/task06c.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task06c.dir/task06c.cpp.o -c /home/olympichek/CppProjects/Tasks03/task06c.cpp

CMakeFiles/task06c.dir/task06c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task06c.dir/task06c.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olympichek/CppProjects/Tasks03/task06c.cpp > CMakeFiles/task06c.dir/task06c.cpp.i

CMakeFiles/task06c.dir/task06c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task06c.dir/task06c.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olympichek/CppProjects/Tasks03/task06c.cpp -o CMakeFiles/task06c.dir/task06c.cpp.s

# Object files for target task06c
task06c_OBJECTS = \
"CMakeFiles/task06c.dir/task06c.cpp.o"

# External object files for target task06c
task06c_EXTERNAL_OBJECTS =

task06c: CMakeFiles/task06c.dir/task06c.cpp.o
task06c: CMakeFiles/task06c.dir/build.make
task06c: CMakeFiles/task06c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olympichek/CppProjects/Tasks03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task06c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task06c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task06c.dir/build: task06c

.PHONY : CMakeFiles/task06c.dir/build

CMakeFiles/task06c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task06c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task06c.dir/clean

CMakeFiles/task06c.dir/depend:
	cd /home/olympichek/CppProjects/Tasks03/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olympichek/CppProjects/Tasks03 /home/olympichek/CppProjects/Tasks03 /home/olympichek/CppProjects/Tasks03/cmake-build-debug /home/olympichek/CppProjects/Tasks03/cmake-build-debug /home/olympichek/CppProjects/Tasks03/cmake-build-debug/CMakeFiles/task06c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task06c.dir/depend

