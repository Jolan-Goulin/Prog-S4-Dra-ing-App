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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build"

# Utility rule file for docs.

# Include the progress variables for this target.
include p6/third-party/glfw/docs/CMakeFiles/docs.dir/progress.make

p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/include/GLFW/glfw3.h
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/include/GLFW/glfw3native.h
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/main.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/news.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/quick.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/moving.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/compile.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/build.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/intro.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/context.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/monitor.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/window.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/input.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/vulkan.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/compat.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/internal.dox
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/DoxygenLayout.xml
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/header.html
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/footer.html
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/extra.css
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/spaces.svg
p6/third-party/glfw/docs/html/index.html: ../p6/third-party/glfw/docs/Doxyfile.in
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Generating HTML documentation"
	cd "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build/p6/third-party/glfw/docs" && /usr/bin/doxygen

docs: p6/third-party/glfw/docs/html/index.html
docs: p6/third-party/glfw/docs/CMakeFiles/docs.dir/build.make

.PHONY : docs

# Rule to build all files generated by this target.
p6/third-party/glfw/docs/CMakeFiles/docs.dir/build: docs

.PHONY : p6/third-party/glfw/docs/CMakeFiles/docs.dir/build

p6/third-party/glfw/docs/CMakeFiles/docs.dir/clean:
	cd "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build/p6/third-party/glfw/docs" && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : p6/third-party/glfw/docs/CMakeFiles/docs.dir/clean

p6/third-party/glfw/docs/CMakeFiles/docs.dir/depend:
	cd "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main" "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/p6/third-party/glfw/docs" "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build" "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build/p6/third-party/glfw/docs" "/home/6ima2/jolan.goulin/Bureau/projet c++/Simple-Cpp-Setup-main/build/p6/third-party/glfw/docs/CMakeFiles/docs.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : p6/third-party/glfw/docs/CMakeFiles/docs.dir/depend

