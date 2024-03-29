# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artemiy/CLionProjects/horror/Pac-Man

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artemiy/CLionProjects/horror/Pac-Man

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/artemiy/CLionProjects/horror/Pac-Man/CMakeFiles /home/artemiy/CLionProjects/horror/Pac-Man//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/artemiy/CLionProjects/horror/Pac-Man/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named horror

# Build rule for target.
horror: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 horror
.PHONY : horror

# fast build rule for target.
horror/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/build
.PHONY : horror/fast

display.o: display.cpp.o
.PHONY : display.o

# target to build an object file
display.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/display.cpp.o
.PHONY : display.cpp.o

display.i: display.cpp.i
.PHONY : display.i

# target to preprocess a source file
display.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/display.cpp.i
.PHONY : display.cpp.i

display.s: display.cpp.s
.PHONY : display.s

# target to generate assembly for a file
display.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/display.cpp.s
.PHONY : display.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/main.cpp.s
.PHONY : main.cpp.s

maze.o: maze.cpp.o
.PHONY : maze.o

# target to build an object file
maze.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/maze.cpp.o
.PHONY : maze.cpp.o

maze.i: maze.cpp.i
.PHONY : maze.i

# target to preprocess a source file
maze.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/maze.cpp.i
.PHONY : maze.cpp.i

maze.s: maze.cpp.s
.PHONY : maze.s

# target to generate assembly for a file
maze.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/maze.cpp.s
.PHONY : maze.cpp.s

objects.o: objects.cpp.o
.PHONY : objects.o

# target to build an object file
objects.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/objects.cpp.o
.PHONY : objects.cpp.o

objects.i: objects.cpp.i
.PHONY : objects.i

# target to preprocess a source file
objects.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/objects.cpp.i
.PHONY : objects.cpp.i

objects.s: objects.cpp.s
.PHONY : objects.s

# target to generate assembly for a file
objects.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/objects.cpp.s
.PHONY : objects.cpp.s

save.o: save.cpp.o
.PHONY : save.o

# target to build an object file
save.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/save.cpp.o
.PHONY : save.cpp.o

save.i: save.cpp.i
.PHONY : save.i

# target to preprocess a source file
save.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/save.cpp.i
.PHONY : save.cpp.i

save.s: save.cpp.s
.PHONY : save.s

# target to generate assembly for a file
save.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/save.cpp.s
.PHONY : save.cpp.s

source.o: source.cpp.o
.PHONY : source.o

# target to build an object file
source.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/source.cpp.o
.PHONY : source.cpp.o

source.i: source.cpp.i
.PHONY : source.i

# target to preprocess a source file
source.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/source.cpp.i
.PHONY : source.cpp.i

source.s: source.cpp.s
.PHONY : source.s

# target to generate assembly for a file
source.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/source.cpp.s
.PHONY : source.cpp.s

table_records.o: table_records.cpp.o
.PHONY : table_records.o

# target to build an object file
table_records.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/table_records.cpp.o
.PHONY : table_records.cpp.o

table_records.i: table_records.cpp.i
.PHONY : table_records.i

# target to preprocess a source file
table_records.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/table_records.cpp.i
.PHONY : table_records.cpp.i

table_records.s: table_records.cpp.s
.PHONY : table_records.s

# target to generate assembly for a file
table_records.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/horror.dir/build.make CMakeFiles/horror.dir/table_records.cpp.s
.PHONY : table_records.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... horror"
	@echo "... display.o"
	@echo "... display.i"
	@echo "... display.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... maze.o"
	@echo "... maze.i"
	@echo "... maze.s"
	@echo "... objects.o"
	@echo "... objects.i"
	@echo "... objects.s"
	@echo "... save.o"
	@echo "... save.i"
	@echo "... save.s"
	@echo "... source.o"
	@echo "... source.i"
	@echo "... source.s"
	@echo "... table_records.o"
	@echo "... table_records.i"
	@echo "... table_records.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

