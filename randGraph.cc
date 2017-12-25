#include "randGraph.h"
#include <stdlib.h>

const int BW_LIMIT = 100;
void randGraphSparse(vector<vector<int> >& G, int n, int m) {
    vector<int> degree(n,0);
    /* Using iterators here would make things complicated since rand() returns an integer */
    for (int i=n-1; i>0; i--) {
        int j;
        while (degree[i] < m) { // So, that the degree is m when the while loop terminates
            j = rand() % i;
            G[i][j] = rand() % BW_LIMIT + 1;
            G[j][i] = G[i][j];
            degree[i]++;
            degree[j]++;
        }
    }
}

void randGraphDense(vector<vector<int> >& G, int n, int p) {
    vector<int> degree(n,0);
    /* Using iterators here would make things complicated since the jth index starts from i */
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (((rand()%100) < p) && (i != j)) {
                G[i][j] = rand() % BW_LIMIT + 1;
                G[j][i] = G[i][j];
                degree[i]++;
                degree[j]++;
            }
        }
    }
}

void fixGraph(vector<vector<int> >& G, int s, int t) {
    int n = G.size();
    int v1 = s;
    for (int i=0; i<n; ++i) {
        if ((i!=s)&&(i!=t)) {
            G[v1][i] = rand() % BW_LIMIT + 1;
            G[i][v1] = G[v1][i];
            // Bug, if the above stmt is not added, the resulting graph is directed and Kruskal's algo fails 
            v1 = i;
        }
    }
    G[v1][t] = rand() % BW_LIMIT + 1;
    G[t][v1] =G[v1][t];
}

void convGraphRep(vector< vector<int> >& matG, vector<vector<node> >& vectorG) {
    vector< vector<node> >::iterator l = vectorG.begin();
    for (vector< vector<int> >::iterator i = matG.begin(); i!=matG.end(); i++) {
        for (vector<int> ::iterator j = i->begin(); j!=i->end(); j++) {
            int vertex=0;
            if (*j!=0) {
                vertex = j - i->begin();
                node edge(vertex, *j);
                l->push_back(edge);
            }
        }
        l++;
    }
}

