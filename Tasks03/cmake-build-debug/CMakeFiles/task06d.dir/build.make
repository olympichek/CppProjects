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
include CMakeFiles/task06d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task06d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task06d.dir/flags.make

CMakeFiles/task06d.dir/task06d.cpp.o: CMakeFiles/task06d.dir/flags.make
CMakeFiles/task06d.dir/task06d.cpp.o: ../task06d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olympichek/CppProjects/Tasks03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task06d.dir/task06d.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task06d.dir/task06d.cpp.o -c /home/olympichek/CppProjects/Tasks03/task06d.cpp

CMakeFiles/task06d.dir/task06d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task06d.dir/task06d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olympichek/CppProjects/Tasks03/task06d.cpp > CMakeFiles/task06d.dir/task06d.cpp.i

CMakeFiles/task06d.dir/task06d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task06d.dir/task06d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olympichek/CppProjects/Tasks03/task06d.cpp -o CMakeFiles/task06d.dir/task06d.cpp.s

# Object files for target task06d
task06d_OBJECTS = \
"CMakeFiles/task06d.dir/task06d.cpp.o"

# External object files for target task06d
task06d_EXTERNAL_OBJECTS =

task06d: CMakeFiles/task06d.dir/task06d.cpp.o
task06d: CMakeFiles/task06d.dir/build.make
task06d: CMakeFiles/task06d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olympichek/CppProjects/Tasks03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task06d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task06d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task06d.dir/build: task06d

.PHONY : CMakeFiles/task06d.dir/build

CMakeFiles/task06d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task06d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task06d.dir/clean

CMakeFiles/task06d.dir/depend:
	cd /home/olympichek/CppProjects/Tasks03/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olympichek/CppProjects/Tasks03 /home/olympichek/CppProjects/Tasks03 /home/olympichek/CppProjects/Tasks03/cmake-build-debug /home/olympichek/CppProjects/Tasks03/cmake-build-debug /home/olympichek/CppProjects/Tasks03/cmake-build-debug/CMakeFiles/task06d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task06d.dir/depend
