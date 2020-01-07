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
  
  /*-------------------- Grid_moves ---------------------------------*/

  void h_com (const int& row_1); // (DONE 1/3) commute row_1 with row_1 + 1. Check availability before doing the commute.
  
//( Remark: if one needs to do a sequence of v_coms, it is better to do a hash map first.)
  void h_cyc (void); //DONE 1/2 exchange rows.
  
  void v_cyc (void); //DONE 1/6 exchange cols;

  void v_com (const int& col_1); //Done 1/6 col commutation;
  
  void stab(const int& row, const int& col); // WAITLIST

  void destab(const int& row, const int& col); // WAITLIST

  bool is_alternating (void); // WAITLIST
  
};

/* General definition of generators of a grid 
 * A generator of is set of n intersections points, each pair of the two intersections are not in same horizontal line or vertical line. 
 * Hence it can be represented by (a_0, ... a_{N - 1}) which is a permutation of (0,..., N-1); 
 */

class grid_generator {
private:
  vector<int> gen_pos; // store the position of intersections points;
  int gen_size; // store the generator size;
  bool is_valid_gen;
public:
  grid_generator (const vector<int>& _gen_pos, const int& _gen_size); //(DONE 1/2) constructor;

  bool is_valid_generator (void); // (DONE 1/2) check if the generator is valid or not;

  void print_gen(void);  //(DONE 1/2) print the generator;
};


/* Heegaard Floer homology related functions */
class HF {
public:
  HF () { 
  } // constructor. NOT yet decided.
  
  vector<grid_generator*> all_generators (const grid& A); //TODO output all generators of 
  
  void print_grid_and_gen (const grid& A, const grid_generator& x); // TODO print the grade together with the generator;

  int maslov_grading (const grid& A, const grid_generator& x); //TODO: Calculate the Maslov grading of certain generator;

  vector<grid_generator*> kernal (const grid& A); //TODO: Kernal of the differentials

  vector<grid_generator*> image (const grid& A); // TODO: image of the differentials;

  vector<grid_generator*> HF_hat_gen (const grid& A); // TODO: calcuate the HF hat from grid diagram;

  int tau_invariant (const grid& A); // TODO: calcuate the tau invariant of the grade diagram;

  int upsilon_invariant (const grid& A); // TODO: the upsilon invariant of the grade diagram;

  vector<int,int> involutive_upsilon_invariant (const grid& A); // TODO: the involutive upsilon invariant 

  int signature_invariant (const grid& A); //TODO: the signature of the grade diagram;
  
  vector<int> reduced_alexander_poly (const grid& A); // TODO: calcuate the alexander polynomial of a grid diagram.
};
