/******************************************************************************
Copyright (c) 2020 Haofei Fan (fhfatpku001@gmail.com)

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
 *****************************************************************************/

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

#include "grid_diagram.h"
#include "classic_invariants.h"
#include "vector_related_tools.h"
#include "grid_move.h"
#include "grid_state.h"
#include "heegaard_floer.h"
#include "sample_functions.h"
//#include "grid_CFK_generator.h"

using namespace std;
using namespace gridhomology::griddiagram;
using namespace gridhomology::classicinvariants;
using namespace gridhomology::gridmoves;
using namespace gridhomology::gridstate;
using namespace gridhomology::tools;
using namespace gridhomology::heegardfloer;

int main()
{
  vector<int> x_pos = {0,1,2,3,4};
  vector<int> o_pos = {3,2,1,4,0};
  GridDiagram* G = new GridDiagram(x_pos, o_pos);

  G->PrintGridDiagram();

  cout << GetNumOfLinkComponents(*G) << endl;
    
  DoHorizontalCommutation(G, 3);
					
  G->PrintGridDiagram();

  DoHorizontalCyclicPermutation(G);

  G->PrintGridDiagram();

  //DoVerticalCyclicPermutation(G);
					
  //G->PrintGridDiagram();

  //GridState* grid_state = new GridState(x_pos);
  //grid_state->PrintGridState();
  //PrintTwoDimensionalVector(GetAllPermutation(0, 3));
  /*
  vector<int> v = {1,2,3,0,4};
  
  vector<GridState> all_states = GetAllGridState(*G);

  for (auto it : all_states) {
    it.PrintGridState();
    cout << GetXMaslovGrading(*G, it) << " " << GetOMaslovGrading(*G, it) << " " << GetReducedAlexanderGrading(*G, it) << endl;
    }*/

  cout << gridhomology::sample::GetProbabilityOfKnotInGridDiagram(6) << "\n";
  
  return 0;
}
