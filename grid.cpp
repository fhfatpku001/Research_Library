/*Content: This file contains the definitions related to the grid diagram*/

#include "grid.h"




/* print_vec_vec_int-input: a matrix of int;
 * print_vec_vec_int-output: NONE, print matrix;
 */

void grid::print_vec_vec_int (const vector<vector<int>>& input) {
  for (auto it : input) {
      for (auto iit : it) {
	cout << iit << " ";
      }
      cout << endl;
    }
}

/*
 * grid::conjugate_vec-input:
 * grid::conjugate_vec_output:
 * @grid::conjugate_vec.param: result - a hash map, which maps the position of integer i to its position in the input.
*/

vector<int> grid::conjugate_vec (const vector<int>& input) {
  vector<int> result(input.size(), 0);

  for (int i = 0; i < input.size(); ++i) {
    result[input[i]] = i;
  }

  return result;
}

/*
grid::is_valid_grid()-input: NONE;
grid::is_valid_grid()-output: check whether the grid is a valid grid or not;
grid::is_valid_grid().param: occupied_x_pos occupied_o_pos - check if some i in X's or O's appears more than once or not;
*/

bool grid::is_valid_grid (void) {
    if (grid_size != X_pos.size() || grid_size != O_pos.size() || grid_size == 0) {
      return false;
    }

    vector<bool> occupied_x_pos(X_pos.size(), false);
    vector<bool> occupied_o_pos(O_pos.size(), false);

    for (size_t i = 0; i < X_pos.size(); ++i) {
      if (X_pos[i] < 0 || X_pos[i] > grid_size || occupied_x_pos[X_pos[i]] || O_pos[i] < 0 || O_pos[i] > grid_size || occupied_o_pos[O_pos[i]]) {
	return false;
      } else {
	occupied_x_pos[X_pos[i]] = true;
	occupied_o_pos[O_pos[i]] = true;
      }
    }
    
    return true;
};

/*
grid::X_coordinates()-input: X points in vector<col_posistion> form;
gird::X_coordinates()-output: X points in vector {row, col} form;
@grid::X_coordinates().param: result - store X points coodinates;
*/

vector<vector<int>> grid::X_coordinates (void) {
  vector<vector<int>> result;
  if (is_valid) {
    for (int i = 0; i < X_pos.size(); ++i) {
      result.push_back({i, X_pos[i]});
    }
  }

  return result;
}

/*
grid::O_coordinates()-input: O points in vector<col_posistion> form;
gird::O_coordinates()-output: O points in vector {row, col} form;
@grid::O_coordinates().param: result - store O points coodinates;
*/

vector<vector<int>>grid::O_coordinates (void) {
  vector<vector<int>> result;
  if (is_valid) {
    for (int i = 0; i < O_pos.size(); ++i) {
      result.push_back({i, O_pos[i]});
    }
  }
  
  return result;
}

/*
grid::print_X_coordinates()-input: NONE;
grid::print_X_coordinates()-output: print the X points coordinate;
*/
void grid::print_X_coordinates(void) {
  print_vec_vec_int(X_coordinates());
}

/*
grid::print_O_coordinates()-input: NONE;
grid::print_O_coordinates()-output: print the O points coordinate;
*/

void grid::print_O_coordinates(void) {
  print_vec_vec_int(O_coordinates());
}

/*
grid::print_grid() - input: void;
grid::print_grid() - output: print the grid in terminal;
grid::print_grid() - version: 1.0; 
*/

void grid::print_grid(void) {
  if (grid_size > 10) {
    cout << "Grid size is too large!" << endl;
      return;
  }

  if (!is_valid) {
    cout << "Grid is invalid!" << endl;
    return;
  }
    
  for (size_t j = 0; j < grid_size; ++j) {
    cout << ".___" ; // block horizontal line length = 4;
  }
  cout << "." <<endl;

  for (int i = 0; i < grid_size; ++i) {
    for (int j = 0; j < grid_size; ++j) {
      string s = "|   ";

      if (X_pos[i] == j && O_pos[i] == j) {
	s[1] = 'X'; s[3] = 'O'; // if a block contains both X and O;
      } else if (X_pos[i] == j && O_pos[i] != j) {
	s[2] = 'X'; // a block contains a single X;
      } else if (X_pos[i] != j && O_pos[i] == j) {
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

/*
grid::num_link_components()-input: void;
grid::num_link_components()-output: the number of link components;
grid::num_link_components()-algorithm:: DFS, start from one X find all X in the same components, mark them visited X points;
@grid::num_link_components()-conj_O_pos: the hash map store position of the number i;
@grid::num_link_components()-visited: store visited X position.
*/

int grid::num_link_components(void) {
  vector<int> conj_O_pos = conjugate_vec(O_pos);
  vector<bool> visited(X_pos.size(), false);
  int count = 0;

  for (int i = 0; i < X_pos.size(); ++i) {
    if (!visited[i]) {
	++count;
	int next_pos = conj_O_pos[X_pos[i]];

	while (next_pos != i) {
	  visited[next_pos] = true;
	  next_pos = conj_O_pos[X_pos[next_pos]];
	}
		
      }
    }
    
  return count;
}

/*
grid::grid-constructor of class grid;
grid::grid-input: X-points positions, O-points positions, grid size;
grid::grid-remark: first assign X,O points positions, based on the positions and grid size, check if the grid is valid or not. Set the result in is_valid;
*/

grid::grid(const vector<int>& _X_pos, const vector<int>& _O_pos, int _grid_size) {
  X_pos = _X_pos;
  O_pos = _O_pos;
  grid_size = _grid_size;
  is_valid = is_valid_grid();
}

/*
grid::is_knot()-input: void;
grid::is_knot()-output: check if a grid represent a knot or not ;
*/

bool grid::is_knot() {
  return  (is_valid_grid() && num_link_components() == 1) ? true : false;
}


