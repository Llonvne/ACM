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
CMAKE_COMMAND = "/Users/llonvne/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/llonvne/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/llonvne/CLionProjects/Uva - 101"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Uva___101.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Uva___101.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Uva___101.dir/flags.make

CMakeFiles/Uva___101.dir/main.cpp.o: CMakeFiles/Uva___101.dir/flags.make
CMakeFiles/Uva___101.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Uva___101.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Uva___101.dir/main.cpp.o -c "/Users/llonvne/CLionProjects/Uva - 101/main.cpp"

CMakeFiles/Uva___101.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Uva___101.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/llonvne/CLionProjects/Uva - 101/main.cpp" > CMakeFiles/Uva___101.dir/main.cpp.i

CMakeFiles/Uva___101.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Uva___101.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/llonvne/CLionProjects/Uva - 101/main.cpp" -o CMakeFiles/Uva___101.dir/main.cpp.s

# Object files for target Uva___101
Uva___101_OBJECTS = \
"CMakeFiles/Uva___101.dir/main.cpp.o"

# External object files for target Uva___101
Uva___101_EXTERNAL_OBJECTS =

Uva___101: CMakeFiles/Uva___101.dir/main.cpp.o
Uva___101: CMakeFiles/Uva___101.dir/build.make
Uva___101: CMakeFiles/Uva___101.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Uva___101"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Uva___101.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Uva___101.dir/build: Uva___101
.PHONY : CMakeFiles/Uva___101.dir/build

CMakeFiles/Uva___101.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Uva___101.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Uva___101.dir/clean

CMakeFiles/Uva___101.dir/depend:
	cd "/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/llonvne/CLionProjects/Uva - 101" "/Users/llonvne/CLionProjects/Uva - 101" "/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug" "/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug" "/Users/llonvne/CLionProjects/Uva - 101/cmake-build-debug/CMakeFiles/Uva___101.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Uva___101.dir/depend

