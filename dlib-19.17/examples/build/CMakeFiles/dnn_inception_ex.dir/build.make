# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/dnn_inception_ex.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dnn_inception_ex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dnn_inception_ex.dir/flags.make

CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.o: CMakeFiles/dnn_inception_ex.dir/flags.make
CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.o: ../dnn_inception_ex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.o -c /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/dnn_inception_ex.cpp

CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/dnn_inception_ex.cpp > CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.i

CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/dnn_inception_ex.cpp -o CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.s

# Object files for target dnn_inception_ex
dnn_inception_ex_OBJECTS = \
"CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.o"

# External object files for target dnn_inception_ex
dnn_inception_ex_EXTERNAL_OBJECTS =

dnn_inception_ex: CMakeFiles/dnn_inception_ex.dir/dnn_inception_ex.cpp.o
dnn_inception_ex: CMakeFiles/dnn_inception_ex.dir/build.make
dnn_inception_ex: dlib_build/libdlib.a
dnn_inception_ex: /usr/lib64/libSM.so
dnn_inception_ex: /usr/lib64/libICE.so
dnn_inception_ex: /usr/lib64/libX11.so
dnn_inception_ex: /usr/lib64/libXext.so
dnn_inception_ex: /usr/lib64/libpng.so
dnn_inception_ex: /usr/lib64/libz.so
dnn_inception_ex: /usr/lib64/libjpeg.so
dnn_inception_ex: CMakeFiles/dnn_inception_ex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dnn_inception_ex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dnn_inception_ex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dnn_inception_ex.dir/build: dnn_inception_ex

.PHONY : CMakeFiles/dnn_inception_ex.dir/build

CMakeFiles/dnn_inception_ex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dnn_inception_ex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dnn_inception_ex.dir/clean

CMakeFiles/dnn_inception_ex.dir/depend:
	cd /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build /home/johan.lenagard/Documents/2Y/hub/my_workshop/dlib-19.17/examples/build/CMakeFiles/dnn_inception_ex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dnn_inception_ex.dir/depend

