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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/thermal-printer-controller/VersionA1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/thermal-printer-controller/VersionA1.0/build

# Include any dependencies generated for this target.
include CMakeFiles/FeedAndHalfCut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FeedAndHalfCut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FeedAndHalfCut.dir/flags.make

CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.o: CMakeFiles/FeedAndHalfCut.dir/flags.make
CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.o: ../src/main_FeedAndHalfCut.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/thermal-printer-controller/VersionA1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.o"
	x86_64-linux-gnu-gcc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.o -c /home/ubuntu/thermal-printer-controller/VersionA1.0/src/main_FeedAndHalfCut.cpp

CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.i"
	x86_64-linux-gnu-gcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/thermal-printer-controller/VersionA1.0/src/main_FeedAndHalfCut.cpp > CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.i

CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.s"
	x86_64-linux-gnu-gcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/thermal-printer-controller/VersionA1.0/src/main_FeedAndHalfCut.cpp -o CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.s

CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.o: CMakeFiles/FeedAndHalfCut.dir/flags.make
CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.o: ../src/printerutilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/thermal-printer-controller/VersionA1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.o"
	x86_64-linux-gnu-gcc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.o -c /home/ubuntu/thermal-printer-controller/VersionA1.0/src/printerutilities.cpp

CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.i"
	x86_64-linux-gnu-gcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/thermal-printer-controller/VersionA1.0/src/printerutilities.cpp > CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.i

CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.s"
	x86_64-linux-gnu-gcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/thermal-printer-controller/VersionA1.0/src/printerutilities.cpp -o CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.s

# Object files for target FeedAndHalfCut
FeedAndHalfCut_OBJECTS = \
"CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.o" \
"CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.o"

# External object files for target FeedAndHalfCut
FeedAndHalfCut_EXTERNAL_OBJECTS =

cpp_bin/FeedAndHalfCut: CMakeFiles/FeedAndHalfCut.dir/src/main_FeedAndHalfCut.cpp.o
cpp_bin/FeedAndHalfCut: CMakeFiles/FeedAndHalfCut.dir/src/printerutilities.cpp.o
cpp_bin/FeedAndHalfCut: CMakeFiles/FeedAndHalfCut.dir/build.make
cpp_bin/FeedAndHalfCut: ../lib/libautoreplyprint.a
cpp_bin/FeedAndHalfCut: CMakeFiles/FeedAndHalfCut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/thermal-printer-controller/VersionA1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpp_bin/FeedAndHalfCut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FeedAndHalfCut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FeedAndHalfCut.dir/build: cpp_bin/FeedAndHalfCut

.PHONY : CMakeFiles/FeedAndHalfCut.dir/build

CMakeFiles/FeedAndHalfCut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FeedAndHalfCut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FeedAndHalfCut.dir/clean

CMakeFiles/FeedAndHalfCut.dir/depend:
	cd /home/ubuntu/thermal-printer-controller/VersionA1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/thermal-printer-controller/VersionA1.0 /home/ubuntu/thermal-printer-controller/VersionA1.0 /home/ubuntu/thermal-printer-controller/VersionA1.0/build /home/ubuntu/thermal-printer-controller/VersionA1.0/build /home/ubuntu/thermal-printer-controller/VersionA1.0/build/CMakeFiles/FeedAndHalfCut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FeedAndHalfCut.dir/depend

