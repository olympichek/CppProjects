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
CMAKE_SOURCE_DIR = /home/olympichek/CppProjects/Tasks02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olympichek/CppProjects/Tasks02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task02.dir/flags.make

CMakeFiles/task02.dir/task02.cpp.o: CMakeFiles/task02.dir/flags.make
CMakeFiles/task02.dir/task02.cpp.o: ../task02.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olympichek/CppProjects/Tasks02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task02.dir/task02.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task02.dir/task02.cpp.o -c /home/olympichek/CppProjects/Tasks02/task02.cpp

CMakeFiles/task02.dir/task02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task02.dir/task02.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olympichek/CppProjects/Tasks02/task02.cpp > CMakeFiles/task02.dir/task02.cpp.i

CMakeFiles/task02.dir/task02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task02.dir/task02.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olympichek/CppProjects/Tasks02/task02.cpp -o CMakeFiles/task02.dir/task02.cpp.s

# Object files for target task02
task02_OBJECTS = \
"CMakeFiles/task02.dir/task02.cpp.o"

# External object files for target task02
task02_EXTERNAL_OBJECTS =

task02: CMakeFiles/task02.dir/task02.cpp.o
task02: CMakeFiles/task02.dir/build.make
task02: CMakeFiles/task02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olympichek/CppProjects/Tasks02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task02.dir/build: task02

.PHONY : CMakeFiles/task02.dir/build

CMakeFiles/task02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task02.dir/clean

CMakeFiles/task02.dir/depend:
	cd /home/olympichek/CppProjects/Tasks02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olympichek/CppProjects/Tasks02 /home/olympichek/CppProjects/Tasks02 /home/olympichek/CppProjects/Tasks02/cmake-build-debug /home/olympichek/CppProjects/Tasks02/cmake-build-debug /home/olympichek/CppProjects/Tasks02/cmake-build-debug/CMakeFiles/task02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task02.dir/depend

