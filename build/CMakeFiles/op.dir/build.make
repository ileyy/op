# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/iley/CLionProjects/op

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/iley/CLionProjects/op/build

# Include any dependencies generated for this target.
include CMakeFiles/op.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/op.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/op.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/op.dir/flags.make

CMakeFiles/op.dir/Gen_file.c.o: CMakeFiles/op.dir/flags.make
CMakeFiles/op.dir/Gen_file.c.o: /Users/iley/CLionProjects/op/Gen_file.c
CMakeFiles/op.dir/Gen_file.c.o: CMakeFiles/op.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iley/CLionProjects/op/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/op.dir/Gen_file.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/op.dir/Gen_file.c.o -MF CMakeFiles/op.dir/Gen_file.c.o.d -o CMakeFiles/op.dir/Gen_file.c.o -c /Users/iley/CLionProjects/op/Gen_file.c

CMakeFiles/op.dir/Gen_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/op.dir/Gen_file.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/iley/CLionProjects/op/Gen_file.c > CMakeFiles/op.dir/Gen_file.c.i

CMakeFiles/op.dir/Gen_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/op.dir/Gen_file.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/iley/CLionProjects/op/Gen_file.c -o CMakeFiles/op.dir/Gen_file.c.s

CMakeFiles/op.dir/Var_str.c.o: CMakeFiles/op.dir/flags.make
CMakeFiles/op.dir/Var_str.c.o: /Users/iley/CLionProjects/op/Var_str.c
CMakeFiles/op.dir/Var_str.c.o: CMakeFiles/op.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iley/CLionProjects/op/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/op.dir/Var_str.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/op.dir/Var_str.c.o -MF CMakeFiles/op.dir/Var_str.c.o.d -o CMakeFiles/op.dir/Var_str.c.o -c /Users/iley/CLionProjects/op/Var_str.c

CMakeFiles/op.dir/Var_str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/op.dir/Var_str.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/iley/CLionProjects/op/Var_str.c > CMakeFiles/op.dir/Var_str.c.i

CMakeFiles/op.dir/Var_str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/op.dir/Var_str.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/iley/CLionProjects/op/Var_str.c -o CMakeFiles/op.dir/Var_str.c.s

CMakeFiles/op.dir/File_out.c.o: CMakeFiles/op.dir/flags.make
CMakeFiles/op.dir/File_out.c.o: /Users/iley/CLionProjects/op/File_out.c
CMakeFiles/op.dir/File_out.c.o: CMakeFiles/op.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iley/CLionProjects/op/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/op.dir/File_out.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/op.dir/File_out.c.o -MF CMakeFiles/op.dir/File_out.c.o.d -o CMakeFiles/op.dir/File_out.c.o -c /Users/iley/CLionProjects/op/File_out.c

CMakeFiles/op.dir/File_out.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/op.dir/File_out.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/iley/CLionProjects/op/File_out.c > CMakeFiles/op.dir/File_out.c.i

CMakeFiles/op.dir/File_out.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/op.dir/File_out.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/iley/CLionProjects/op/File_out.c -o CMakeFiles/op.dir/File_out.c.s

CMakeFiles/op.dir/Alg.c.o: CMakeFiles/op.dir/flags.make
CMakeFiles/op.dir/Alg.c.o: /Users/iley/CLionProjects/op/Alg.c
CMakeFiles/op.dir/Alg.c.o: CMakeFiles/op.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iley/CLionProjects/op/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/op.dir/Alg.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/op.dir/Alg.c.o -MF CMakeFiles/op.dir/Alg.c.o.d -o CMakeFiles/op.dir/Alg.c.o -c /Users/iley/CLionProjects/op/Alg.c

CMakeFiles/op.dir/Alg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/op.dir/Alg.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/iley/CLionProjects/op/Alg.c > CMakeFiles/op.dir/Alg.c.i

CMakeFiles/op.dir/Alg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/op.dir/Alg.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/iley/CLionProjects/op/Alg.c -o CMakeFiles/op.dir/Alg.c.s

# Object files for target op
op_OBJECTS = \
"CMakeFiles/op.dir/Gen_file.c.o" \
"CMakeFiles/op.dir/Var_str.c.o" \
"CMakeFiles/op.dir/File_out.c.o" \
"CMakeFiles/op.dir/Alg.c.o"

# External object files for target op
op_EXTERNAL_OBJECTS =

op: CMakeFiles/op.dir/Gen_file.c.o
op: CMakeFiles/op.dir/Var_str.c.o
op: CMakeFiles/op.dir/File_out.c.o
op: CMakeFiles/op.dir/Alg.c.o
op: CMakeFiles/op.dir/build.make
op: CMakeFiles/op.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/iley/CLionProjects/op/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable op"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/op.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/op.dir/build: op
.PHONY : CMakeFiles/op.dir/build

CMakeFiles/op.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/op.dir/cmake_clean.cmake
.PHONY : CMakeFiles/op.dir/clean

CMakeFiles/op.dir/depend:
	cd /Users/iley/CLionProjects/op/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/iley/CLionProjects/op /Users/iley/CLionProjects/op /Users/iley/CLionProjects/op/build /Users/iley/CLionProjects/op/build /Users/iley/CLionProjects/op/build/CMakeFiles/op.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/op.dir/depend
