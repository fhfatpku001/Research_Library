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

vector<vector<int>> GetAllPermutation (const int& start_num, const int& end_num) {
  // Check valid input; Require increasing sequence;
  if (end_num < start_num) {
    return {};
  }

  // Construct increasing sequence from start_num to end_num;
  const size_t sequence_size = end_num - start_num + 1;
  vector<bool> visited(sequence_size, false);
  vector<int> current_sequence;
  vector<vector<int>> all_permutations;
  HelperGetAllPermutation (all_permutations, current_sequence, visited, start_num);
  return all_permutations;
}
  
void HelperGetAllPermutation (vector<vector<int>>& all_permutations, vector<int>& current_sequence, vector<bool>& visited, const int& start_num) {
  // A Helper functions generate all permutation recursively;
  // Algorithm: Backtracking/DFS;
  if (current_sequence.size() == visited.size()) {
    // Case 1: already get a permutation; 
    all_permutations.push_back(current_sequence);
  } else {
    // Case 2: some slots to be filled;
    for (int i = 0; i < visited.size(); ++i) {
      if (!visited[i]) {
	visited[i] = true;
	current_sequence.push_back(start_num + i);
	HelperGetAllPermutation(all_permutations, current_sequence, visited, start_num);
      }
    }
  }
  // Case 3: verified all possibility, pop_back if possible;
  if (!current_sequence.empty()) {
    visited[current_sequence.back()] = false;
    current_sequence.pop_back();
  }
}
  
}  // namespace gridhomology
}  // namespace tools

