# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/sidoku/SDL2_projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sidoku/SDL2_projects/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL2_Tutorial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL2_Tutorial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2_Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2_Tutorial.dir/flags.make

CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o: CMakeFiles/SDL2_Tutorial.dir/flags.make
CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o: /home/sidoku/SDL2_projects/SDL2_tutorial.cpp
CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o: CMakeFiles/SDL2_Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sidoku/SDL2_projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o -MF CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o.d -o CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o -c /home/sidoku/SDL2_projects/SDL2_tutorial.cpp

CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sidoku/SDL2_projects/SDL2_tutorial.cpp > CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.i

CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sidoku/SDL2_projects/SDL2_tutorial.cpp -o CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.s

# Object files for target SDL2_Tutorial
SDL2_Tutorial_OBJECTS = \
"CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o"

# External object files for target SDL2_Tutorial
SDL2_Tutorial_EXTERNAL_OBJECTS =

SDL2_Tutorial: CMakeFiles/SDL2_Tutorial.dir/SDL2_tutorial.cpp.o
SDL2_Tutorial: CMakeFiles/SDL2_Tutorial.dir/build.make
SDL2_Tutorial: CMakeFiles/SDL2_Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sidoku/SDL2_projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SDL2_Tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2_Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL2_Tutorial.dir/build: SDL2_Tutorial
.PHONY : CMakeFiles/SDL2_Tutorial.dir/build

CMakeFiles/SDL2_Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2_Tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL2_Tutorial.dir/clean

CMakeFiles/SDL2_Tutorial.dir/depend:
	cd /home/sidoku/SDL2_projects/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sidoku/SDL2_projects /home/sidoku/SDL2_projects /home/sidoku/SDL2_projects/build /home/sidoku/SDL2_projects/build /home/sidoku/SDL2_projects/build/CMakeFiles/SDL2_Tutorial.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SDL2_Tutorial.dir/depend

