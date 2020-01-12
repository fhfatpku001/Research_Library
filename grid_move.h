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
#include <queue>
#include <stack>
#include <functional>
#include <unordered_map>
#include <unordered_set>

#include "grid_diagram.h"

using namespace std;
using namespace gridhomology::griddiagram;

namespace gridmoves{

// 
void DoHorizontalCommutation (GridDiagram* grid_diagram, const int& row);

void DoVerticalCommutation(GridDiagram* grid_diagram, const int& col);

void DoVerticalCommutation (GridDiagram* grid_diagram, const int& col);
  
void DoHorizontalCyclicPermutation (GridDiagram* grid_diagram);
  
void DoVerticalCyclicPermutation (GridDiagram* grid_diagram);
  
// TODO: void DoStabilization (GridDiagram* grid_diagram, const int& row, const int& col);
  
// TODO: void DoDestabilization (GridDiagram* grid_diagram, const int& row, const int& col);

}


  


