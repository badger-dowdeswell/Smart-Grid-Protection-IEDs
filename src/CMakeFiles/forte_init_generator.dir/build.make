# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/badger/CMake/bin/cmake

# The command to remove a file.
RM = /home/badger/CMake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/badger/org.eclipse.4diac.forte

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/badger/Development/4diac/Smart_Grid_02

# Utility rule file for forte_init_generator.

# Include the progress variables for this target.
include src/CMakeFiles/forte_init_generator.dir/progress.make

src/CMakeFiles/forte_init_generator:
	cd /home/badger/Development/4diac/Smart_Grid_02/src && /home/badger/CMake/bin/cmake -DFORTE_BINARY_DIR:STRING="/home/badger/Development/4diac/Smart_Grid_02" -DFORTE_SOURCE_DIR:STRING="/home/badger/org.eclipse.4diac.forte" -DFORTE_USE_64BIT_DATATYPES:STRING="ON" -DFORTE_USE_REAL_DATATYPE:STRING="ON" -DFORTE_USE_LREAL_DATATYPE:STRING="ON" -DFORTE_SUPPORT_ARRAYS:STRING="ON" -DFORTE_LITTLE_ENDIAN:STRING= -DFORTE_BIG_ENDIAN:STRING= -DFORTE_LOGLEVEL:STRING="LOGDEBUG" -P /home/badger/org.eclipse.4diac.forte/buildsupport/generate_init.cmake

forte_init_generator: src/CMakeFiles/forte_init_generator
forte_init_generator: src/CMakeFiles/forte_init_generator.dir/build.make

.PHONY : forte_init_generator

# Rule to build all files generated by this target.
src/CMakeFiles/forte_init_generator.dir/build: forte_init_generator

.PHONY : src/CMakeFiles/forte_init_generator.dir/build

src/CMakeFiles/forte_init_generator.dir/clean:
	cd /home/badger/Development/4diac/Smart_Grid_02/src && $(CMAKE_COMMAND) -P CMakeFiles/forte_init_generator.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/forte_init_generator.dir/clean

src/CMakeFiles/forte_init_generator.dir/depend:
	cd /home/badger/Development/4diac/Smart_Grid_02 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/badger/org.eclipse.4diac.forte /home/badger/org.eclipse.4diac.forte/src /home/badger/Development/4diac/Smart_Grid_02 /home/badger/Development/4diac/Smart_Grid_02/src /home/badger/Development/4diac/Smart_Grid_02/src/CMakeFiles/forte_init_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/forte_init_generator.dir/depend

