# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build"

# Include any dependencies generated for this target.
include CMakeFiles/city.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/city.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/city.dir/flags.make

CMakeFiles/city.dir/lib/city.cpp.o: CMakeFiles/city.dir/flags.make
CMakeFiles/city.dir/lib/city.cpp.o: ../lib/city.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/city.dir/lib/city.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/city.dir/lib/city.cpp.o -c "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/lib/city.cpp"

CMakeFiles/city.dir/lib/city.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/city.dir/lib/city.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/lib/city.cpp" > CMakeFiles/city.dir/lib/city.cpp.i

CMakeFiles/city.dir/lib/city.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/city.dir/lib/city.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/lib/city.cpp" -o CMakeFiles/city.dir/lib/city.cpp.s

# Object files for target city
city_OBJECTS = \
"CMakeFiles/city.dir/lib/city.cpp.o"

# External object files for target city
city_EXTERNAL_OBJECTS =

libcity.so: CMakeFiles/city.dir/lib/city.cpp.o
libcity.so: CMakeFiles/city.dir/build.make
libcity.so: CMakeFiles/city.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libcity.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/city.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/city.dir/build: libcity.so

.PHONY : CMakeFiles/city.dir/build

CMakeFiles/city.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/city.dir/cmake_clean.cmake
.PHONY : CMakeFiles/city.dir/clean

CMakeFiles/city.dir/depend:
	cd "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1" "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1" "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build" "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build" "/home/simon/Documents/Numerical Simulation and Scientific Computing/ex1/build/CMakeFiles/city.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/city.dir/depend

