/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtaininga copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "vector_related_tools.h"

namespace gridhomology {
namespace tools {
 
void PrintTwoDimensionalVector (const vector<vector<int>>& input) {
  for (const auto& it : input) {
    for (const auto& iit : it) {
      std::cout << iit << " ";
    }
    std::cout << endl;
  }
  std::cout << endl;
}

vector<int> GetRowPositions (const vector<int>& points_column_positions) {
  // Row number of i in points_column_positions are the positions of i;
  vector<int> row_positions_(points_column_positions.size(), 0);

  for (int i = 0; i < points_column_positions.size(); ++i) {
    row_positions_[points_column_positions[i]] = i;
  }

  return row_positions_;
}
  
}  // namespace gridhomology
}  // namespace tools
