# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AgressiveCows.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/AgressiveCows.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AgressiveCows.dir/flags.make

CMakeFiles/AgressiveCows.dir/main.cpp.o: CMakeFiles/AgressiveCows.dir/flags.make
CMakeFiles/AgressiveCows.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AgressiveCows.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AgressiveCows.dir/main.cpp.o -c /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/main.cpp

CMakeFiles/AgressiveCows.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AgressiveCows.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/main.cpp > CMakeFiles/AgressiveCows.dir/main.cpp.i

CMakeFiles/AgressiveCows.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AgressiveCows.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/main.cpp -o CMakeFiles/AgressiveCows.dir/main.cpp.s

# Object files for target AgressiveCows
AgressiveCows_OBJECTS = \
"CMakeFiles/AgressiveCows.dir/main.cpp.o"

# External object files for target AgressiveCows
AgressiveCows_EXTERNAL_OBJECTS =

AgressiveCows: CMakeFiles/AgressiveCows.dir/main.cpp.o
AgressiveCows: CMakeFiles/AgressiveCows.dir/build.make
AgressiveCows: CMakeFiles/AgressiveCows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AgressiveCows"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AgressiveCows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AgressiveCows.dir/build: AgressiveCows
.PHONY : CMakeFiles/AgressiveCows.dir/build

CMakeFiles/AgressiveCows.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AgressiveCows.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AgressiveCows.dir/clean

CMakeFiles/AgressiveCows.dir/depend:
	cd /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug /Users/llonvne/Desktop/College_Study_File/Clion/AgressiveCows/cmake-build-debug/CMakeFiles/AgressiveCows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AgressiveCows.dir/depend

