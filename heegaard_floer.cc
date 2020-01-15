/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtain a copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "heegaard_floer.h"

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
namespace heegardfloer {

vector<GridState> GetAllGridState (const GridDiagram& grid_diagram) {
  const int start_num = 0;
  const int end_num = grid_diagram.GetGridSize() - 1;
  vector<vector<int>> all_permutations = gridhomology::tools::GetAllPermutation(start_num, end_num);
  vector<GridState> all_grid_states;
  for (size_t i = 0; i < all_permutations.size(); ++i) {
    GridState grid_state(all_permutations[i]);
    all_grid_states.push_back(grid_state);
  }

  return all_grid_states;
};

void PrintAllGridState (const GridDiagram& grid_diagram) {
  // TODO: to be optimized;
  vector<GridState> all_grid_states = GetAllGridState(grid_diagram);
  for (const auto& it : all_grid_states) {
    it.PrintGridState();
  }
};
  
}  // namespace heegaardfloer;
}  // namespace gridhomology;
