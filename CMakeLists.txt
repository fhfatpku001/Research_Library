cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(myproject)

add_library(
	grid-homology SHARED
	grid_diagram.h
	grid_diagram.cc
	grid_move.h
	grid_move.cc
	)

add_executable(myproject main.cc) 

target_link_libraries(myproject PRIVATE grid-homology)

