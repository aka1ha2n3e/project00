# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/djredwing/project000

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/djredwing/project000/cmp

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o: /Users/djredwing/project000/test/ScreenManagerTest.cpp
CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o -MF CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o.d -o CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o -c /Users/djredwing/project000/test/ScreenManagerTest.cpp

CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/test/ScreenManagerTest.cpp > CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.i

CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/test/ScreenManagerTest.cpp -o CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.s

CMakeFiles/Test.dir/src/FileDriver.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/FileDriver.cpp.o: /Users/djredwing/project000/src/FileDriver.cpp
CMakeFiles/Test.dir/src/FileDriver.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test.dir/src/FileDriver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/FileDriver.cpp.o -MF CMakeFiles/Test.dir/src/FileDriver.cpp.o.d -o CMakeFiles/Test.dir/src/FileDriver.cpp.o -c /Users/djredwing/project000/src/FileDriver.cpp

CMakeFiles/Test.dir/src/FileDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/FileDriver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/FileDriver.cpp > CMakeFiles/Test.dir/src/FileDriver.cpp.i

CMakeFiles/Test.dir/src/FileDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/FileDriver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/FileDriver.cpp -o CMakeFiles/Test.dir/src/FileDriver.cpp.s

CMakeFiles/Test.dir/src/Log.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/Log.cpp.o: /Users/djredwing/project000/src/Log.cpp
CMakeFiles/Test.dir/src/Log.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Test.dir/src/Log.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/Log.cpp.o -MF CMakeFiles/Test.dir/src/Log.cpp.o.d -o CMakeFiles/Test.dir/src/Log.cpp.o -c /Users/djredwing/project000/src/Log.cpp

CMakeFiles/Test.dir/src/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/Log.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/Log.cpp > CMakeFiles/Test.dir/src/Log.cpp.i

CMakeFiles/Test.dir/src/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/Log.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/Log.cpp -o CMakeFiles/Test.dir/src/Log.cpp.s

CMakeFiles/Test.dir/src/SampleClass.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/SampleClass.cpp.o: /Users/djredwing/project000/src/SampleClass.cpp
CMakeFiles/Test.dir/src/SampleClass.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Test.dir/src/SampleClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/SampleClass.cpp.o -MF CMakeFiles/Test.dir/src/SampleClass.cpp.o.d -o CMakeFiles/Test.dir/src/SampleClass.cpp.o -c /Users/djredwing/project000/src/SampleClass.cpp

CMakeFiles/Test.dir/src/SampleClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/SampleClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/SampleClass.cpp > CMakeFiles/Test.dir/src/SampleClass.cpp.i

CMakeFiles/Test.dir/src/SampleClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/SampleClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/SampleClass.cpp -o CMakeFiles/Test.dir/src/SampleClass.cpp.s

CMakeFiles/Test.dir/src/UI.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/UI.cpp.o: /Users/djredwing/project000/src/UI.cpp
CMakeFiles/Test.dir/src/UI.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Test.dir/src/UI.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/UI.cpp.o -MF CMakeFiles/Test.dir/src/UI.cpp.o.d -o CMakeFiles/Test.dir/src/UI.cpp.o -c /Users/djredwing/project000/src/UI.cpp

CMakeFiles/Test.dir/src/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/UI.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/UI.cpp > CMakeFiles/Test.dir/src/UI.cpp.i

CMakeFiles/Test.dir/src/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/UI.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/UI.cpp -o CMakeFiles/Test.dir/src/UI.cpp.s

CMakeFiles/Test.dir/src/common.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/common.cpp.o: /Users/djredwing/project000/src/common.cpp
CMakeFiles/Test.dir/src/common.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Test.dir/src/common.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/common.cpp.o -MF CMakeFiles/Test.dir/src/common.cpp.o.d -o CMakeFiles/Test.dir/src/common.cpp.o -c /Users/djredwing/project000/src/common.cpp

CMakeFiles/Test.dir/src/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/common.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/common.cpp > CMakeFiles/Test.dir/src/common.cpp.i

CMakeFiles/Test.dir/src/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/common.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/common.cpp -o CMakeFiles/Test.dir/src/common.cpp.s

CMakeFiles/Test.dir/src/iterator.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/iterator.cpp.o: /Users/djredwing/project000/src/iterator.cpp
CMakeFiles/Test.dir/src/iterator.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Test.dir/src/iterator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/iterator.cpp.o -MF CMakeFiles/Test.dir/src/iterator.cpp.o.d -o CMakeFiles/Test.dir/src/iterator.cpp.o -c /Users/djredwing/project000/src/iterator.cpp

CMakeFiles/Test.dir/src/iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/iterator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/iterator.cpp > CMakeFiles/Test.dir/src/iterator.cpp.i

CMakeFiles/Test.dir/src/iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/iterator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/iterator.cpp -o CMakeFiles/Test.dir/src/iterator.cpp.s

CMakeFiles/Test.dir/src/type.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/type.cpp.o: /Users/djredwing/project000/src/type.cpp
CMakeFiles/Test.dir/src/type.cpp.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Test.dir/src/type.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/type.cpp.o -MF CMakeFiles/Test.dir/src/type.cpp.o.d -o CMakeFiles/Test.dir/src/type.cpp.o -c /Users/djredwing/project000/src/type.cpp

CMakeFiles/Test.dir/src/type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/type.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/djredwing/project000/src/type.cpp > CMakeFiles/Test.dir/src/type.cpp.i

CMakeFiles/Test.dir/src/type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/type.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/djredwing/project000/src/type.cpp -o CMakeFiles/Test.dir/src/type.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o" \
"CMakeFiles/Test.dir/src/FileDriver.cpp.o" \
"CMakeFiles/Test.dir/src/Log.cpp.o" \
"CMakeFiles/Test.dir/src/SampleClass.cpp.o" \
"CMakeFiles/Test.dir/src/UI.cpp.o" \
"CMakeFiles/Test.dir/src/common.cpp.o" \
"CMakeFiles/Test.dir/src/iterator.cpp.o" \
"CMakeFiles/Test.dir/src/type.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/test/ScreenManagerTest.cpp.o
Test: CMakeFiles/Test.dir/src/FileDriver.cpp.o
Test: CMakeFiles/Test.dir/src/Log.cpp.o
Test: CMakeFiles/Test.dir/src/SampleClass.cpp.o
Test: CMakeFiles/Test.dir/src/UI.cpp.o
Test: CMakeFiles/Test.dir/src/common.cpp.o
Test: CMakeFiles/Test.dir/src/iterator.cpp.o
Test: CMakeFiles/Test.dir/src/type.cpp.o
Test: CMakeFiles/Test.dir/build.make
Test: lib/libgtest.a
Test: lib/libgtest_main.a
Test: /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libcurses.tbd
Test: /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libform.tbd
Test: lib/libgtest.a
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/djredwing/project000/cmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test
.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /Users/djredwing/project000/cmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/djredwing/project000 /Users/djredwing/project000 /Users/djredwing/project000/cmp /Users/djredwing/project000/cmp /Users/djredwing/project000/cmp/CMakeFiles/Test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Test.dir/depend
