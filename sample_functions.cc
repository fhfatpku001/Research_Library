/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtaininga copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "sample_functions.h"

namespace gridhomology {
namespace sample {

//@brief Given Grid diagram size n,
//find the probablity of "such a grid diagram represent a knot";
double GetProbabilityOfKnotInGridDiagram (const int& n) {
  if (n < 1) {
    return 0;
  }

  vector<vector<int>> all_permutations = GetAllPermutation(0, n - 1);
  
  int count_all_grids = 0;
  int count_knot = 0;
  
  for (const auto& it : all_permutations) {
    for (const auto& iit : all_permutations) {
      GridDiagram grid_diagram(it, iit);
      if(IsKnot(grid_diagram)) {
	++count_knot;
      }
      ++count_all_grids;
    }
  }
  double result = count_knot;
  result /= count_all_grids;
  return result;
};  
  
}  // namespace sample;
}  // namespace gridhomology;
