# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/david/Desktop/pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Desktop/pong/Debug

# Include any dependencies generated for this target.
include CMakeFiles/pong.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pong.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pong.dir/flags.make

CMakeFiles/pong.dir/bin/pong.cpp.o: CMakeFiles/pong.dir/flags.make
CMakeFiles/pong.dir/bin/pong.cpp.o: ../bin/pong.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pong.dir/bin/pong.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pong.dir/bin/pong.cpp.o -c /home/david/Desktop/pong/bin/pong.cpp

CMakeFiles/pong.dir/bin/pong.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong.dir/bin/pong.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/pong/bin/pong.cpp > CMakeFiles/pong.dir/bin/pong.cpp.i

CMakeFiles/pong.dir/bin/pong.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong.dir/bin/pong.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/pong/bin/pong.cpp -o CMakeFiles/pong.dir/bin/pong.cpp.s

# Object files for target pong
pong_OBJECTS = \
"CMakeFiles/pong.dir/bin/pong.cpp.o"

# External object files for target pong
pong_EXTERNAL_OBJECTS =

pong: CMakeFiles/pong.dir/bin/pong.cpp.o
pong: CMakeFiles/pong.dir/build.make
pong: /usr/lib/libsfml-graphics.so
pong: /usr/lib/libsfml-window.so
pong: /usr/lib/libsfml-system.so
pong: /usr/lib/libsfml-audio.so
pong: /usr/lib/libsfml-network.so
pong: libpong_core.a
pong: /usr/lib/libsfml-graphics.so
pong: /usr/lib/libsfml-window.so
pong: /usr/lib/libsfml-system.so
pong: /usr/lib/libsfml-audio.so
pong: /usr/lib/libsfml-network.so
pong: CMakeFiles/pong.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Desktop/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pong"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pong.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pong.dir/build: pong

.PHONY : CMakeFiles/pong.dir/build

CMakeFiles/pong.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pong.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pong.dir/clean

CMakeFiles/pong.dir/depend:
	cd /home/david/Desktop/pong/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Desktop/pong /home/david/Desktop/pong /home/david/Desktop/pong/Debug /home/david/Desktop/pong/Debug /home/david/Desktop/pong/Debug/CMakeFiles/pong.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pong.dir/depend

