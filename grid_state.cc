/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtain a copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "grid_state.h"

#include <iostream>
#include <string>
#include <vector>

#include "vector_related_tools.h"

using namespace std;
using namespace gridhomology::tools;

namespace gridhomology {
namespace gridstate {

GridState::GridState(const vector<int>& intersection_positions) {
  grid_state_positions_ = intersection_positions;
  is_valid_grid_state_ = IsValidPermutation(intersection_positions);
}

void GridState::SetGridStatePositions(const vector<int> &intersection_positions) {
  grid_state_positions_ = intersection_positions;
  is_valid_grid_state_ = IsValidPermutation(intersection_positions);
  return;
}

void GridState::PrintGridState() const {
  // Requirement on grid diagram size;
  const size_t& grid_size = grid_state_positions_.size();
  if (grid_size > 10) {
    cout << "Grid size is too large!" << endl;
      return;
  }

  // GridState should be valid;
  if (!is_valid_grid_state_) {
    cout << "Grid state is invalid!" << endl;
    return;
  }

  // Print out the GridState;
  for (size_t i = 0; i < grid_size; ++i) {
    for (size_t j = 0; j < grid_size; ++j) {
      string blank_line = ".___";
      if(j == grid_state_positions_[i]) {
	blank_line[0] = '*'; 
      }
      cout << blank_line ; 
    }
    cout << "." <<endl;
    for (int j = 0; j < grid_size; ++j) {
      cout << "|   " ;
    }
    cout << "|" << endl;
  }
  // the first row and last row should be identified.
  for (int j = 0; j < grid_size; ++j) {
    string blank_line = ".___";
    if(j == grid_state_positions_[0]) {
      // the position of intersections. 
      blank_line[0] = '*';
    }
    cout << blank_line; 
  }
  cout << '.' << endl;
}

const bool& GridState::IsValidGridState() const {
  return is_valid_grid_state_;
}
  
vector<pair<double, double>> GridState::GetGridStateCoordinates() const {
  // Check Valid GridState;
  if (!IsValidGridState()) {
    return {};
  }

  // convert the positions of intersections to coordinates;
  vector<pair<double, double>> result;
  for (size_t i = 0; i < grid_state_positions_.size(); ++i) {
    result.push_back({i, grid_state_positions_[i]});
  }
  return result;
}

size_t GridState::GetGridStateSize() const {
  return grid_state_positions_.size();
};

const vector<int>& GridState::GetGridStatePositions() const {
  return grid_state_positions_;
}  
  
}  // namespace gridstate
}  // namespace gridhomology
