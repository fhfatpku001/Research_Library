# Introduction

This is a C++ Library for grid homology. Grid homology is a variation of [Heegaard Floer homology](https://en.wikipedia.org/wiki/Floer_homology). It is a novel invariant for [Knots and Links](https://en.wikipedia.org/wiki/Knot).

Here is a picture of knot (Trefoil):

![trefoil](https://github.com/fhfatpku001/Research_Library/blob/master/Trefoil.svg "Trefoil A strongly invertible knot")

One can show that, all knots and links in 3-dimensional space R^3 or S^3 can be represented by a grid diagram (actually a grid diagram for torus):
```
.___.___.___.___.___.
| X |   |   | O |   |
.___.___.___.___.___.
|   | X |   |   | O |
.___.___.___.___.___.
| O |   | X |   |   |
.___.___.___.___.___.
|   | O |   | X |   |
.___.___.___.___.___.
|   |   | O |   | X |
.___.___.___.___.___.
```

Here we connect X to O in each row, and O to X in each column.

The shape change of knots and links can be represented by a movie of grid, which we can decompose into grid move:

For example: Let G be a grid diagram;
```
G->PrintGridDiagram():

.___.___.___.___.___.
| X |   |   | O |   |
.___.___.___.___.___.
|   | X | O |   |   |
.___.___.___.___.___.
|   | O | X |   |   |
.___.___.___.___.___.
|   |   |   | X | O | <----
.___.___.___.___.___.       Switch the two row;
| O |   |   |   | X | <----        |
.___.___.___.___.___.              |
                                   |
DoHorizontalCommutation(G, 3);     |
G->PrintGridDiagram();             |
.___.___.___.___.___.              |
| X |   |   | O |   |              |
.___.___.___.___.___.              |
|   | X | O |   |   |              |
.___.___.___.___.___.              |
|   | O | X |   |   | <------------|
.___.___.___.___.___.              |
| O |   |   |   | X |              |
.___.___.___.___.___.              |
|   |   |   | X | O |              |Do A cyclic Permutation
.___.___.___.___.___.              |
                                   |
DoHorizontalCyclicPermutation(G);  |
G->PrintGridDiagram();             |
.___.___.___.___.___.              |
|   | X | O |   |   |              |
.___.___.___.___.___.              |
|   | O | X |   |   |  <----------- ;
.___.___.___.___.___.
| O |   |   |   | X |
.___.___.___.___.___.
|   |   |   | X | O |
.___.___.___.___.___.
| X |   |   | O |   |
.___.___.___.___.___.
```
					
From a grid diagram of knot and links, we can calculate many topological invariants.

For example:
Classic Topological Invariant:
1. Link Components; (Number of connected components in a link)
2. Self-linking number (Seifert Matrix);
3. Alexander Polynomial;
...

Novel Heegaard Floer (grid homology) Invariant;
1. Hat Version Heegaard Floer homology; 
2. Tau Invariant, Upsilon invariant, ...;
3. Alexander Polynomial can also be derived from grid homology;
...

Those invariants from grid homology are pretty useful not only in Geometry/Topology, but also in real World:

For example, 
"Recent work, for example, has applied Floer homology to determine how various enzymes in the body alter the knottedness of DNA. Understanding these mechanisms is important for developing certain drugs." --- http://grantome.com/grant/NSF/DMS-1251064

Although Floer homology is pretty powerful and useful, unfortunately, not all variations of Floer homology are easy to calculate. See https://arxiv.org/pdf/1401.7107.pdf for an introduction. By Manolescu-Ozsvath-Sarkar and many other mathematician's hard work, grid homology was introduced. All most invariants of Heegaard Floer homology can be calculated by hand or by "A computer program"; See this article in Annals of Mathematics (A combinatorial description of knot Floer homology) by Manolescu, Ozsvath and Sarkar. In Page 657, they provided two examples of the calculation.

# Features:

1. grid_diagram.h, grid_state.h:
Construct a grid diagram class and related grid state class;

Example:
```
vector<int> x_points_positions = {0,1,2,3,4};
vector<int> o_points_positions = {3,2,1,4,0};
GridDiagram* grid_diagram= new GridDiagram(x_points_positions, o_points_positions);
grid_diagram->PrintGridDiagram();


Output:
.___.___.___.___.___.
| X |   |   | O |   |
.___.___.___.___.___.
|   | X | O |   |   |
.___.___.___.___.___.
|   | O | X |   |   |
.___.___.___.___.___.
|   |   |   | X | O |
.___.___.___.___.___.
| O |   |   |   | X |
.___.___.___.___.___.
```

2. classic_invariants.h: Calculate classic link invariants; 

Example: Number of Link Components in a grid diagram:

```
cout << GetNumOfLinkComponents(*G) << endl
```

Output: 2;

3. grid_move.h: contains elementary moves of a grid diagram, i.e. these elementary moves change a grid to another grid;

From grid diagram:
```
.___.___.___.___.___.
| X |   |   | O |   |
.___.___.___.___.___.
|   | X | O |   |   |
.___.___.___.___.___.
|   | O | X |   |   |
.___.___.___.___.___.
|   |   |   | X | O |
.___.___.___.___.___.
| O |   |   |   | X |
.___.___.___.___.___.
```
After
```
 DoHorizontalCommutation(grid_diagram, 3);

.___.___.___.___.___.
| X |   |   | O |   |
.___.___.___.___.___.
|   | X | O |   |   |
.___.___.___.___.___.
|   | O | X |   |   |
.___.___.___.___.___.
| O |   |   |   | X |
.___.___.___.___.___.
|   |   |   | X | O |
.___.___.___.___.___.
```
4. heegaard_floer.h: contains all functions (to calculate certain Heegaard Floer invariants) related to Heegaar Floer homology:

```
{
  vector<GridState> all_states = GetAllGridState(*grid_diagram);

  for (const auto& it : all_states) {
    it.PrintGridState();
    cout << GetXMaslovGrading(*grid_diagram, it) << " " << GetOMaslovGrading(*grid_diagram, it) << " " << GetReducedAlexanderGrading(*grid_diagram, it) << endl;
   }
}
```

5. sample_functions.h: contains some sample applications of functions inside a library.

For example:

Consider the questions: What is the possibility for "a grid diagram represents a knot?"

```
GetProbabilityOfKnotInGridDiagram (6); 

output: 0.166667
```
