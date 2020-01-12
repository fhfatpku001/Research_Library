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

using namespace std;

namespace gridhomology {
namespace tools {

// @brief Print Two dimensional vector;
// @param input: the 2-dim vector to be printed;
void PrintTwoDimensionalVector (const vector<vector<int>>& input);

// @brief Get the row positions of either x_points or o_points;
// @param points_column_positions
// @return The row positions of x_points or o_points;
vector<int> GetRowPositions (const vector<int>& points_column_positions);

   
}  // namespace tools
}  // namespace gridhomology
