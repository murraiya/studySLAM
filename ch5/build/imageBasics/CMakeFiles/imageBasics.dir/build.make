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
CMAKE_SOURCE_DIR = /home/sj/slambook2/studySLAM/ch5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sj/slambook2/studySLAM/ch5/build

# Include any dependencies generated for this target.
include imageBasics/CMakeFiles/imageBasics.dir/depend.make

# Include the progress variables for this target.
include imageBasics/CMakeFiles/imageBasics.dir/progress.make

# Include the compile flags for this target's objects.
include imageBasics/CMakeFiles/imageBasics.dir/flags.make

imageBasics/CMakeFiles/imageBasics.dir/imageBasics.cpp.o: imageBasics/CMakeFiles/imageBasics.dir/flags.make
imageBasics/CMakeFiles/imageBasics.dir/imageBasics.cpp.o: ../imageBasics/imageBasics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sj/slambook2/studySLAM/ch5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object imageBasics/CMakeFiles/imageBasics.dir/imageBasics.cpp.o"
	cd /home/sj/slambook2/studySLAM/ch5/build/imageBasics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imageBasics.dir/imageBasics.cpp.o -c /home/sj/slambook2/studySLAM/ch5/imageBasics/imageBasics.cpp

imageBasics/CMakeFiles/imageBasics.dir/imageBasics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imageBasics.dir/imageBasics.cpp.i"
	cd /home/sj/slambook2/studySLAM/ch5/build/imageBasics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sj/slambook2/studySLAM/ch5/imageBasics/imageBasics.cpp > CMakeFiles/imageBasics.dir/imageBasics.cpp.i

imageBasics/CMakeFiles/imageBasics.dir/imageBasics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imageBasics.dir/imageBasics.cpp.s"
	cd /home/sj/slambook2/studySLAM/ch5/build/imageBasics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sj/slambook2/studySLAM/ch5/imageBasics/imageBasics.cpp -o CMakeFiles/imageBasics.dir/imageBasics.cpp.s

# Object files for target imageBasics
imageBasics_OBJECTS = \
"CMakeFiles/imageBasics.dir/imageBasics.cpp.o"

# External object files for target imageBasics
imageBasics_EXTERNAL_OBJECTS =

imageBasics/imageBasics: imageBasics/CMakeFiles/imageBasics.dir/imageBasics.cpp.o
imageBasics/imageBasics: imageBasics/CMakeFiles/imageBasics.dir/build.make
imageBasics/imageBasics: /usr/local/lib/libopencv_dnn.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_highgui.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_ml.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_objdetect.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_shape.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_stitching.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_superres.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_videostab.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_calib3d.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_features2d.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_flann.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_photo.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_video.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_videoio.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_imgcodecs.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_imgproc.so.3.4.16
imageBasics/imageBasics: /usr/local/lib/libopencv_core.so.3.4.16
imageBasics/imageBasics: imageBasics/CMakeFiles/imageBasics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sj/slambook2/studySLAM/ch5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable imageBasics"
	cd /home/sj/slambook2/studySLAM/ch5/build/imageBasics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imageBasics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
imageBasics/CMakeFiles/imageBasics.dir/build: imageBasics/imageBasics

.PHONY : imageBasics/CMakeFiles/imageBasics.dir/build

imageBasics/CMakeFiles/imageBasics.dir/clean:
	cd /home/sj/slambook2/studySLAM/ch5/build/imageBasics && $(CMAKE_COMMAND) -P CMakeFiles/imageBasics.dir/cmake_clean.cmake
.PHONY : imageBasics/CMakeFiles/imageBasics.dir/clean

imageBasics/CMakeFiles/imageBasics.dir/depend:
	cd /home/sj/slambook2/studySLAM/ch5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sj/slambook2/studySLAM/ch5 /home/sj/slambook2/studySLAM/ch5/imageBasics /home/sj/slambook2/studySLAM/ch5/build /home/sj/slambook2/studySLAM/ch5/build/imageBasics /home/sj/slambook2/studySLAM/ch5/build/imageBasics/CMakeFiles/imageBasics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : imageBasics/CMakeFiles/imageBasics.dir/depend

