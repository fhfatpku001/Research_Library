/*Content: This file contains the definitions related to the grid diagram changes, i.e. grid moves. commutations, and stablizations*/

#include "grid.h"

/*
grid::h_com(const int &row_1)-input: void;
grid::h_com(const int &row_1)-output: void, commutations of row_1 and row_1 + 1;
grid::h_com(const int &row_1).param: (a,b) - the interval in row_1, (c,d) the interval of row_1 + 1;
*/

void grid::h_com(const int &row_1) {
  if (!is_valid) {
    std::cout << "invalid grid" << endl;
    return;
  }
  
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

/*
grid::h_cyc()-input: void;
grid::h_cyc()-output: void, cyclic permute rows;
@grid::h_cyc().param: X_pos_end, O_pos_end, store the last X, O positions;
*/

void grid::h_cyc(void) {
  if (!is_valid) {
    return;
  }
  
  // permute X_pos, keep grid size unchanged;
  int X_pos_end = X_pos[0];

  for (size_t i = 0; i + 1 < X_pos.size(); ++i) {
    X_pos[i] = X_pos[i + 1];
  }

  X_pos.back() = X_pos_end;

  // Permute O_pos;
  int O_pos_end = O_pos[0];

  for (size_t i = 0; i + 1 < O_pos.size(); ++i) {
    O_pos[i] = O_pos[i + 1];
  }

  O_pos.back() = O_pos_end;

  return;
}

/*
grid::v_com(const int &col_1)-input: column number;
grid::v_com(const int &col_1)-output: void, try swap col1 and col1+1;
grid::v_com(const int &col_1).param: 
row_x_1, row_x_2, row_o_1, row_o_2- are coordinates of X_1, X_2, O_1 and O_2;
(b,a), (d,c) are the intervals need to compare. 
*/

void grid::v_com(const int &col_1) {
  if (!is_valid) {
    std::cout << "invalid grid" << endl;
    return;
  }
  
  int col_2 = (col_1 + 1) % grid_size;

  if (col_1 < 0 || col_1 >= grid_size || col_2 < 0 || col_2 >= grid_size) {
    std::cout << "invalid col numbers!" << endl;
    return;
  }
  
  // get the positions; (Remark, for sequences of moves, we can do it outside)
  int row_x_1, row_x_2, row_o_1, row_o_2;

  for (int i = 0; i < grid_size; ++i) {
    if (X_pos[i] == col_1) {
      row_x_1 = i;
    }
  }

  for (int i = 0; i < grid_size; ++i) {
    if (X_pos[i] == col_2) {
      row_x_2 = i;
    }
  }

  for (int i = 0; i < grid_size; ++i) {
    if (O_pos[i] == col_1) {
      row_o_1 = i;
    }
  }

  for (int i = 0; i < grid_size; ++i) {
    if (O_pos[i] == col_2) {
      row_o_2 = i;
    }
  }

  // now check if we can commute or not;

  int a = max(row_x_1, row_o_1);
  int b = min(row_x_1, row_o_1);
  int c = max(row_x_2, row_o_2);
  int d = min(row_x_2, row_o_2);

    // four cases such that (a, b)  and (c,d) anc commute.
  if ( (a <= c && b >= d) || (a >= c && b <= d) || a <= d || b >= c) {
    std::cout << "can commute" << endl;
    // swap these two cols; keep grid size unchanged.
    X_pos[row_x_1] = col_2;
    X_pos[row_x_2] = col_1;
    O_pos[row_o_1] = col_2;
    O_pos[row_o_2] = col_1;
        
  } else {
    std::cout << "unable to commute" << endl;
  }
  
}

/*
grid::v_cyc()-input: void;
grid::v_cyc()-output: void, col cyclic permutation;
*/

void grid::v_cyc(void) {
  if (!is_valid) {
    std::cout << "invalid grid" << endl;
    return;
  }
  
  // every X/O_pos[i] + 1 % grid_size;

  for (int i = 0; i < grid_size; ++i) {
    X_pos[i] = (X_pos[i] + 1) % grid_size;
    O_pos[i] = (O_pos[i] + 1) % grid_size;
  }

  return;
}
