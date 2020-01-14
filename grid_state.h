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

using namespace std;

namespace gridhomology {
namespace gridstate {

class GridState {
public:
  // @brief Constructor
  // @param intersection_positions A sequence of numbers represents
  // the positions of intersections;
  GridState (const vector<int>& intersection_positions);

  // @brief Reset the grid_state;
  // @param intersection_positions The new positions;
  void SetGridStatePositions (const vector<int>& intersection_positions);

  // @brief Print a GridState;
  void PrintGridState() const;

  // @brief Check if a GridState is Valid or not;
  // @return true if valid : false if not valid; 
  const bool& IsValidGridState() const;

  // @brief Get the coordinates of all intersections in a GridState;
  // @return The cooridnates in {{row, column}} form;
  vector<pair<double, double>> GetGridStateCoordinates() const;

  // @brief Get the grid state size;
  // @return The size of a GridState;
  size_t GetGridStateSize() const;

  // @brief Get the grid state positions;
  // @return The GridState intersections positions;
  const vector<int>& GetGridStatePositions() const;
  
private:
  vector<int> grid_state_positions_;
  bool is_valid_grid_state_;
};
  
}  // namespace gridstate
}  // namespace gridhomology



