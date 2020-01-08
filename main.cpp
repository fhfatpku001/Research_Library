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

int main()
{
  vector<int> v1 = {1,2,3,0};
  vector<int> v2 = {3,0,2,1};
  grid* G = new grid(v1, v2, 4);

  G->print_grid();

  HF* Heegaard = new HF();

  vector<grid_generator*> result = Heegaard->all_generators(G);

  for (int i = 0; i < result.size(); ++i) {
    result[i]->print_gen_vec();
  }

  
  
 /*
  cout << G->num_link_components() << endl;

  if (G->is_knot()) {
    cout << "is knot" << endl;
  } else {
    cout << " Not knot" << endl;
  }


  
 
  vector<int> v3 = {0,3,4,5,2,1};

  grid_generator* gen = new grid_generator(v3, 6);

  gen->print_gen();
  */

  
  
  return 0;
}

















