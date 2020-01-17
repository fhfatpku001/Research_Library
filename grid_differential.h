
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

#include "grid_diagram.h"
#include "grid_state.h"
#include "vector_related_tools.h"

using namespace std;
using namespace gridhomology::griddiagram;
using namespace gridhomology::gridstate;

namespace gridhomology {
namespace differential {

class Rectangle {
  
}

vector<Rectangle> GetAllRectangles (const GridDiagram& grid_diagram);    

vector<Rectangle> GetAllEmptyRectangle (const GridDiagram& grid_diagram);
  
bool IsBlankRectangle (const GridDiagram& grid_diagram, const Rectangle& rectangle);

size_t CountXInRectangle (const GridDiagram& grid_diagram, const Rectangle& rectangle);

size_t CountOInRectangle (const GridDiagram& grid_diagram, const Rectangle& rectangle);
  
}  // differential
}  // gridhomology
