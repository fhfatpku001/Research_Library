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
#include <queue>
#include <stack>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace gridhomology {
namespace tools {

// @brief Print Two dimensional vector;
// @param input: the 2-dim vector to be printed;
void PrintTwoDimensionalVector (const vector<vector<int>>& input);

// @brief Get the row positions of either x_points or o_points;
// @param points_column_positions
// @return The row positions of x_points or o_points;
vector<int> GetRowPositions (const vector<int>& points_column_positions);

// @brief Let p_point = (p_1, p_2) and q_point = (q_1, q_2).
// We say p_point < q_point if q_1 < q_1 and p_2 < q_2;
// JFunction count all pair <p_point, q_point> such that p_point < q_point;
// @param p_set Contains all p_points coordinate;
// @param q_set Contains all q_points coordinate;
// @return Count the number of pair <p_point, q_point>
// with p_point < q_point; (Require this count be int)
int JFunction (const vector<pair<double,double>>& p_set, const vector<pair<double,double>>& q_set);

// @breif Symmetic JFunction; (to calculate Maslov index)
// @param p_set Contains all p_points coordinate;
// @param q_set Contains all q_points coordinate;
// @return Count the number of pair <p_point, q_point>
//  with p_point < q_point;
// and the number of pair <q_point, p_point>
//  with q_point < p_point;and take average(double);
double SymJFunction (const vector<pair<double,double>>& p_set, const vector<pair<double,double>>& q_set);

// @brief Check whether a vector is a permutation of {0,1,2,...n};
// @param sequence_of_numbers the input vector to be checked;
// @return true if is a permutation : false otherwise;
bool IsValidPermutation (const vector<int>& sequence_of_numbers);
  
}  // namespace tools
}  // namespace gridhomology

