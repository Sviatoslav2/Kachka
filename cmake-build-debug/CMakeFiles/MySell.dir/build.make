# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Admin/CLionProjects/MySell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MySell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MySell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MySell.dir/flags.make

CMakeFiles/MySell.dir/main.cpp.o: CMakeFiles/MySell.dir/flags.make
CMakeFiles/MySell.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MySell.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySell.dir/main.cpp.o -c /mnt/c/Users/Admin/CLionProjects/MySell/main.cpp

CMakeFiles/MySell.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySell.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Admin/CLionProjects/MySell/main.cpp > CMakeFiles/MySell.dir/main.cpp.i

CMakeFiles/MySell.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySell.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Admin/CLionProjects/MySell/main.cpp -o CMakeFiles/MySell.dir/main.cpp.s

CMakeFiles/MySell.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MySell.dir/main.cpp.o.requires

CMakeFiles/MySell.dir/main.cpp.o.provides: CMakeFiles/MySell.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MySell.dir/build.make CMakeFiles/MySell.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MySell.dir/main.cpp.o.provides

CMakeFiles/MySell.dir/main.cpp.o.provides.build: CMakeFiles/MySell.dir/main.cpp.o


# Object files for target MySell
MySell_OBJECTS = \
"CMakeFiles/MySell.dir/main.cpp.o"

# External object files for target MySell
MySell_EXTERNAL_OBJECTS =

MySell: CMakeFiles/MySell.dir/main.cpp.o
MySell: CMakeFiles/MySell.dir/build.make
MySell: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
MySell: /usr/lib/x86_64-linux-gnu/libboost_system.so
MySell: CMakeFiles/MySell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MySell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MySell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MySell.dir/build: MySell

.PHONY : CMakeFiles/MySell.dir/build

CMakeFiles/MySell.dir/requires: CMakeFiles/MySell.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MySell.dir/requires

CMakeFiles/MySell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MySell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MySell.dir/clean

CMakeFiles/MySell.dir/depend:
	cd /mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Admin/CLionProjects/MySell /mnt/c/Users/Admin/CLionProjects/MySell /mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug /mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug /mnt/c/Users/Admin/CLionProjects/MySell/cmake-build-debug/CMakeFiles/MySell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MySell.dir/depend

