#ifndef RANDGRAPH_H_INCLUDED
#define RANDGRAPH_H_INCLUDED

#include "graph.h"
#include <vector>
using std::vector;

void randGraphSparse(vector< vector<int> >& G, int n, int m);
void randGraphDense(vector< vector<int> >& G, int n, int p);
void fixGraph(vector<vector<int> >& G, int s, int t); 
void convGraphRep(vector< vector<int> >& matG, vector< vector<node> >& vectorG);

#endif
