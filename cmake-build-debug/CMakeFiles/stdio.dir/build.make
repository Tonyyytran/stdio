# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /cygdrive/c/Users/John/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/John/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/John/Desktop/CLionProjects/stdio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stdio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stdio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stdio.dir/flags.make

CMakeFiles/stdio.dir/main.cpp.o: CMakeFiles/stdio.dir/flags.make
CMakeFiles/stdio.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stdio.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stdio.dir/main.cpp.o -c /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/main.cpp

CMakeFiles/stdio.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stdio.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/main.cpp > CMakeFiles/stdio.dir/main.cpp.i

CMakeFiles/stdio.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stdio.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/main.cpp -o CMakeFiles/stdio.dir/main.cpp.s

CMakeFiles/stdio.dir/stdio.cpp.o: CMakeFiles/stdio.dir/flags.make
CMakeFiles/stdio.dir/stdio.cpp.o: ../stdio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stdio.dir/stdio.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stdio.dir/stdio.cpp.o -c /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/stdio.cpp

CMakeFiles/stdio.dir/stdio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stdio.dir/stdio.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/stdio.cpp > CMakeFiles/stdio.dir/stdio.cpp.i

CMakeFiles/stdio.dir/stdio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stdio.dir/stdio.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/stdio.cpp -o CMakeFiles/stdio.dir/stdio.cpp.s

# Object files for target stdio
stdio_OBJECTS = \
"CMakeFiles/stdio.dir/main.cpp.o" \
"CMakeFiles/stdio.dir/stdio.cpp.o"

# External object files for target stdio
stdio_EXTERNAL_OBJECTS =

stdio.exe: CMakeFiles/stdio.dir/main.cpp.o
stdio.exe: CMakeFiles/stdio.dir/stdio.cpp.o
stdio.exe: CMakeFiles/stdio.dir/build.make
stdio.exe: CMakeFiles/stdio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stdio.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stdio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stdio.dir/build: stdio.exe

.PHONY : CMakeFiles/stdio.dir/build

CMakeFiles/stdio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stdio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stdio.dir/clean

CMakeFiles/stdio.dir/depend:
	cd /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/John/Desktop/CLionProjects/stdio /cygdrive/c/Users/John/Desktop/CLionProjects/stdio /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug /cygdrive/c/Users/John/Desktop/CLionProjects/stdio/cmake-build-debug/CMakeFiles/stdio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stdio.dir/depend
