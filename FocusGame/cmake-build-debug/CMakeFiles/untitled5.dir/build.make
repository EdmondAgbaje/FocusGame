# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\35389\CLionProjects\FocusGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled5.dir/flags.make

CMakeFiles/untitled5.dir/main.c.obj: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled5.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled5.dir\main.c.obj   -c C:\Users\35389\CLionProjects\FocusGame\main.c

CMakeFiles/untitled5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled5.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\35389\CLionProjects\FocusGame\main.c > CMakeFiles\untitled5.dir\main.c.i

CMakeFiles/untitled5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled5.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\35389\CLionProjects\FocusGame\main.c -o CMakeFiles\untitled5.dir\main.c.s

CMakeFiles/untitled5.dir/game_init.c.obj: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/game_init.c.obj: ../game_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled5.dir/game_init.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled5.dir\game_init.c.obj   -c C:\Users\35389\CLionProjects\FocusGame\game_init.c

CMakeFiles/untitled5.dir/game_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled5.dir/game_init.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\35389\CLionProjects\FocusGame\game_init.c > CMakeFiles\untitled5.dir\game_init.c.i

CMakeFiles/untitled5.dir/game_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled5.dir/game_init.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\35389\CLionProjects\FocusGame\game_init.c -o CMakeFiles\untitled5.dir\game_init.c.s

CMakeFiles/untitled5.dir/input_output.c.obj: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/input_output.c.obj: ../input_output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled5.dir/input_output.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled5.dir\input_output.c.obj   -c C:\Users\35389\CLionProjects\FocusGame\input_output.c

CMakeFiles/untitled5.dir/input_output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled5.dir/input_output.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\35389\CLionProjects\FocusGame\input_output.c > CMakeFiles\untitled5.dir\input_output.c.i

CMakeFiles/untitled5.dir/input_output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled5.dir/input_output.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\35389\CLionProjects\FocusGame\input_output.c -o CMakeFiles\untitled5.dir\input_output.c.s

CMakeFiles/untitled5.dir/game_movement.c.obj: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/game_movement.c.obj: ../game_movement.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/untitled5.dir/game_movement.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled5.dir\game_movement.c.obj   -c C:\Users\35389\CLionProjects\FocusGame\game_movement.c

CMakeFiles/untitled5.dir/game_movement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled5.dir/game_movement.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\35389\CLionProjects\FocusGame\game_movement.c > CMakeFiles\untitled5.dir\game_movement.c.i

CMakeFiles/untitled5.dir/game_movement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled5.dir/game_movement.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\35389\CLionProjects\FocusGame\game_movement.c -o CMakeFiles\untitled5.dir\game_movement.c.s

CMakeFiles/untitled5.dir/winner.c.obj: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/winner.c.obj: ../winner.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/untitled5.dir/winner.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled5.dir\winner.c.obj   -c C:\Users\35389\CLionProjects\FocusGame\winner.c

CMakeFiles/untitled5.dir/winner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled5.dir/winner.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\35389\CLionProjects\FocusGame\winner.c > CMakeFiles\untitled5.dir\winner.c.i

CMakeFiles/untitled5.dir/winner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled5.dir/winner.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\35389\CLionProjects\FocusGame\winner.c -o CMakeFiles\untitled5.dir\winner.c.s

CMakeFiles/untitled5.dir/keptPiece_movement.c.obj: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/keptPiece_movement.c.obj: ../keptPiece_movement.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/untitled5.dir/keptPiece_movement.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled5.dir\keptPiece_movement.c.obj   -c C:\Users\35389\CLionProjects\FocusGame\keptPiece_movement.c

CMakeFiles/untitled5.dir/keptPiece_movement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled5.dir/keptPiece_movement.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\35389\CLionProjects\FocusGame\keptPiece_movement.c > CMakeFiles\untitled5.dir\keptPiece_movement.c.i

CMakeFiles/untitled5.dir/keptPiece_movement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled5.dir/keptPiece_movement.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\35389\CLionProjects\FocusGame\keptPiece_movement.c -o CMakeFiles\untitled5.dir\keptPiece_movement.c.s

# Object files for target untitled5
untitled5_OBJECTS = \
"CMakeFiles/untitled5.dir/main.c.obj" \
"CMakeFiles/untitled5.dir/game_init.c.obj" \
"CMakeFiles/untitled5.dir/input_output.c.obj" \
"CMakeFiles/untitled5.dir/game_movement.c.obj" \
"CMakeFiles/untitled5.dir/winner.c.obj" \
"CMakeFiles/untitled5.dir/keptPiece_movement.c.obj"

# External object files for target untitled5
untitled5_EXTERNAL_OBJECTS =

untitled5.exe: CMakeFiles/untitled5.dir/main.c.obj
untitled5.exe: CMakeFiles/untitled5.dir/game_init.c.obj
untitled5.exe: CMakeFiles/untitled5.dir/input_output.c.obj
untitled5.exe: CMakeFiles/untitled5.dir/game_movement.c.obj
untitled5.exe: CMakeFiles/untitled5.dir/winner.c.obj
untitled5.exe: CMakeFiles/untitled5.dir/keptPiece_movement.c.obj
untitled5.exe: CMakeFiles/untitled5.dir/build.make
untitled5.exe: CMakeFiles/untitled5.dir/linklibs.rsp
untitled5.exe: CMakeFiles/untitled5.dir/objects1.rsp
untitled5.exe: CMakeFiles/untitled5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable untitled5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled5.dir/build: untitled5.exe

.PHONY : CMakeFiles/untitled5.dir/build

CMakeFiles/untitled5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled5.dir/clean

CMakeFiles/untitled5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\35389\CLionProjects\FocusGame C:\Users\35389\CLionProjects\FocusGame C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug C:\Users\35389\CLionProjects\FocusGame\cmake-build-debug\CMakeFiles\untitled5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled5.dir/depend

