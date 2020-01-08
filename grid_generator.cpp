#include "grid.h"
/* Content: This file constains the definitions related to the grid_generators */

/*@grid_generator::grid_generator: constructor of the class grid_generator*/
grid_generator::grid_generator(const vector<int>& _gen_pos, const int& _gen_size) {
  gen_pos = _gen_pos; // store the position of the intersections.
  gen_size = _gen_size; // generator size = grid size.
  is_valid_gen = is_valid_generator(); // check if a generator is valid or not;
}

/*
grid_generator::is_valid_generator()-input: void
grid_generator::is_valid_generator()-output: bool valid generator or not;
@grid_generator::is_valid_generator().param: visited - store visited positions.
*/

bool grid_generator::is_valid_generator(void) {
  if (gen_size <= 0 || gen_size != gen_pos.size()) {
    return false;
  } // gen_size should match the number of elements in gen_pos;

  vector<bool> visited(gen_size, false);

  for (size_t i = 0; i < gen_pos.size(); ++i) {
    if (gen_pos[i] < 0 || gen_pos[i] >= gen_size || visited[gen_pos[i]]) {
      return false;
    } // each position should be visited exactly once.

    visited[gen_pos[i]] = true;
  }

  return true;
}

/*
grid_generator::print_gen(void) - input: void;
grid_generator::print_gen(void) - output: Void, print the generator;
*/

void grid_generator::print_gen(void) { 
  if (gen_size > 10) {
    cout << "Generator size is too large!" << endl;
      return;
  }

  if (!is_valid_gen) {
    cout << "Generator is invalid!" << endl;
    return;
  }
    
  for (int i = 0; i < gen_size; ++i) {
    for (int j = 0; j < gen_size; ++j) {
      string s = ".___";

      if(j == gen_pos[i]) {
	s[0] = '*'; // the position of intersections. 
      }
      
      cout << s ; 
    }
    cout << "." <<endl;

    for (int j = 0; j < gen_size; ++j) {
      cout << "|   " ;
    }
    cout << "|" << endl;
  }
  // the first row and last row should be identified.
  for (int j = 0; j < gen_size; ++j) {
    string s = ".___";

    if(j == gen_pos[0]) {
      s[0] = '*'; // the position of intersections. 
    }
      
    cout << s ; 
  }
  cout << '.' << endl;
  
  return;
}

void grid_generator::print_gen_vec(void) {
  std::cout << "(";
  for (int i = 0; i < gen_size; ++i) {
    std::cout << gen_pos[i] << " ";
  }

  std::cout << ")" << endl;
}
