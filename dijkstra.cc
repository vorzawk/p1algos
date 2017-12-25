#include <iostream>
#include "maxBW.h"
#include "maxHeap.h"
using namespace std;

const int INF = 1e9;
/* A status value of UNSEEN means that the vertex has not been uncovered yet, FRINGE means that a path exists but it is
 * not necessarily the max BW path. IN_TREE means that the maximum bandwidth path from s to the vertex has been found*/
const int UNSEEN = 0;
const int FRINGE = 1;
const int IN_TREE = 2;
/* Function to find the shortest path from s to t in graph G*/
int dijkstra(vector< vector<node> > G, int s, int t) {
    int n = G.size(); // n is the number of vertices in the graph
    heap fringeHeap(n);
    vector<int> status(n,UNSEEN), bw(n,0), prev(n,-1);
    status[s] = IN_TREE;
    bw[s] = INF;
    for (vector<node>::iterator i = G[s].begin(); i!=G[s].end(); i++) {
        int w = i-> vertex;
        prev[w] = s;
        bw[w] = i-> edgeWeight;
        status[w] = FRINGE;
        fringeHeap.insert(fringeNode(w, bw[w]));
    }

/* At evry iteration, the algorithm adds the FRINGE vertex having the highest bandwidth into the tree. It can be proved that
 * once a vertex is added into the tree, the bw value is maximum */
    while (status[t] != IN_TREE) { // Continue till t is added to the tree
        /* Find the fringe vertex with maximum bandwidth */
        if (!fringeHeap.empty()) { // If no path exists from s->t, then the fringe set is emptied before t is added to the tree
            fringeNode maxBWfringe = fringeHeap.maxVal();
            fringeHeap.del(0);

        /* Add the vertex into the tree and update the status of the newly uncovered FRINGE vertices*/
            int v = maxBWfringe.vertex;
            status[v] = IN_TREE;
            for (auto i = G[v].begin(); i != G[v].end(); ++i) {
                int w = i-> vertex;
                int edgeWt = i-> edgeWeight;
                if (status[w] == UNSEEN) {
                    prev[w] = v;
                    bw[w] = min(bw[v], edgeWt);
                    status[w] = FRINGE;
                    fringeHeap.insert(fringeNode(w, bw[w]));

                    /* If the newly uncovered path has a higher BW, then update the BW value and the path from s*/
                } else if ((status[w] == FRINGE) && (bw[w] < min(bw[v], edgeWt))) {
                    int fringePos = fringeHeap.get_vertexLoc(w);
                    fringeHeap.del(fringePos);
                    prev[w] = v;
                    bw[w] = min(bw[v], edgeWt);
                    fringeHeap.insert(fringeNode(w, bw[w]));
                }
            }
        } else {
            return 0; // No path from s to t
        }
    }

    cout << "2) dijkstra using Heap\n";
    printPath(prev, t);
    cout << endl;
    return bw[t]; // Shortest path found
}
