/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtaininga copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "grid_diagram_class.h"

griddiagramnamespace::GridDiagram::GridDiagram (const vector<int>& x_pos, const vector<int>& o_pos, const int& assigned_grid_size) {
  x_points_positions = x_pos;
  o_points_positions = o_pos;
  grid_size = assigned_grid_size;
  is_valid_grid = HelperIsValidGrid();
}

bool griddiagramnamespace::GridDiagram::IsValidGrid() {
  return is_valid_grid;
}

void griddiagramnamespace::GridDiagram::PrintTwoDimensionalVector (const vector<vector<int>>& input) {
  for (auto it : input) {
    for (auto iit : it) {
      std::cout << iit << " ";
    }
    std::cout << endl;
  }
  std::cout << endl;
}

vector<int> griddiagramnamespace::GridDiagram::GetRowPositions (const vector<int>& points_column_positions) {
  // Row number of i in points_column_positions are the positions of i;
  vector<int> row_positions(points_column_positions.size(), 0);

  for (int i = 0; i < points_column_positions.size(); ++i) {
    row_positions[points_column_positions[i]] = i;
  }

  return row_positions;
}

void griddiagramnamespace::GridDiagram::PrintGridDiagram() {
  // Requirement on the grid size;
  if (grid_size > 10) {
    cout << "Grid size is too large!" << endl;
    return;
  }

  // Do not print invalid grid;
  if (!is_valid_grid) {
    cout << "Grid is invalid!" << endl;
    return;
  }

  // Print the top boundary of the grid;
  for (int j = 0; j < grid_size; ++j) {
    cout << ".___" ; // set block horizontal line length = 4;
  }
  cout << "." <<endl;

  // Print the grid together with the X and O points;
  // when both X and O in the same block, print X O; 
  for (int i = 0; i < grid_size; ++i) {
    for (int j = 0; j < grid_size; ++j) {
      string s = "|   ";
     
      if (x_points_positions[i] == j && o_points_positions[i] == j) {
	s[1] = 'X'; s[3] = 'O'; // if a block contains both X and O;
      } else if (x_points_positions[i] == j && o_points_positions[i] != j) {
	s[2] = 'X'; // a block contains a single X;
      } else if (x_points_positions[i] != j && o_points_positions[i] == j) {
	s[2] = 'O'; // a block contains a single O;
      }
	
      cout << s ;
    }
    
    cout << "|" << endl;

    for (int j = 0; j < grid_size; ++j) {
      cout << ".___" ; 
    }
    
    cout << "." <<endl;
  }

  return ;
}

vector<vector<int>> griddiagramnamespace::GridDiagram::GetXPointsCoordinates() {
  if (!is_valid_grid) {
    return {};
  }

  vector<vector<int>> x_coordinates;
  
  for (int i = 0; i < x_points_positions.size(); ++i) {
    x_coordinates.push_back({i, x_points_positions[i]});
  }

  return x_coordinates;
}

vector<vector<int>> griddiagramnamespace::GridDiagram::GetOPointsCoordinates() {
  if (!is_valid_grid) {
    return {};
  }

  vector<vector<int>> o_coordinates;
  
  for (int i = 0; i < o_points_positions.size(); ++i) {
    o_coordinates.push_back({i, o_points_positions[i]});
  }

  return o_coordinates;
}

void griddiagramnamespace::GridDiagram::SetXPointsPositions(const vector<int> &x_pos) {
  // Check the well-definedness of x_points positions before we reset
  // the positions of x points; 
  if (x_pos.size() != grid_size || x_pos.empty()) {
    return;
  }

  vector<bool> visited_x_positions(x_pos.size(), false);

  for (int i = 0; i < grid_size; ++i) {
    if (visited_x_positions[x_pos[i]] || x_pos[i] >= grid_size || x_pos[i] < 0) {
      return;
    } else {
      visited_x_positions[x_pos[i]] = true;
    }
  }

  x_points_positions = x_pos;
  return;
}

void griddiagramnamespace::GridDiagram::SetOPointsPositions(const vector<int> &o_pos) {
  // Check the well-definedness of o_points positions before we reset
  // the positions of o points; 
  if (o_pos.size() != grid_size || o_pos.empty()) {
    return;
  }

  vector<bool> visited_o_positions(o_pos.size(), false);

  for (int i = 0; i < grid_size; ++i) {
    if (visited_o_positions[o_pos[i]] || o_pos[i] >= grid_size || o_pos[i] < 0) {
      return;
    } else {
      visited_o_positions[o_pos[i]] = true;
    }
  }

  o_points_positions = o_pos;
  return;
}

bool griddiagramnamespace::GridDiagram::HelperIsValidGrid() {
  // step1: check if the gridsize is positive and match the number of x and o points;
  if (grid_size != x_points_positions.size() || grid_size != o_points_positions.size() || grid_size == 0) {
    return false;
  }

  // step2: check if x points and o points are permutation of {0,1,..., grid_size - 1};
  vector<bool> visited_x_positions(x_points_positions.size(), false);
  vector<bool> visited_o_positions(o_points_positions.size(), false);

  for (size_t i = 0; i < grid_size; ++i) {
    if (x_points_positions[i] < 0 || x_points_positions[i] >= grid_size || o_points_positions[i] < 0 || o_points_positions[i] >= grid_size || visited_x_positions[x_points_positions[i]] || visited_o_positions[o_points_positions[i]]) {
      return false;
    } else {
      visited_x_positions[x_points_positions[i]] = true;
      visited_o_positions[o_points_positions[i]] = true;
    }
  }

  return true;
}

int griddiagramnamespace::GridDiagram::GetGridSize() {
  return grid_size;
}
