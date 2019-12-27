#pragma once

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

using namespace std;


/* General Definitio of Grid:
 * A square with vertical and horizontal lines, which divides the squre into smaller square equally.
 * Remark: In topology, this grid represent a torus, when one identify bottom boundary with top boundary, and left bdry with right bdry.  
 * The position of X points and O points will give rises to a link: One connect X_i with O_j in same row, and X_k with O_l in same column.
 */

class grid {
private:
  
  vector<int> X_pos; //store the coord of {X_0,...X_{n-1}} points//
  vector<int> O_pos; //store the coord of {X_0,...X_{n-1}} points//
  int grid_size; // the size of the grid diagram//
  bool is_valid; // check a grid is a valid grid diagram for links or not.

  void print_vec_vec_int (const vector<vector<int>>& input); //(DONE 12/25) Aux function for print a matrix of int.

  vector<int> conjugate_vec (const vector<int>& input); //(DONE 12/25) A hand-maded hash map, map the column num to row number.
  
public:

  grid(const vector<int>& _X_pos, const vector<int>& _O_pos, int _grid_size); // (DONE 12/27) constructor of a grid: given position of X points, O points and grid size //

  bool is_valid_grid (void); // (DONE 12/26) return valid grid or not

  int num_link_components(void); // (DONE 12/26) return the number of link components in a grid (Algorithm: DFS, time O(N), space O(N)).
 
  vector<vector<int>> X_coordinates (void); // (DONE 12/26) return the X points coordinates in {row, col} format.
  
  vector<vector<int>> O_coordinates (void); //(DONE 12/26) return all O points coordinates in {row, col} format.

  void print_X_coordinates(void); // (DONE 12/26) print the X points coordinates in {row, col} format.

  void print_O_coordinates(void); // (DONE 12/26) print all O points coordinates in {row, col} format.
  
  void print_grid(void); // (DONE 12/26) print grid together with X or O points. Grid size should be less than or equal to 10.

  bool is_knot (void); // (DONE 12/27) check if a grid represent a knot or not; 

  // TODO LIST
  //: grid/ stabilization, commutation, cyclic permutation.

  void stab(const int& row, const int& col);

  void destab(const int& row, const int& col);

  void h_com (const int& row_1, const int& row_2);

  void v_com (const int& col_1, const int& col_2);
  
};

/* General definition of generators of a grid 
 * A generator of is set of n intersections points, each pair of the two intersections are not in same horizontal line or vertical line. 
 * Hence it can be represented by (a_0, ... a_{N - 1}) which is a permutation of (0,..., N-1); 
 */

class grid_generator {
private:
  vector<int> gen_pos; // store the position of intersections points;
  int gen_size; // store the generator size;

public:
  grid_generator (const vector<int>& _gen_pos, const vector<int>& gen_size);

  bool is_valid_generator (void);

  void print_gen(void);  
};


/* Heegaard Floer homology related functions */
class HF {
public:
  vector<grid_generator*> all_generators (const grid& A);
  
  
};
