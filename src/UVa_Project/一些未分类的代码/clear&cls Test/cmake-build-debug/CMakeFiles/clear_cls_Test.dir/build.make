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
CMAKE_SOURCE_DIR = "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/clear_cls_Test.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/clear_cls_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clear_cls_Test.dir/flags.make

CMakeFiles/clear_cls_Test.dir/main.cpp.o: CMakeFiles/clear_cls_Test.dir/flags.make
CMakeFiles/clear_cls_Test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clear_cls_Test.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clear_cls_Test.dir/main.cpp.o -c "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/main.cpp"

CMakeFiles/clear_cls_Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clear_cls_Test.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/main.cpp" > CMakeFiles/clear_cls_Test.dir/main.cpp.i

CMakeFiles/clear_cls_Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clear_cls_Test.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/main.cpp" -o CMakeFiles/clear_cls_Test.dir/main.cpp.s

# Object files for target clear_cls_Test
clear_cls_Test_OBJECTS = \
"CMakeFiles/clear_cls_Test.dir/main.cpp.o"

# External object files for target clear_cls_Test
clear_cls_Test_EXTERNAL_OBJECTS =

clear_cls_Test: CMakeFiles/clear_cls_Test.dir/main.cpp.o
clear_cls_Test: CMakeFiles/clear_cls_Test.dir/build.make
clear_cls_Test: CMakeFiles/clear_cls_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clear_cls_Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clear_cls_Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clear_cls_Test.dir/build: clear_cls_Test
.PHONY : CMakeFiles/clear_cls_Test.dir/build

CMakeFiles/clear_cls_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clear_cls_Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clear_cls_Test.dir/clean

CMakeFiles/clear_cls_Test.dir/depend:
	cd "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test" "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test" "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug" "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug" "/Users/llonvne/Desktop/College_Study_File/Clion/clear&cls Test/cmake-build-debug/CMakeFiles/clear_cls_Test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/clear_cls_Test.dir/depend

