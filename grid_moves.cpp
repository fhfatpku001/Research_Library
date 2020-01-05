/*Content: This file contains the definitions related to the grid diagram changes, i.e. grid moves. commutations, and stablizations*/

#include "grid.h"

/*
grid::h_com(const int &row_1)-input: void;
grid::h_com(const int &row_1)-output: void, commutations of row_1 and row_1 + 1;
grid::h_com(const int &row_1).param: (a,b) - the interval in row_1, (c,d) the interval of row_1 + 1;
*/

void grid::h_com(const int &row_1) {
  int row_2 = (row_1 + 1) % grid_size;
  
  if (row_1 < 0 || row_1 >= grid_size || row_2 < 0 || row_2 >= grid_size) {
    std::cout << "invalid row numbers!" << endl;
    return;
  }
  
  int a = min(X_pos[row_1], O_pos[row_1]);
  int b = max(X_pos[row_1], O_pos[row_1]);
  int c = min(X_pos[row_2], O_pos[row_2]);
  int d = max(X_pos[row_2], O_pos[row_2]);

  // four cases such that (a, b)  and (c,d) anc commute.
  if ( (a <= c && b >= d) || (a >= c && b <= d) || a >= d || b <= c) {
    std::cout << "can commute" << endl;
    // swap these two rows; keep grid size unchanged.
    int temp_X = X_pos[row_1];
    int temp_O = O_pos[row_1];

    X_pos[row_1] = X_pos[row_2];
    X_pos[row_2] = temp_X;
    O_pos[row_1] = O_pos[row_2];
    O_pos[row_2] = temp_O;
        
  } else {
    std::cout << "unable to commute" << endl;
  }

  return;
}
