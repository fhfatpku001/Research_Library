/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtaininga copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "grid_diagram.h"

namespace gridhomology {
namespace griddiagram {

GridDiagram::GridDiagram (const vector<int>& x_pos, const vector<int>& o_pos) {
  x_points_positions_ = x_pos;
  o_points_positions_ = o_pos;
  is_valid_grid_ = CheckValidInput();
}

const bool& GridDiagram::IsValidGrid() const {
  return is_valid_grid_;
}

void GridDiagram::PrintTwoDimensionalVector (const vector<vector<int>>& input) const {
  for (const auto& it : input) {
    for (const auto& iit : it) {
      std::cout << iit << " ";
    }
    std::cout << endl;
  }
  std::cout << endl;
}

vector<int> GridDiagram::GetRowPositions (const vector<int>& points_column_positions) const {
  // Row number of i in points_column_positions are the positions of i;
  vector<int> row_positions_(points_column_positions.size(), 0);

  for (int i = 0; i < points_column_positions.size(); ++i) {
    row_positions_[points_column_positions[i]] = i;
  }

  return row_positions_;
}

void GridDiagram::PrintGridDiagram() const {
  // Requirement on the grid size;
  if (GetGridSize() > 10) {
    cout << "Grid size is too large!" << endl;
    return;
  }

  // Do not print invalid grid;
  if (!IsValidGrid()) {
    cout << "Grid is invalid!" << endl;
    return;
  }

  // Print the top boundary of the grid;
  for (int j = 0; j < GetGridSize(); ++j) {
    cout << ".___" ; // set block horizontal line length = 4;
  }
  cout << "." <<endl;
  // Print the grid together with the X and O points;
  // when both X and O in the same block, print X O; 
  for (int i = 0; i < GetGridSize(); ++i) {
    for (int j = 0; j < GetGridSize(); ++j) {
      string blank_block_ = "|   ";
      if (x_points_positions_[i] == j && o_points_positions_[i] == j) {
	// a block contains both X and O;
	blank_block_[1] = 'X'; blank_block_[3] = 'O'; 
      } else if (x_points_positions_[i] == j && o_points_positions_[i] != j) {
	// a block contains a single X;
	blank_block_[2] = 'X'; 
      } else if (x_points_positions_[i] != j && o_points_positions_[i] == j) {
	// a block contains a single O;
	blank_block_[2] = 'O'; 
      }
      cout << blank_block_ ;
    }
    cout << "|" << endl;
    for (int j = 0; j < GetGridSize(); ++j) {
      cout << ".___" ; 
    }
    cout << "." <<endl;
  }
  return ;
}

vector<vector<int>> GridDiagram::GetXPointsCoordinates() const {
  // Check Valid Grid before get x points positions;
  if (!IsValidGrid()) {
    return {};
  }

  // Get x_points coordinates;
  vector<vector<int>> x_coordinates_;
  for (int i = 0; i < x_points_positions_.size(); ++i) {
    x_coordinates_.push_back({i, x_points_positions_[i]});
  }
  return x_coordinates_;
}

vector<vector<int>> GridDiagram::GetOPointsCoordinates() const {
  // Check Valid Grid before get o points positions;
  if (!IsValidGrid()) {
    return {};
  }

  // Get o_points coordinates;
  vector<vector<int>> o_coordinates_;
  for (int i = 0; i < o_points_positions_.size(); ++i) {
    o_coordinates_.push_back({i, o_points_positions_[i]});
  }
  return o_coordinates_;
}

void GridDiagram::SetXPointsPositions(const vector<int>& x_pos) {
  // Check the well-definedness of x_points positions before we reset
  // the positions of x points; 
  if (x_pos.empty() || x_pos.size() != GetGridSize()) {
    return;
  }

  // construct a temporary hash map visited_x_positions to check if input is valid;
  vector<bool> visited_x_positions_(x_pos.size(), false);
  for (int i = 0; i < GetGridSize(); ++i) {
    if (visited_x_positions_[x_pos[i]] || x_pos[i] >= GetGridSize() || x_pos[i] < 0) {
      std::cout << "invalid x positions" << endl;
      return;
    } else {
      visited_x_positions_[x_pos[i]] = true;
    }
  }
  x_points_positions_ = x_pos;
  return;
}

void GridDiagram::SetOPointsPositions(const vector<int> &o_pos) {
  // Check the well-definedness of o_points positions before we reset
  // the positions of o points; 
  if (o_pos.size() != GetGridSize()|| o_pos.empty()) {
    return;
  }

  // construct a temporary hash map visited_o_positions to check if input is valid;
  vector<bool> visited_o_positions_(o_pos.size(), false);
  for (int i = 0; i < GetGridSize(); ++i) {
    if (visited_o_positions_[o_pos[i]] || o_pos[i] >= GetGridSize() || o_pos[i] < 0) {
      return;
    } else {
      visited_o_positions_[o_pos[i]] = true;
    }
  }
  o_points_positions_ = o_pos;
  return;
}

bool GridDiagram::CheckValidInput() const {
  // step1: check if the gridsize is positive and match the number of x and o points;
  if (x_points_positions_.empty() || x_points_positions_.size() != o_points_positions_.size()) {
    return false;
  }

  // step2: check if x points and o points are permutation of {0,1,..., grid_size - 1};
  vector<bool> visited_x_positions_(x_points_positions_.size(), false);
  vector<bool> visited_o_positions_(o_points_positions_.size(), false);

  for (size_t i = 0; i < GetGridSize(); ++i) {
    if (x_points_positions_[i] < 0 || x_points_positions_[i] >= GetGridSize() || o_points_positions_[i] < 0 || o_points_positions_[i] >= GetGridSize() || visited_x_positions_[x_points_positions_[i]] || visited_o_positions_[o_points_positions_[i]]) {
      return false;
    } else {
      visited_x_positions_[x_points_positions_[i]] = true;
      visited_o_positions_[o_points_positions_[i]] = true;
    }
  }

  return true;
}

size_t GridDiagram::GetGridSize() const {
  return x_points_positions_.size();
}

  
}  // namespace griddiagram
}  // namespace gridhomology




