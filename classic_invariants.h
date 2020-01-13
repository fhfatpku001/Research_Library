/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtain a copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#pragma once

#include "grid_diagram.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using namespace gridhomology::griddiagram;

namespace gridhomology {
namespace classicinvariants {

// @brief: a grid diagram represents a link,
// this function get the number of link connected
// components (number of circles)
// @param: grid_diagram input a grid diagram;
// @return: number of link components; (non-negative);
size_t GetNumOfLinkComponents (GridDiagram* grid_diagram);

// @brief: check whether a grid diagram represents a knot or not;
// @param: grid_diagram input a grid diagram;
// @return: true, if is a knot : false, otherwise;
bool IsKnot(GridDiagram* grid_diagram);

}  // namespace classicinvariants
}  // namespace gridhomology
