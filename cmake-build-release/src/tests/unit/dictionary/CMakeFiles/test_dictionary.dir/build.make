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
include src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/depend.make

# Include the progress variables for this target.
include src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/flags.make

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/flags.make
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o: ../src/dictionary/ion_master_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/dictionary/ion_master_table.c

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/dictionary/ion_master_table.c > CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.i

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/dictionary/ion_master_table.c -o CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.s

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.requires:

.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.requires

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.provides: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.requires
	$(MAKE) -f src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build.make src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.provides.build
.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.provides

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.provides.build: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o


src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/flags.make
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o: ../src/tests/unit/dictionary/test_dictionary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_dictionary.dir/test_dictionary.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/test_dictionary.c

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_dictionary.dir/test_dictionary.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/test_dictionary.c > CMakeFiles/test_dictionary.dir/test_dictionary.c.i

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_dictionary.dir/test_dictionary.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/test_dictionary.c -o CMakeFiles/test_dictionary.dir/test_dictionary.c.s

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.requires:

.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.requires

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.provides: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.requires
	$(MAKE) -f src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build.make src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.provides.build
.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.provides

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.provides.build: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o


src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/flags.make
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o: ../src/tests/unit/dictionary/generic_dictionary_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/generic_dictionary_test.c

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/generic_dictionary_test.c > CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.i

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/generic_dictionary_test.c -o CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.s

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.requires:

.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.requires

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.provides: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.requires
	$(MAKE) -f src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build.make src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.provides.build
.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.provides

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.provides.build: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o


src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/flags.make
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o: ../src/tests/unit/dictionary/run_dictionary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_dictionary.dir/run_dictionary.c.o   -c /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/run_dictionary.c

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_dictionary.dir/run_dictionary.c.i"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/run_dictionary.c > CMakeFiles/test_dictionary.dir/run_dictionary.c.i

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_dictionary.dir/run_dictionary.c.s"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && /Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary/run_dictionary.c -o CMakeFiles/test_dictionary.dir/run_dictionary.c.s

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.requires:

.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.requires

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.provides: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.requires
	$(MAKE) -f src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build.make src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.provides.build
.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.provides

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.provides.build: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o


# Object files for target test_dictionary
test_dictionary_OBJECTS = \
"CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o" \
"CMakeFiles/test_dictionary.dir/test_dictionary.c.o" \
"CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o" \
"CMakeFiles/test_dictionary.dir/run_dictionary.c.o"

# External object files for target test_dictionary
test_dictionary_EXTERNAL_OBJECTS =

bin/test_dictionary: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o
bin/test_dictionary: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o
bin/test_dictionary: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o
bin/test_dictionary: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o
bin/test_dictionary: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build.make
bin/test_dictionary: src/tests/libplanck_unit.a
bin/test_dictionary: src/dictionary/skip_list/libskip_list.a
bin/test_dictionary: src/dictionary/flat_file/libflat_file.a
bin/test_dictionary: src/dictionary/bpp_tree/libbpp_tree.a
bin/test_dictionary: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danaklamut/ClionProjects/iondb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ../../../../bin/test_dictionary"
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_dictionary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build: bin/test_dictionary

.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/build

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/requires: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/__/__/__/dictionary/ion_master_table.c.o.requires
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/requires: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/test_dictionary.c.o.requires
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/requires: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/generic_dictionary_test.c.o.requires
src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/requires: src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/run_dictionary.c.o.requires

.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/requires

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/clean:
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary && $(CMAKE_COMMAND) -P CMakeFiles/test_dictionary.dir/cmake_clean.cmake
.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/clean

src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/depend:
	cd /Users/danaklamut/ClionProjects/iondb/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danaklamut/ClionProjects/iondb /Users/danaklamut/ClionProjects/iondb/src/tests/unit/dictionary /Users/danaklamut/ClionProjects/iondb/cmake-build-release /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary /Users/danaklamut/ClionProjects/iondb/cmake-build-release/src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/unit/dictionary/CMakeFiles/test_dictionary.dir/depend

