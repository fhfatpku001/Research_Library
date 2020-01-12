/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtaininga copy of the license at 
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
namespace griddiagram {
  
class GridDiagram {
public:
  // @brief Constructor of the class GridDiagram;
  // @param x_pos the column positions of x-type points;
  // @param o_pos the column positions of o-type points;
  // @param assigned_grid_size the size of the grid, it
  // should be equal to the x_pos size and o_pos size;
  GridDiagram (const vector<int>& x_pos, const vector<int>& o_pos);

  // @brief Set new positions for x-type points;
  // @param x_pos the column positions of x-type points;
  void SetXPointsPositions(const vector<int>& x_pos);
  
  // @brief Set new positions for o-type points;
  // @param x_pos the column positions of o-type points;
  void SetOPointsPositions(const vector<int>& o_pos);

  // @brief Check the well-definededness of the GridDiagram;
  // @return true if well-defined; false if not well-defined;
  const bool& IsValidGrid () const;

  // @brief Print the GridDiagram in terminal;
  void PrintGridDiagram() const;

  // @brief Get the positions of x-type points in the Griddiagram;
  // @return In form of {{row(x[i]), col(x[i])}},
  // i from 0 to grid_size -1;
  vector<vector<int>> GetXPointsCoordinates() const;

  // @brief Get the positions of o-type points in the Griddiagram;
  // @return In form of {{row(o_i), col(o_i)}},
  // i from 0 to grid_size -1;
  vector<vector<int>> GetOPointsCoordinates() const;

  // @brief Get the size of the grid diagram;
  // @return size of the grid;
  size_t GetGridSize() const;

  // @brief Get the positions of x points 
  // @return x points positions in vector<int> form;
  const vector<int>& GetXPointsPositions() const;

  // @brief Get the positions of o points 
  // @return o points positions in vector<int> form;
  const vector<int>& GetOPointsPositions() const;
    
private:
  vector<int> x_points_positions_;
  vector<int> o_points_positions_;
  bool is_valid_grid_;

  // @brief Print Two dimensional vector;
  // @param input: the 2-dim vector to be printed;
  void PrintTwoDimensionalVector (const vector<vector<int>>& input) const;

  // @brief Get the row positions of either x_points or o_points;
  // @param points_column_positions
  // @return The row positions of x_points or o_points;
  vector<int> GetRowPositions (const vector<int>& points_column_positions) const;

  // @brief A helper function check whether a grid diagram is valid when constructing it;
  bool CheckValidInput() const;  

};
  
}  // namespace griddiagram
}  // namespace gridhomology
