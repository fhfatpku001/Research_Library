#include "grid_move_functions.h"

using namespace std;
using namespace griddiagramnamespace;


void gridmoves::DoHorizontalCommutation(GridDiagram *grid_diagram, const int &row) {
  if (!grid_diagram->IsValidGrid()) {
    cout << "invalid grid diagram" << endl;
    return;
  }

  int grid_diagram_size = grid_diagram->GetGridSize();
  int next_row = (row + 1) % grid_diagram_size;

  if (row < 0 || row >= grid_diagram_size) {
    cout << "invalide row number" << endl;
    return;
  }
    
    return;
}  

void gridmoves::DoVerticalCommutation(GridDiagram *grid_diagram, const int &col) {
  return;
}

void gridmoves::DoHorizontalCyclicPermutation(GridDiagram *grid_diagram) {
  return;
}

void gridmoves::DoVerticalCyclicPermutation(GridDiagram *grid_diagram) {
  return;
}

