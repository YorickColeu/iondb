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
CMAKE_BINARY_DIR = /Users/danaklamut/ClionProjects/iondb/cmake-build-release

# Include any dependencies generated for this target.
include src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/depend.make

# Include the progress variables for this target.
include src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/flags.make

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/flags.make
src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o: ../src/tests/behaviour/dictionary/bpp_tree/test_behaviour_bpp_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree/test_behaviour_bpp_tree.c

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree/test_behaviour_bpp_tree.c > CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.i

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree/test_behaviour_bpp_tree.c -o CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.s

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.requires:

.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.requires

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.provides: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.requires
	$(MAKE) -f src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/build.make src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.provides.build
.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.provides

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.provides.build: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o


src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/flags.make
src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o: ../src/tests/behaviour/dictionary/bpp_tree/run_behaviour_bpp_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree/run_behaviour_bpp_tree.c

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree/run_behaviour_bpp_tree.c > CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.i

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree/run_behaviour_bpp_tree.c -o CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.s

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.requires:

.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.requires

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.provides: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.requires
	$(MAKE) -f src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/build.make src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.provides.build
.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.provides

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.provides.build: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o


# Object files for target test_behaviour_bpp_tree
test_behaviour_bpp_tree_OBJECTS = \
"CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o" \
"CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o"

# External object files for target test_behaviour_bpp_tree
test_behaviour_bpp_tree_EXTERNAL_OBJECTS =

bin/test_behaviour_bpp_tree: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o
bin/test_behaviour_bpp_tree: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o
bin/test_behaviour_bpp_tree: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/build.make
bin/test_behaviour_bpp_tree: src/tests/behaviour/dictionary/libbehaviour_dictionary.a
bin/test_behaviour_bpp_tree: src/tests/libplanck_unit.a
bin/test_behaviour_bpp_tree: src/dictionary/skip_list/libskip_list.a
bin/test_behaviour_bpp_tree: src/dictionary/flat_file/libflat_file.a
bin/test_behaviour_bpp_tree: src/dictionary/open_address_hash/libopen_address_hash.a
bin/test_behaviour_bpp_tree: src/dictionary/open_address_file_hash/libopen_address_file_hash.a
bin/test_behaviour_bpp_tree: src/dictionary/bpp_tree/libbpp_tree.a
bin/test_behaviour_bpp_tree: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../../../../../bin/test_behaviour_bpp_tree"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_behaviour_bpp_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/build: bin/test_behaviour_bpp_tree

.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/build

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/requires: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/test_behaviour_bpp_tree.c.o.requires
src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/requires: src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/run_behaviour_bpp_tree.c.o.requires

.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/requires

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/clean:
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree && $(CMAKE_COMMAND) -P CMakeFiles/test_behaviour_bpp_tree.dir/cmake_clean.cmake
.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/clean

src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/depend:
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danaklamut/ClionProjects/iondb /Users/danaklamut/ClionProjects/iondb/src/tests/behaviour/dictionary/bpp_tree /Users/danaklamut/ClionProjects/iondb/cmake-build-release /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/behaviour/dictionary/bpp_tree/CMakeFiles/test_behaviour_bpp_tree.dir/depend

