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
CMAKE_SOURCE_DIR = /home/cciadmin/Infocom2023-RIC-O-Demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cciadmin/Infocom2023-RIC-O-Demo/build

# Include any dependencies generated for this target.
include lib/test/mac/CMakeFiles/pdu_test.dir/depend.make

# Include the progress variables for this target.
include lib/test/mac/CMakeFiles/pdu_test.dir/progress.make

# Include the compile flags for this target's objects.
include lib/test/mac/CMakeFiles/pdu_test.dir/flags.make

lib/test/mac/CMakeFiles/pdu_test.dir/pdu_test.cc.o: lib/test/mac/CMakeFiles/pdu_test.dir/flags.make
lib/test/mac/CMakeFiles/pdu_test.dir/pdu_test.cc.o: ../lib/test/mac/pdu_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cciadmin/Infocom2023-RIC-O-Demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/test/mac/CMakeFiles/pdu_test.dir/pdu_test.cc.o"
	cd /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac && /usr/bin/ccache /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pdu_test.dir/pdu_test.cc.o -c /home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/mac/pdu_test.cc

lib/test/mac/CMakeFiles/pdu_test.dir/pdu_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pdu_test.dir/pdu_test.cc.i"
	cd /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/mac/pdu_test.cc > CMakeFiles/pdu_test.dir/pdu_test.cc.i

lib/test/mac/CMakeFiles/pdu_test.dir/pdu_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pdu_test.dir/pdu_test.cc.s"
	cd /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/mac/pdu_test.cc -o CMakeFiles/pdu_test.dir/pdu_test.cc.s

# Object files for target pdu_test
pdu_test_OBJECTS = \
"CMakeFiles/pdu_test.dir/pdu_test.cc.o"

# External object files for target pdu_test
pdu_test_EXTERNAL_OBJECTS =

lib/test/mac/pdu_test: lib/test/mac/CMakeFiles/pdu_test.dir/pdu_test.cc.o
lib/test/mac/pdu_test: lib/test/mac/CMakeFiles/pdu_test.dir/build.make
lib/test/mac/pdu_test: lib/src/phy/libsrslte_phy.a
lib/test/mac/pdu_test: lib/src/common/libsrslte_common.a
lib/test/mac/pdu_test: lib/src/mac/libsrslte_mac.a
lib/test/mac/pdu_test: lib/src/common/libsrslte_common.a
lib/test/mac/pdu_test: lib/src/phy/libsrslte_phy.a
lib/test/mac/pdu_test: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/test/mac/pdu_test: lib/src/srslog/libsrslog.a
lib/test/mac/pdu_test: lib/src/srslog/bundled/fmt/libfmt.a
lib/test/mac/pdu_test: /usr/lib/x86_64-linux-gnu/libmbedcrypto.so
lib/test/mac/pdu_test: lib/test/mac/CMakeFiles/pdu_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cciadmin/Infocom2023-RIC-O-Demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pdu_test"
	cd /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pdu_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/test/mac/CMakeFiles/pdu_test.dir/build: lib/test/mac/pdu_test

.PHONY : lib/test/mac/CMakeFiles/pdu_test.dir/build

lib/test/mac/CMakeFiles/pdu_test.dir/clean:
	cd /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac && $(CMAKE_COMMAND) -P CMakeFiles/pdu_test.dir/cmake_clean.cmake
.PHONY : lib/test/mac/CMakeFiles/pdu_test.dir/clean

lib/test/mac/CMakeFiles/pdu_test.dir/depend:
	cd /home/cciadmin/Infocom2023-RIC-O-Demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cciadmin/Infocom2023-RIC-O-Demo /home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/mac /home/cciadmin/Infocom2023-RIC-O-Demo/build /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/mac/CMakeFiles/pdu_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/test/mac/CMakeFiles/pdu_test.dir/depend

