# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "/Applications/CLion 2.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Applications/CLion 2.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danaklamut/ClionProjects/iondb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo

# Include any dependencies generated for this target.
include src/tests/CMakeFiles/planck_unit.dir/depend.make

# Include the progress variables for this target.
include src/tests/CMakeFiles/planck_unit.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/CMakeFiles/planck_unit.dir/flags.make

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o: src/tests/CMakeFiles/planck_unit.dir/flags.make
src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o: ../src/tests/planckunit/src/planck_unit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/planckunit/src/planck_unit.c

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/planckunit/src/planck_unit.c > CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.i

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/planckunit/src/planck_unit.c -o CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.s

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.requires:

.PHONY : src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.requires

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.provides: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.requires
	$(MAKE) -f src/tests/CMakeFiles/planck_unit.dir/build.make src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.provides.build
.PHONY : src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.provides

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.provides.build: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o


src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o: src/tests/CMakeFiles/planck_unit.dir/flags.make
src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o: ../src/tests/planckunit/src/ion_time/ion_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/planckunit/src/ion_time/ion_time.c

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/planckunit/src/ion_time/ion_time.c > CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.i

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/planckunit/src/ion_time/ion_time.c -o CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.s

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.requires:

.PHONY : src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.requires

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.provides: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.requires
	$(MAKE) -f src/tests/CMakeFiles/planck_unit.dir/build.make src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.provides.build
.PHONY : src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.provides

src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.provides.build: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o


# Object files for target planck_unit
planck_unit_OBJECTS = \
"CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o" \
"CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o"

# External object files for target planck_unit
planck_unit_EXTERNAL_OBJECTS =

src/tests/libplanck_unit.a: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o
src/tests/libplanck_unit.a: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o
src/tests/libplanck_unit.a: src/tests/CMakeFiles/planck_unit.dir/build.make
src/tests/libplanck_unit.a: src/tests/CMakeFiles/planck_unit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libplanck_unit.a"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/planck_unit.dir/cmake_clean_target.cmake
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/planck_unit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/CMakeFiles/planck_unit.dir/build: src/tests/libplanck_unit.a

.PHONY : src/tests/CMakeFiles/planck_unit.dir/build

src/tests/CMakeFiles/planck_unit.dir/requires: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/planck_unit.c.o.requires
src/tests/CMakeFiles/planck_unit.dir/requires: src/tests/CMakeFiles/planck_unit.dir/planckunit/src/ion_time/ion_time.c.o.requires

.PHONY : src/tests/CMakeFiles/planck_unit.dir/requires

src/tests/CMakeFiles/planck_unit.dir/clean:
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/planck_unit.dir/cmake_clean.cmake
.PHONY : src/tests/CMakeFiles/planck_unit.dir/clean

src/tests/CMakeFiles/planck_unit.dir/depend:
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danaklamut/ClionProjects/iondb /Users/danaklamut/ClionProjects/iondb/src/tests /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests /Users/danaklamut/ClionProjects/iondb/cmake-build-relwithdebinfo/src/tests/CMakeFiles/planck_unit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/CMakeFiles/planck_unit.dir/depend

