cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(myproject)

add_library(
	grid-homology SHARED
	grid_diagram.h
	grid_diagram.cc
	grid_move.h
	grid_move.cc
	vector_related_tools.h
	vector_related_tools.cc
	classic_invariants.h
	classic_invariants.cc
	grid_state.h
	grid_state.cc
	heegaard_floer.h
	heegaard_floer.cc
	sample_functions.h
	sample_functions.cc
	)

add_executable(myproject main.cc) 

target_link_libraries(myproject PRIVATE grid-homology)

