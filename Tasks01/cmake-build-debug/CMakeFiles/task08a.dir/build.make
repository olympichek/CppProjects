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
CMAKE_SOURCE_DIR = /home/olympichek/CppProjects/Tasks01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olympichek/CppProjects/Tasks01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task08a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task08a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task08a.dir/flags.make

CMakeFiles/task08a.dir/task08a.cpp.o: CMakeFiles/task08a.dir/flags.make
CMakeFiles/task08a.dir/task08a.cpp.o: ../task08a.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olympichek/CppProjects/Tasks01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task08a.dir/task08a.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task08a.dir/task08a.cpp.o -c /home/olympichek/CppProjects/Tasks01/task08a.cpp

CMakeFiles/task08a.dir/task08a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task08a.dir/task08a.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olympichek/CppProjects/Tasks01/task08a.cpp > CMakeFiles/task08a.dir/task08a.cpp.i

CMakeFiles/task08a.dir/task08a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task08a.dir/task08a.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olympichek/CppProjects/Tasks01/task08a.cpp -o CMakeFiles/task08a.dir/task08a.cpp.s

# Object files for target task08a
task08a_OBJECTS = \
"CMakeFiles/task08a.dir/task08a.cpp.o"

# External object files for target task08a
task08a_EXTERNAL_OBJECTS =

task08a: CMakeFiles/task08a.dir/task08a.cpp.o
task08a: CMakeFiles/task08a.dir/build.make
task08a: CMakeFiles/task08a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olympichek/CppProjects/Tasks01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task08a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task08a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task08a.dir/build: task08a

.PHONY : CMakeFiles/task08a.dir/build

CMakeFiles/task08a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task08a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task08a.dir/clean

CMakeFiles/task08a.dir/depend:
	cd /home/olympichek/CppProjects/Tasks01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olympichek/CppProjects/Tasks01 /home/olympichek/CppProjects/Tasks01 /home/olympichek/CppProjects/Tasks01/cmake-build-debug /home/olympichek/CppProjects/Tasks01/cmake-build-debug /home/olympichek/CppProjects/Tasks01/cmake-build-debug/CMakeFiles/task08a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task08a.dir/depend

