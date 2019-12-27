#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
#include <bitset>
#include "grid.h"
using namespace std;



void grid::print_vec_vec_int (const vector<vector<int>>& input) {
  for (auto it : input) {
      for (auto iit : it) {
	cout << iit << " ";
      }
      cout << endl;
    }
}

vector<int> grid::conjugate_vec (const vector<int>& input) {
  vector<int> result(input.size(), 0);

  for (int i = 0; i < input.size(); ++i) {
    result[input[i]] = i;
  }

  return result;
}



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



vector<vector<int>> grid::X_coordinates (void) {
  vector<vector<int>> result;
  if (is_valid) {
    for (int i = 0; i < X_pos.size(); ++i) {
      result.push_back({i, X_pos[i]});
    }
  }

  return result;
}
  
vector<vector<int>>grid::O_coordinates (void) {
  vector<vector<int>> result;
  if (is_valid) {
    for (int i = 0; i < O_pos.size(); ++i) {
      result.push_back({i, O_pos[i]});
    }
  }
  
  return result;
}

void grid::print_X_coordinates(void) {
  print_vec_vec_int(X_coordinates());
}

void grid::print_O_coordinates(void) {
  print_vec_vec_int(O_coordinates());
}
  

  
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
    cout << ".___" ;
  }
  cout << "." <<endl;

  for (int i = 0; i < grid_size; ++i) {
    for (int j = 0; j < grid_size; ++j) {
      string s = "|   ";

      if (X_pos[i] == j && O_pos[i] == j) {
	s[1] = 'X'; s[3] = 'O';
      } else if (X_pos[i] == j && O_pos[i] != j) {
	s[2] = 'X';
	} else if (X_pos[i] != j && O_pos[i] == j) {
	s[2] = 'O'; 
      }
	
	cout << s ;
      }
      cout << "|" << endl;

      for (int j = 0; j < grid_size; ++j) {
	cout << ".___" ;
      }
      cout << "." <<endl;
    }
}


int grid::num_link_components(void) {
    //DFS
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

grid::grid(const vector<int>& _X_pos, const vector<int>& _O_pos, int _grid_size) {
  X_pos = _X_pos;
  O_pos = _O_pos;
  grid_size = _grid_size;
  is_valid = is_valid_grid();
}

bool grid::is_knot() {
  return  (is_valid_grid() && num_link_components() == 1) ? true : false;
}
