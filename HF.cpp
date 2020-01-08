// This file include the definitions of HF related functions.

#include "grid.h"
/*
HF::all_generators(grid *A) - input: a grid diagram A;
HF::all_generators(grid *A) - output: all generators of the grid diagram;
@HF::all_generators(grid *A).param:
grid_size - store the size of A;
visited - hash to check whether an intersection choose or not;
result - store the final result of all generators;
*/

vector<grid_generator*> HF::all_generators(grid* A) {
  // Get grid size, check if the grid is valid or not;
  if (!A->is_valid_grid()) {
    return {};
  }

  int grid_size = A->get_grid_size();

  vector<bool> visited(grid_size, false);
  vector<int> current_vec;
  vector<grid_generator*> result;

  helper_gens(result, current_vec, visited); // recursively, backtracking/DFS;
  
  return result;
}

/*
HF::helper_gens - input:
result - a vector store all gens;
cur_vec - a vec store current intersection positions;
visited - hash, check whether an intersection choose or not
*/

void HF::helper_gens (vector<grid_generator*>& result, vector<int>& current_vec, vector<bool>& visited) {
  if (current_vec.size() == visited.size()) {
    grid_generator* cur_gen = new grid_generator(current_vec, visited.size());
    result.push_back(cur_gen);
  } else {
    for (int i = 0; i < visited.size(); ++i) {
      if (!visited[i]) {
	visited[i] = true;
	current_vec.push_back(i);
	helper_gens(result, current_vec, visited);
      }
    }
  }

  if (!current_vec.empty()) {
    visited[current_vec.back()] = false;
    current_vec.pop_back();
  }
}
