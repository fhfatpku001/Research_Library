/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtain a copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "classic_invariants.h"
#include "vector_related_tools.h"

using namespace std;

using namespace gridhomology::griddiagram;
using namespace gridhomology::tools;

namespace gridhomology {
namespace classicinvariants {

size_t GetNumOfLinkComponents (const GridDiagram& grid_diagram) {
  const vector<int>& x_positions = grid_diagram.GetXPointsPositions();
  const vector<int> conjugate_o_positions = GetRowPositions(grid_diagram.GetOPointsPositions());
  vector<bool> visited_x_positions(grid_diagram.GetGridSize(), false);
  size_t count = 0;
  for (size_t i = 0; i < x_positions.size(); ++i) {
    if (!visited_x_positions[i]) {
      ++count;

      int next_o_position = conjugate_o_positions[x_positions[i]];
      while (next_o_position != i) {
	visited_x_positions[next_o_position] = true;
	next_o_position = conjugate_o_positions[x_positions[next_o_position]];
      }
    }
  }

  return count;
};

bool IsKnot(const GridDiagram& grid_diagram) {
  return (GetNumOfLinkComponents(grid_diagram) == 1) ? true : false;
};

}  // namespace classicinvariants
}  // namespace gridhomology
