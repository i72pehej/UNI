# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/julen/i72pehej/Uni_3/Algoritmica/Practica3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julen/i72pehej/Uni_3/Algoritmica/Practica3

# Include any dependencies generated for this target.
include CMakeFiles/p3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p3.dir/flags.make

CMakeFiles/p3.dir/p3.cpp.o: CMakeFiles/p3.dir/flags.make
CMakeFiles/p3.dir/p3.cpp.o: p3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julen/i72pehej/Uni_3/Algoritmica/Practica3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p3.dir/p3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p3.dir/p3.cpp.o -c /home/julen/i72pehej/Uni_3/Algoritmica/Practica3/p3.cpp

CMakeFiles/p3.dir/p3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p3.dir/p3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julen/i72pehej/Uni_3/Algoritmica/Practica3/p3.cpp > CMakeFiles/p3.dir/p3.cpp.i

CMakeFiles/p3.dir/p3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p3.dir/p3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julen/i72pehej/Uni_3/Algoritmica/Practica3/p3.cpp -o CMakeFiles/p3.dir/p3.cpp.s

CMakeFiles/p3.dir/p3.cpp.o.requires:

.PHONY : CMakeFiles/p3.dir/p3.cpp.o.requires

CMakeFiles/p3.dir/p3.cpp.o.provides: CMakeFiles/p3.dir/p3.cpp.o.requires
	$(MAKE) -f CMakeFiles/p3.dir/build.make CMakeFiles/p3.dir/p3.cpp.o.provides.build
.PHONY : CMakeFiles/p3.dir/p3.cpp.o.provides

CMakeFiles/p3.dir/p3.cpp.o.provides.build: CMakeFiles/p3.dir/p3.cpp.o


# Object files for target p3
p3_OBJECTS = \
"CMakeFiles/p3.dir/p3.cpp.o"

# External object files for target p3
p3_EXTERNAL_OBJECTS =

p3: CMakeFiles/p3.dir/p3.cpp.o
p3: CMakeFiles/p3.dir/build.make
p3: CMakeFiles/p3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julen/i72pehej/Uni_3/Algoritmica/Practica3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p3.dir/build: p3

.PHONY : CMakeFiles/p3.dir/build

CMakeFiles/p3.dir/requires: CMakeFiles/p3.dir/p3.cpp.o.requires

.PHONY : CMakeFiles/p3.dir/requires

CMakeFiles/p3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p3.dir/clean

CMakeFiles/p3.dir/depend:
	cd /home/julen/i72pehej/Uni_3/Algoritmica/Practica3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julen/i72pehej/Uni_3/Algoritmica/Practica3 /home/julen/i72pehej/Uni_3/Algoritmica/Practica3 /home/julen/i72pehej/Uni_3/Algoritmica/Practica3 /home/julen/i72pehej/Uni_3/Algoritmica/Practica3 /home/julen/i72pehej/Uni_3/Algoritmica/Practica3/CMakeFiles/p3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p3.dir/depend

