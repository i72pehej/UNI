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
include CMakeFiles/cliente.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cliente.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cliente.dir/flags.make

CMakeFiles/cliente.dir/clienteDomino.c.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/clienteDomino.c.o: clienteDomino.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cliente.dir/clienteDomino.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cliente.dir/clienteDomino.c.o   -c /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/clienteDomino.c

CMakeFiles/cliente.dir/clienteDomino.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cliente.dir/clienteDomino.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/clienteDomino.c > CMakeFiles/cliente.dir/clienteDomino.c.i

CMakeFiles/cliente.dir/clienteDomino.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cliente.dir/clienteDomino.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/clienteDomino.c -o CMakeFiles/cliente.dir/clienteDomino.c.s

CMakeFiles/cliente.dir/clienteDomino.c.o.requires:

.PHONY : CMakeFiles/cliente.dir/clienteDomino.c.o.requires

CMakeFiles/cliente.dir/clienteDomino.c.o.provides: CMakeFiles/cliente.dir/clienteDomino.c.o.requires
	$(MAKE) -f CMakeFiles/cliente.dir/build.make CMakeFiles/cliente.dir/clienteDomino.c.o.provides.build
.PHONY : CMakeFiles/cliente.dir/clienteDomino.c.o.provides

CMakeFiles/cliente.dir/clienteDomino.c.o.provides.build: CMakeFiles/cliente.dir/clienteDomino.c.o


# Object files for target cliente
cliente_OBJECTS = \
"CMakeFiles/cliente.dir/clienteDomino.c.o"

# External object files for target cliente
cliente_EXTERNAL_OBJECTS =

cliente: CMakeFiles/cliente.dir/clienteDomino.c.o
cliente: CMakeFiles/cliente.dir/build.make
cliente: CMakeFiles/cliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cliente"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cliente.dir/build: cliente

.PHONY : CMakeFiles/cliente.dir/build

CMakeFiles/cliente.dir/requires: CMakeFiles/cliente.dir/clienteDomino.c.o.requires

.PHONY : CMakeFiles/cliente.dir/requires

CMakeFiles/cliente.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cliente.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cliente.dir/clean

CMakeFiles/cliente.dir/depend:
	cd /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu /home/julen/i72pehej/Uni_3/Redes/p2/DominoManu/CMakeFiles/cliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cliente.dir/depend

