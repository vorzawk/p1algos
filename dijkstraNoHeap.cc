#include <iostream>
#include "maxBW.h"
#include <algorithm>
using namespace std;

const int INF = 1e9;
/* A status value of UNSEEN means that the vertex has not been uncovered yet, FRINGE means that a path exists but it is
 * not necessarily the max BW path. IN_TREE means that the maximum bandwidth path from s to the vertex has been found*/
const int UNSEEN = 0;
const int FRINGE = 1;
const int IN_TREE = 2;
/* Function to find the shortest path from s to t in graph G*/
int dijkstraNoHeap(vector< vector<node> > G, int s, int t) {
    int n = G.size(); // n is the number of vertices in the graph
    vector<int> status(n,UNSEEN), bw(n,0), prev(n,-1);
    status[s] = IN_TREE;
    bw[s] = INF;
    for (vector<node>::iterator i = G[s].begin(); i!=G[s].end(); i++) {
        int w = i-> vertex;
        prev[w] = s;
        bw[w] = i-> edgeWeight;
        status[w] = FRINGE;
    }

/* At evry iteration, the algorithm adds the FRINGE vertex having the highest bandwidth into the tree. It can be proved that
 * once a vertex is added into the tree, the bw value is maximum */
    while (status[t] != IN_TREE) { // Presence of a pth from s to t is ensured in the test cases
        /* Find the fringe vertex with maximum bandwidth */
        int maxBW = -1;
        int maxBWVertex = -1;
        for (int i = 0; i < n; i++) {
            if((status[i] == FRINGE) && (maxBW < bw[i])){
                maxBW = bw[i];
                maxBWVertex = i;
            }
        }
        
        /* Add the vertex into the tree and update the status of the newly uncovered FRINGE vertices*/
        if (maxBWVertex != -1) {
            int v = maxBWVertex;
            status[v] = IN_TREE;
            for (auto i = G[v].begin(); i != G[v].end(); ++i) {
                int w = i-> vertex;
                int edgeWt = i-> edgeWeight;
                if (status[w] == UNSEEN) {
                    prev[w] = v;
                    bw[w] = min(bw[v], edgeWt);
                    status[w] = FRINGE;
                    /* If the newly uncovered path has a higher BW, then update the BW value and the path from s*/
                } else if ((status[w] == FRINGE) && (bw[w] < min(bw[v], edgeWt))) {
                    prev[w] = v;
                    bw[w] = min(bw[v], edgeWt);
                }
            }
        } else {
            return 0; // No path from s to t
        }
    }
    cout << "1) dijkstra without Heap\n";
    printPath(prev, t);
    cout << endl;
    return bw[t]; // Shortest path found
}
