# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/home/badger/CMake/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/home/badger/CMake/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/home/badger/CMake/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/home/badger/CMake/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/home/badger/CMake/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/badger/CMake/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/home/badger/CMake/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/home/badger/CMake/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/badger/Development/4diac/Smart_Grid_02/CMakeFiles /home/badger/Development/4diac/Smart_Grid_02/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/badger/Development/4diac/Smart_Grid_02/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named forte_stringlist_externals

# Build rule for target.
forte_stringlist_externals: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 forte_stringlist_externals
.PHONY : forte_stringlist_externals

# fast build rule for target.
forte_stringlist_externals/fast:
	$(MAKE) -f CMakeFiles/forte_stringlist_externals.dir/build.make CMakeFiles/forte_stringlist_externals.dir/build
.PHONY : forte_stringlist_externals/fast

#=============================================================================
# Target rules for targets named forte_stringlist_generator

# Build rule for target.
forte_stringlist_generator: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 forte_stringlist_generator
.PHONY : forte_stringlist_generator

# fast build rule for target.
forte_stringlist_generator/fast:
	$(MAKE) -f src/CMakeFiles/forte_stringlist_generator.dir/build.make src/CMakeFiles/forte_stringlist_generator.dir/build
.PHONY : forte_stringlist_generator/fast

#=============================================================================
# Target rules for targets named FORTE_LITE

# Build rule for target.
FORTE_LITE: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 FORTE_LITE
.PHONY : FORTE_LITE

# fast build rule for target.
FORTE_LITE/fast:
	$(MAKE) -f src/CMakeFiles/FORTE_LITE.dir/build.make src/CMakeFiles/FORTE_LITE.dir/build
.PHONY : FORTE_LITE/fast

#=============================================================================
# Target rules for targets named forte_init_generator

# Build rule for target.
forte_init_generator: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 forte_init_generator
.PHONY : forte_init_generator

# fast build rule for target.
forte_init_generator/fast:
	$(MAKE) -f src/CMakeFiles/forte_init_generator.dir/build.make src/CMakeFiles/forte_init_generator.dir/build
.PHONY : forte_init_generator/fast

#=============================================================================
# Target rules for targets named forte

# Build rule for target.
forte: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 forte
.PHONY : forte

# fast build rule for target.
forte/fast:
	$(MAKE) -f src/CMakeFiles/forte.dir/build.make src/CMakeFiles/forte.dir/build
.PHONY : forte/fast

#=============================================================================
# Target rules for targets named forte_generate_modules_cmake_files

# Build rule for target.
forte_generate_modules_cmake_files: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 forte_generate_modules_cmake_files
.PHONY : forte_generate_modules_cmake_files

# fast build rule for target.
forte_generate_modules_cmake_files/fast:
	$(MAKE) -f src/CMakeFiles/forte_generate_modules_cmake_files.dir/build.make src/CMakeFiles/forte_generate_modules_cmake_files.dir/build
.PHONY : forte_generate_modules_cmake_files/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... edit_cache"
	@echo "... forte_stringlist_externals"
	@echo "... install"
	@echo "... rebuild_cache"
	@echo "... list_install_components"
	@echo "... install/local"
	@echo "... forte_stringlist_generator"
	@echo "... FORTE_LITE"
	@echo "... forte_init_generator"
	@echo "... forte"
	@echo "... forte_generate_modules_cmake_files"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
