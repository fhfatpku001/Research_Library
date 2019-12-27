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
  vector<int> v1 = {1,2,3,4,0};
  vector<int> v2 = {3,4,0,2,1};
  grid* G = new grid(v1, v2, 5);

  G->print_grid();

  cout << G->num_link_components() << endl;

  if (G->is_knot()) {
    cout << "is knot" << endl;
  } else {
    cout << " Not knot" << endl;
  }
  
  return 0;
}

















