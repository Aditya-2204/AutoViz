# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Utility rule file for appAutoViz2_copy_qml.

# Include any custom commands dependencies for this target.
include CMakeFiles/appAutoViz2_copy_qml.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appAutoViz2_copy_qml.dir/progress.make

CMakeFiles/appAutoViz2_copy_qml: .qt/appAutoViz2_qml.txt

.qt/appAutoViz2_qml.txt: /Users/adityachakraborty/Qt/6.8.2/macos/lib/cmake/Qt6Qml/Qt6QmlCopyFiles.cmake
.qt/appAutoViz2_qml.txt: /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/Main.qml
.qt/appAutoViz2_qml.txt: /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/SimScreen.qml
.qt/appAutoViz2_qml.txt: /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/Robot.qml
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying appAutoViz2 qml sources into build dir"
	/opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -DFILES_INFO_PATH=/Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/.qt/appAutoViz2_qml.cmake -P /Users/adityachakraborty/Qt/6.8.2/macos/lib/cmake/Qt6Qml/Qt6QmlCopyFiles.cmake

appAutoViz2_copy_qml: .qt/appAutoViz2_qml.txt
appAutoViz2_copy_qml: CMakeFiles/appAutoViz2_copy_qml
appAutoViz2_copy_qml: CMakeFiles/appAutoViz2_copy_qml.dir/build.make
.PHONY : appAutoViz2_copy_qml

# Rule to build all files generated by this target.
CMakeFiles/appAutoViz2_copy_qml.dir/build: appAutoViz2_copy_qml
.PHONY : CMakeFiles/appAutoViz2_copy_qml.dir/build

CMakeFiles/appAutoViz2_copy_qml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appAutoViz2_copy_qml.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appAutoViz2_copy_qml.dir/clean

CMakeFiles/appAutoViz2_copy_qml.dir/depend:
	cd /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2 /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2 /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/adityachakraborty/Desktop/Code/C++/Robotics/AutoViz2/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/appAutoViz2_copy_qml.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/appAutoViz2_copy_qml.dir/depend

