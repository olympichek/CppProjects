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
include CMakeFiles/task02b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task02b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task02b.dir/flags.make

CMakeFiles/task02b.dir/task02b.cpp.o: CMakeFiles/task02b.dir/flags.make
CMakeFiles/task02b.dir/task02b.cpp.o: ../task02b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olympichek/CppProjects/Tasks01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task02b.dir/task02b.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task02b.dir/task02b.cpp.o -c /home/olympichek/CppProjects/Tasks01/task02b.cpp

CMakeFiles/task02b.dir/task02b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task02b.dir/task02b.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olympichek/CppProjects/Tasks01/task02b.cpp > CMakeFiles/task02b.dir/task02b.cpp.i

CMakeFiles/task02b.dir/task02b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task02b.dir/task02b.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olympichek/CppProjects/Tasks01/task02b.cpp -o CMakeFiles/task02b.dir/task02b.cpp.s

# Object files for target task02b
task02b_OBJECTS = \
"CMakeFiles/task02b.dir/task02b.cpp.o"

# External object files for target task02b
task02b_EXTERNAL_OBJECTS =

task02b: CMakeFiles/task02b.dir/task02b.cpp.o
task02b: CMakeFiles/task02b.dir/build.make
task02b: CMakeFiles/task02b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olympichek/CppProjects/Tasks01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task02b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task02b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task02b.dir/build: task02b

.PHONY : CMakeFiles/task02b.dir/build

CMakeFiles/task02b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task02b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task02b.dir/clean

CMakeFiles/task02b.dir/depend:
	cd /home/olympichek/CppProjects/Tasks01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olympichek/CppProjects/Tasks01 /home/olympichek/CppProjects/Tasks01 /home/olympichek/CppProjects/Tasks01/cmake-build-debug /home/olympichek/CppProjects/Tasks01/cmake-build-debug /home/olympichek/CppProjects/Tasks01/cmake-build-debug/CMakeFiles/task02b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task02b.dir/depend

