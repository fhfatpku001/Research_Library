/******************************************************************************
 * Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)
 * 
 * Licensed under the MIT License. You may obtaininga copy of the license at 
 * 
 * https://github.com/fhfatpku001/Research_Library/blob/master/LICENSE
 *****************************************************************************/

#include "vector_related_tools.h"

namespace gridhomology {
namespace tools {
 
void PrintTwoDimensionalVector (const vector<vector<int>>& input) {
  for (const auto& it : input) {
    for (const auto& iit : it) {
      std::cout << iit << " ";
    }
    std::cout << endl;
  }
  std::cout << endl;
}

vector<int> GetRowPositions (const vector<int>& points_column_positions) {
  // Row number of i in points_column_positions are the positions of i;
  vector<int> row_positions(points_column_positions.size(), 0);

  for (int i = 0; i < points_column_positions.size(); ++i) {
    row_positions[points_column_positions[i]] = i;
  }

  return row_positions;
}

int JFunction (const vector<pair<double,double>>& p_set, const vector<pair<double,double>>& q_set) {
  if (p_set.empty() || q_set.empty()) {
    return 0;
  }

  int count = 0;
  for (size_t i = 0; i < p_set.size(); ++i) {
    for (size_t j = 0; j < q_set.size(); ++j) {
      if (p_set[i].first < q_set[j].first && p_set[i].second < q_set[j].second) {
	++count;
      }
    }
  }
  return count;
}

double SymJFunction (const vector<pair<double,double>>& p_set, const vector<pair<double,double>>& q_set) {
  double result = JFunction(p_set, q_set) + JFunction(q_set, p_set);
  result /= 2.0;
  return result;
}

bool IsValidPermutation (const vector<int>& sequence_of_numbers) {
  // check empty input;
  if (sequence_of_numbers.empty()) {
    return false;
  }

  // each 0 to n - 1 should be visited exactly once;
  vector<bool> visited_positions(sequence_of_numbers.size(), false);
  for (size_t i = 0; i < sequence_of_numbers.size(); ++i) {
    if (sequence_of_numbers[i] < 0 || sequence_of_numbers[i] > sequence_of_numbers.size() || visited_positions[sequence_of_numbers[i]]) {
      return false;
    } else {
      visited_positions[sequence_of_numbers[i]] = true;
    }
  }
  return true;
}
  
}  // namespace gridhomology
}  // namespace tools

