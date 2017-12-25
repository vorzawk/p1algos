#include "graph.h"
#include "maxBW.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void heapSort (priority_queue<edge>& h, vector<edge>& vecEdges) {
    while(!h.empty()) {
        vecEdges.push_back(h.top());
        h.pop();
    }
}

int Find(const vector<int>& D, int v) {
    int w = v;
    while( D[w] != -1) {
        w = D[w];
    }
    return w;
}

void Union(vector<int>& D, vector<int>& rank, int r1, int r2) {
    if (rank[r1] > rank[r2]) {
        D[r2] = r1;
    } else if (rank[r2] > rank[r1]) {
        D[r1] = r2;
    } else {
        D[r2] = r1;
        rank[r1]++;
    }
}

void dfs(const vector< vector<node> >& G, int s, int t, vector<node>& path) {
    /* dfs(s) ensures that all veretices reachable from s are processed before s. So, if t is reachable from s, then t
     * is processed earlier. Also, since there are no cycles, there is exactly one unique path from s->t. So, any vertex
     * is either on that path or not. Any vertex reachable from s but not in the s->t path is either not visited or is
     * processed before t. In the first case, the vertex will be added to the path. In the second case, the vertex,
     * v(say) and all vertices reachable from v will be processed before t (t is not reachable from v). So, the s->t
     * path is given by the vertices being processed when t is uncovered */
    enum color { black, white, gray };
    int n = G.size();
    static vector<color> status(n,white);
    static bool pathFound = false;
    if(s!=t) { // Bug found while testing, pathFound is never set!
        status[s] = gray;
        for(auto i=G[s].begin(); i!=G[s].end(); ++i) {
            if (status[i->vertex] == white) {
                path.push_back(*i);
                dfs(G, i->vertex, t, path);
                if (pathFound) {
                    return;
                }
            }
        }
        status[s] = black;
        if (!path.empty()) {
            path.pop_back();
        }
    } else {
        pathFound = true;
    }
}

int kruskal(vector< vector<node> > G, int s, int t) {
    /* Sort the edges in decreasing order using heap sort */
    /* Read all edges into a vector first*/
    int n = G.size();
    priority_queue<edge> heapEdges;
    vector<edge> vecEdges;
    int firstVertex = 0;
    for (auto i=G.begin(); i!=G.end(); ++i) {
        for (auto j=i->begin(); j!=i->end(); ++j) {
            int secondVertex = j->vertex;
            if (firstVertex < secondVertex) { // Ensures that every edge is added only once
                heapEdges.push(edge(firstVertex, secondVertex, j->edgeWeight));
            }
        }
        firstVertex++;
    }
    heapSort(heapEdges, vecEdges);

    /* Create a new graph consisting only of the Maximum Spanning Tree of G and find the path from s->t using DFS. It
     * can be proved that the path from s->t in the MST is the maximum BW path*/
     vector< vector<node> > mstG(n);

    /* MakeSet */
    vector<int> D(n,-1), rank(n,0);

    for (auto i=vecEdges.begin(); i!=vecEdges.end(); ++i) {
        int r1, r2, v1, v2;
        v1 = i->firstVertex;
        v2 = i->secondVertex;

        r1 = Find(D, v1);
        r2 = Find(D, v2);
        if (r1 != r2) {
            mstG[v1].push_back(node(v2, i->bandwidth));
            mstG[v2].push_back(node(v1, i->bandwidth));
            // Bug found during testing, without the above stmt, the mst is a directed graph
            Union(D, rank, r1, r2);
        }
    }

    vector<node> path;
    clock_t start;
    double duration;
    start = clock();
    dfs(mstG, s, t, path);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
    if (!path.empty()) {
        cout << "3) Kruskal\n" << s; 
        int bw = 1e9;
        for (auto i=path.begin(); i!=path.end(); ++i) {
            cout << "->" << i->vertex;
            bw = min(bw, i->edgeWeight);
        }
        cout << endl;
        cout << "Time taken by dfs in Kruskal = " << duration << 's' << endl;
        return bw;
    } else {
        return 0;
    }
}

