#ifndef MAXBW_H_INCLUDED
#define MAXBW_H_INCLUDED

#include "graph.h"
#include <vector>
using std::vector;

int dijkstraNoHeap(vector< vector<node> > G, int s, int t);
int dijkstra(vector< vector<node> > G, int s, int t);
int kruskal(vector< vector<node> > G, int s, int t);
void printPath(vector<int>& prev, int t);

#endif
