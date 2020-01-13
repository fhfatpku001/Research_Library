#include "grid_move.h"

using namespace std;
using namespace gridhomology::griddiagram;

namespace gridhomology{
namespace gridmoves{

void DoHorizontalCommutation(GridDiagram *grid_diagram, const int &row) {
  // Check Valid Grid before we do commutation;
  if (!grid_diagram->IsValidGrid()) {
    cout << "invalid grid diagram" << endl;
    return;
  }

  // Check Valid input row number before we do commutation;
  const size_t& grid_size = grid_diagram->GetGridSize();
  if (row < 0 || row >= grid_size) {
    cout << "invalid row number" << endl;
    return;
  }

  // When the [x/o, o/x] interval in row and next_row not intersect
  //or include one other commute the two row;
  const int next_row = (row + 1) % grid_size;
  const vector<int>& x_positions = grid_diagram->GetXPointsPositions();
  const vector<int>& o_positions = grid_diagram->GetOPointsPositions();
  const int left_boundary_of_row = min(x_positions[row], o_positions[row]);
  const int right_boundary_of_row = max(x_positions[row], o_positions[row]);
  const int left_boundary_of_next_row = min(x_positions[next_row], o_positions[next_row]);
  const int right_boundary_of_next_row = max(x_positions[next_row], o_positions[next_row]);
  vector<int> commuted_x_positions;
  vector<int> commuted_o_positions;
  if ((left_boundary_of_row <= left_boundary_of_next_row && right_boundary_of_row >= right_boundary_of_next_row) || (left_boundary_of_row >= left_boundary_of_next_row && right_boundary_of_row <= right_boundary_of_next_row) || (left_boundary_of_row >= right_boundary_of_next_row) || (right_boundary_of_row <= left_boundary_of_next_row)) {
    cout << "can commute" << endl;
    commuted_x_positions = x_positions;
    commuted_o_positions = o_positions;
    swap(commuted_x_positions[row], commuted_x_positions[next_row]);
    swap(commuted_o_positions[row], commuted_o_positions[next_row]);
    grid_diagram->SetXPointsPositions(commuted_x_positions);
    grid_diagram->SetOPointsPositions(commuted_o_positions);
  } else {
    cout << "can not commute" << endl;
  }
  return;
}  

void DoVerticalCommutation(GridDiagram *grid_diagram, const int &col) {
  // Check Valid Grid before we do commutation;
  if (!grid_diagram->IsValidGrid()) {
    cout << "invalid grid diagram" << endl;
    return;
  } 

  // Check Valid input column number before we do commutation;
  const size_t& grid_size = grid_diagram->GetGridSize();
  if (col < 0 || col >= grid_size) {
    cout << "invalid row number" << endl;
    return;
  }

  // Get the row number of the x, o points in col_1 = col and col_2 = col + 1;
  const int& col_1 = col;
  const int col_2 = (col + 1) % grid_size;
  const vector<int>& x_positions = grid_diagram->GetXPointsPositions();
  const vector<int>& o_positions = grid_diagram->GetOPointsPositions();
  int row_x_1, row_x_2, row_o_1, row_o_2;
  for (int i = 0; i < grid_size; ++i) {
    if (x_positions[i] == col_1) {
      row_x_1 = i;
    }
    if (o_positions[i] == col_1) {
      row_o_1 = i;
    }
    if (x_positions[i] == col_2) {
      row_x_2 = i;
    }
    if (o_positions[i] == col_2) {
      row_o_2 = i;
    }
  }

  // when x_1,o_1 inteval and x_2, o_2 interval does not intersect or
  // include one another, do vertical commutation;
  const int upper_boundary_col_1 = max(row_x_1, row_o_1);
  const int lower_boundary_col_1 = min(row_x_1, row_o_1);
  const int upper_boundary_col_2 = max(row_x_2, row_o_2);
  const int lower_boundary_col_2 = min(row_x_2, row_o_2);
  if ((upper_boundary_col_1 >= upper_boundary_col_2 && lower_boundary_col_1 <= lower_boundary_col_2) || (upper_boundary_col_1 <= upper_boundary_col_2 && lower_boundary_col_1 >= lower_boundary_col_2) || (upper_boundary_col_1 <= lower_boundary_col_2) || (upper_boundary_col_2 <= lower_boundary_col_1)) {
    std::cout << "can commute" << endl;
    // swap these two cols; keep grid size unchanged.
    vector<int> commuted_x_positions = grid_diagram->GetXPointsPositions();
    vector<int> commuted_o_positions = grid_diagram->GetOPointsPositions();
    commuted_x_positions[row_x_1] = col_2;
    commuted_x_positions[row_x_2] = col_1;
    commuted_o_positions[row_o_1] = col_2;
    commuted_o_positions[row_o_2] = col_1;
    grid_diagram->SetXPointsPositions(commuted_x_positions);
    grid_diagram->SetOPointsPositions(commuted_o_positions);
  } else {
    cout << "unable to commute" << endl;
  }
  return;
}

void DoHorizontalCyclicPermutation(GridDiagram *grid_diagram) {
  // Check Valid Grid before we do cyclic permutation;
  if (!grid_diagram->IsValidGrid()) {
    cout << "invalid grid diagram" << endl;
    return;
  }

  // Do cyclic permutation for both x and o points;
  vector<int> cyclic_permuted_x_positions = grid_diagram->GetXPointsPositions();
  vector<int> cyclic_permuted_o_positions = grid_diagram->GetOPointsPositions();
  const int end_point_x_position = cyclic_permuted_x_positions[0];
  const int end_point_o_position = cyclic_permuted_o_positions[0];
  for (size_t i = 0; i + 1 < grid_diagram->GetGridSize(); ++i) {
    cyclic_permuted_x_positions[i] = cyclic_permuted_x_positions[i + 1];
    cyclic_permuted_o_positions[i] = cyclic_permuted_o_positions[i + 1];
  }
  cyclic_permuted_x_positions.back() = end_point_x_position;
  cyclic_permuted_o_positions.back() = end_point_o_position;
  grid_diagram->SetXPointsPositions(cyclic_permuted_x_positions);
  grid_diagram->SetOPointsPositions(cyclic_permuted_o_positions);
  return;
}

void DoVerticalCyclicPermutation(GridDiagram *grid_diagram) {
  // Check Valid Grid before we do cyclic permutation;
  if (!grid_diagram->IsValidGrid()) {
    cout << "invalid grid diagram" << endl;
    return;
  }

  // all x and o point position + 1;
  vector<int> vertical_cyclic_permuted_x_positions = grid_diagram->GetXPointsPositions();
  vector<int> vertical_cyclic_permuted_o_positions = grid_diagram->GetOPointsPositions();
  const size_t grid_size = grid_diagram->GetGridSize();
  for (size_t i = 0; i < grid_size; ++i) {
    vertical_cyclic_permuted_o_positions[i] = (vertical_cyclic_permuted_o_positions[i] + 1) % grid_size;
    vertical_cyclic_permuted_x_positions[i] = (vertical_cyclic_permuted_x_positions[i] + 1) % grid_size;
  }
  grid_diagram->SetXPointsPositions(vertical_cyclic_permuted_x_positions);
  grid_diagram->SetOPointsPositions(vertical_cyclic_permuted_o_positions);
  return;
}

}  // namespace gridmoves 
}  // namespace gridhomology

