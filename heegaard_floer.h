/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtain a copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <climits>

#include "grid_diagram.h"
#include "grid_state.h"
#include "vector_related_tools.h"

using namespace std;
using namespace gridhomology::griddiagram;
using namespace gridhomology::gridstate;

namespace gridhomology {
namespace heegardfloer {

// @brief: Generate all grid state of a grid diagram;
// @param: grid_diagram A grid diagram;
// @return: All grid states of grid_diagram;
vector<GridState> GetAllGridState (const GridDiagram& grid_diagram);

// @brief: Print all grid states of a grid diagram;
// @param: grid_diagram A grid diagram;
void PrintAllGridState (const GridDiagram& grid_diagram);   

// @brief: Get Maslov X Grading of a GridState;
// @param: grid_diagram A grid diagram;
// @param: grid_state A grid state inside this diagram;
// @return: Maslov X grading (half integer, double); 
double GetXMaslovGrading (const GridDiagram& grid_diagram, const GridState& grid_state);

// @brief: Get Maslov X Grading of a GridState;
// @param: grid_diagram A grid diagram;
// @param: grid_state A grid state inside this diagram;
// @return: Maslov X grading (half integer, double);   
double GetOMaslovGrading (const GridDiagram& grid_diagram, const GridState& grid_state);  

// @brief: Get Alexander Grading of a GridState;
// @param: grid_diagram A grid diagram;
// @param: grid_state A grid state inside this diagram;
// @return: Alexander grading (half integer, double);   
double GetReducedAlexanderGrading (const GridDiagram& grid_diagram, const GridState& grid_state);
  
}  // namespace heegaardfloer;
}  // namespace gridhomology;

