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

// @brief: A grid diagram represents a link,
// this function get the number of link connected
// components (number of circles)
// @param: grid_diagram Represents a grid diagram;
// @return: Number of link components; (non-negative);
size_t GetNumOfLinkComponents (const GridDiagram& grid_diagram);

// @brief: Check whether a grid diagram represents a knot or not;
// @param: grid_diagram Input a grid diagram;
// @return: true, if is a knot : false, otherwise;
bool IsKnot(const GridDiagram& grid_diagram);

// TODO: Alexander Polynomial.
// TODO: Signature of a link.
}  // namespace classicinvariants
}  // namespace gridhomology

