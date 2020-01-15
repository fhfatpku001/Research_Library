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
#pragma once

#include "grid_diagram.h"
#include "classic_invariants.h"
#include "vector_related_tools.h"
#include "grid_move.h"
#include "grid_state.h"
#include "heegaard_floer.h"

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


//#include "grid_CFK_generator.h"

using namespace std;
using namespace gridhomology::griddiagram;
using namespace gridhomology::classicinvariants;
using namespace gridhomology::gridmoves;
using namespace gridhomology::gridstate;
using namespace gridhomology::tools;
using namespace gridhomology::heegardfloer;

namespace gridhomology {
namespace sample {

//@brief Given Grid diagram size n,
//find the probablity of "such a grid diagram represent a knot";
double GetProbabilityOfKnotInGridDiagram (const int& n);  
  
}  // namespace sample;
}  // namespace gridhomology;
