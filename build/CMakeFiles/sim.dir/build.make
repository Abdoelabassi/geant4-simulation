# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aelabass/Documents/HyperK/geant4-simulation-v1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aelabass/Documents/HyperK/geant4-simulation-v1/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/sim.cc.o: ../sim.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aelabass/Documents/HyperK/geant4-simulation-v1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/sim.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/sim.cc.o -c /home/aelabass/Documents/HyperK/geant4-simulation-v1/sim.cc

CMakeFiles/sim.dir/sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/sim.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aelabass/Documents/HyperK/geant4-simulation-v1/sim.cc > CMakeFiles/sim.dir/sim.cc.i

CMakeFiles/sim.dir/sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/sim.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aelabass/Documents/HyperK/geant4-simulation-v1/sim.cc -o CMakeFiles/sim.dir/sim.cc.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/sim.cc.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/sim.cc.o
sim: CMakeFiles/sim.dir/build.make
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4Tree.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4GMocren.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4visHepRep.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4RayTracer.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4VRML.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4OpenGL.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4gl2ps.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4interfaces.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4persistency.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4analysis.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4error_propagation.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4readout.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4physicslists.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4parmodels.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4FR.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4vis_management.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4modeling.so
sim: /usr/lib/x86_64-linux-gnu/libSM.so
sim: /usr/lib/x86_64-linux-gnu/libICE.so
sim: /usr/lib/x86_64-linux-gnu/libX11.so
sim: /usr/lib/x86_64-linux-gnu/libXext.so
sim: /usr/lib/x86_64-linux-gnu/libGL.so
sim: /usr/lib/x86_64-linux-gnu/libGLU.so
sim: /usr/lib/x86_64-linux-gnu/libXmu.so
sim: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
sim: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.15.2
sim: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
sim: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
sim: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
sim: /usr/lib/x86_64-linux-gnu/libxerces-c.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4run.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4event.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4tracking.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4processes.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4zlib.so
sim: /usr/lib/x86_64-linux-gnu/libexpat.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4digits_hits.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4track.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4particles.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4geometry.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4geomUSolids.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4materials.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4graphics_reps.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4intercoms.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4global.so
sim: /home/aelabass/Documents/geant4.10.01.p03/geant4.10.01.p03-install/lib/libG4clhep.so
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aelabass/Documents/HyperK/geant4-simulation-v1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim

.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /home/aelabass/Documents/HyperK/geant4-simulation-v1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aelabass/Documents/HyperK/geant4-simulation-v1 /home/aelabass/Documents/HyperK/geant4-simulation-v1 /home/aelabass/Documents/HyperK/geant4-simulation-v1/build /home/aelabass/Documents/HyperK/geant4-simulation-v1/build /home/aelabass/Documents/HyperK/geant4-simulation-v1/build/CMakeFiles/sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sim.dir/depend
