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
CMAKE_SOURCE_DIR = /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build

# Include any dependencies generated for this target.
include test/CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runTests.dir/flags.make

test/CMakeFiles/runTests.dir/moneyTest.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/moneyTest.o: ../test/moneyTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runTests.dir/moneyTest.o"
	cd /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/moneyTest.o -c /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/test/moneyTest.cpp

test/CMakeFiles/runTests.dir/moneyTest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/moneyTest.i"
	cd /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/test/moneyTest.cpp > CMakeFiles/runTests.dir/moneyTest.i

test/CMakeFiles/runTests.dir/moneyTest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/moneyTest.s"
	cd /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/test/moneyTest.cpp -o CMakeFiles/runTests.dir/moneyTest.s

test/CMakeFiles/runTests.dir/moneyTest.o.requires:

.PHONY : test/CMakeFiles/runTests.dir/moneyTest.o.requires

test/CMakeFiles/runTests.dir/moneyTest.o.provides: test/CMakeFiles/runTests.dir/moneyTest.o.requires
	$(MAKE) -f test/CMakeFiles/runTests.dir/build.make test/CMakeFiles/runTests.dir/moneyTest.o.provides.build
.PHONY : test/CMakeFiles/runTests.dir/moneyTest.o.provides

test/CMakeFiles/runTests.dir/moneyTest.o.provides.build: test/CMakeFiles/runTests.dir/moneyTest.o


# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/moneyTest.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

test/runTests: test/CMakeFiles/runTests.dir/moneyTest.o
test/runTests: test/CMakeFiles/runTests.dir/build.make
test/runTests: test/gtest-1.7.0/libgtest.a
test/runTests: test/gtest-1.7.0/libgtest_main.a
test/runTests: test/libTD.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-window.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-system.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-window.so
test/runTests: /usr/lib/x86_64-linux-gnu/libsfml-system.so
test/runTests: test/gtest-1.7.0/libgtest.a
test/runTests: test/CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTests"
	cd /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runTests.dir/build: test/runTests

.PHONY : test/CMakeFiles/runTests.dir/build

test/CMakeFiles/runTests.dir/requires: test/CMakeFiles/runTests.dir/moneyTest.o.requires

.PHONY : test/CMakeFiles/runTests.dir/requires

test/CMakeFiles/runTests.dir/clean:
	cd /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test && $(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runTests.dir/clean

test/CMakeFiles/runTests.dir/depend:
	cd /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3 /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/test /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test /u/23/tainioo2/unix/Documents/Projekti/towerdefence-3/build/test/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runTests.dir/depend
