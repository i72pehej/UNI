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
CMAKE_SOURCE_DIR = /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu

# Include any dependencies generated for this target.
include CMakeFiles/servidor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/servidor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/servidor.dir/flags.make

CMakeFiles/servidor.dir/servidorManu.c.o: CMakeFiles/servidor.dir/flags.make
CMakeFiles/servidor.dir/servidorManu.c.o: servidorManu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/servidor.dir/servidorManu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/servidor.dir/servidorManu.c.o   -c /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/servidorManu.c

CMakeFiles/servidor.dir/servidorManu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/servidor.dir/servidorManu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/servidorManu.c > CMakeFiles/servidor.dir/servidorManu.c.i

CMakeFiles/servidor.dir/servidorManu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/servidor.dir/servidorManu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/servidorManu.c -o CMakeFiles/servidor.dir/servidorManu.c.s

CMakeFiles/servidor.dir/servidorManu.c.o.requires:

.PHONY : CMakeFiles/servidor.dir/servidorManu.c.o.requires

CMakeFiles/servidor.dir/servidorManu.c.o.provides: CMakeFiles/servidor.dir/servidorManu.c.o.requires
	$(MAKE) -f CMakeFiles/servidor.dir/build.make CMakeFiles/servidor.dir/servidorManu.c.o.provides.build
.PHONY : CMakeFiles/servidor.dir/servidorManu.c.o.provides

CMakeFiles/servidor.dir/servidorManu.c.o.provides.build: CMakeFiles/servidor.dir/servidorManu.c.o


# Object files for target servidor
servidor_OBJECTS = \
"CMakeFiles/servidor.dir/servidorManu.c.o"

# External object files for target servidor
servidor_EXTERNAL_OBJECTS =

servidor: CMakeFiles/servidor.dir/servidorManu.c.o
servidor: CMakeFiles/servidor.dir/build.make
servidor: CMakeFiles/servidor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable servidor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servidor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/servidor.dir/build: servidor

.PHONY : CMakeFiles/servidor.dir/build

CMakeFiles/servidor.dir/requires: CMakeFiles/servidor.dir/servidorManu.c.o.requires

.PHONY : CMakeFiles/servidor.dir/requires

CMakeFiles/servidor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/servidor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/servidor.dir/clean

CMakeFiles/servidor.dir/depend:
	cd /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/CMakeFiles/servidor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/servidor.dir/depend

