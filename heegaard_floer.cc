/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtain a copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "heegaard_floer.h"

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

double GetXMaslovGrading (const GridDiagram& grid_diagram, const GridState& grid_state) {
  // Check Valid Input;
  if (!grid_diagram.IsValidGrid() || grid_diagram.GetGridSize() != grid_state.GetGridStateSize()) {
    return INT_MAX;
  }

  // SymJfunction(gs, gs) + SymJfunction(X, X) - 2 SymJfunction(gs, X) + 1;
  const vector<pair<double, double>>& x_cooridnates = grid_diagram.GetXPointsCoordinates();
  const vector<pair<double, double>>& grid_state_coordinates = grid_state.GetGridStateCoordinates();
  double result = gridhomology::tools::SymJFunction(x_cooridnates, x_cooridnates) + gridhomology::tools::SymJFunction(grid_state_coordinates, grid_state_coordinates) - 2 * gridhomology::tools::SymJFunction(x_cooridnates, grid_state_coordinates) + 1;
  return result;
}

double GetOMaslovGrading (const GridDiagram& grid_diagram, const GridState& grid_state) {
  // Check Valid Input;
  if (!grid_diagram.IsValidGrid() || grid_diagram.GetGridSize() != grid_state.GetGridStateSize()) {
    return INT_MAX;
  }

  // SymJfunction(gs, gs) + SymJfunction(O, O) - 2 SymJfunction(gs, O) + 1;
  const vector<pair<double, double>>& o_cooridnates = grid_diagram.GetOPointsCoordinates();
  const vector<pair<double, double>>& grid_state_coordinates = grid_state.GetGridStateCoordinates();
  double result = gridhomology::tools::SymJFunction(o_cooridnates, o_cooridnates) + gridhomology::tools::SymJFunction(grid_state_coordinates, grid_state_coordinates) - 2 * gridhomology::tools::SymJFunction(o_cooridnates, grid_state_coordinates) + 1;
  return result;
}

double GetReducedAlexanderGrading (const GridDiagram& grid_diagram, const GridState& grid_state) {
  // Check Valid Input;
  if (!grid_diagram.IsValidGrid() || grid_diagram.GetGridSize() != grid_state.GetGridStateSize()) {
    return INT_MAX;
  }
  // return 1/2 * (Maslov_O(gs) - Maslov_X(gs) - grid_size + 1);
  return (GetOMaslovGrading(grid_diagram, grid_state) - GetXMaslovGrading(grid_diagram, grid_state) - grid_diagram.GetGridSize() + 1) / 2.0;
};
  
}  // namespace heegaardfloer;
}  // namespace gridhomology;
