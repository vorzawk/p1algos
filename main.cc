#include "randGraph.h"
#include "graph.h"
#include "maxBW.h"
#include <iostream>
#include <ctime>
using namespace std;

void analyze(vector< vector<node> >G, int s, int t) {
    int bw1, bw2, bw3;

    cout << "Maximum BW paths\n";
    clock_t start;
    double duration;
    start = clock();
    bw1 = dijkstraNoHeap(G, s, t);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
    cout << "Time taken = " << duration << 's' << endl;
    start = clock();
    bw2 = dijkstra(G, s, t);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
    cout << "Time taken = " << duration << 's' << endl;
    start = clock();
    bw3 = kruskal(G, s, t);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
    cout << "Total Time taken = " << duration << 's' << endl;

    cout << "Bandwidths\nDijkstra without heap: " << bw1 << ", Dijkstra: " << bw2 << ", Kruskal: " << bw3 << "\n\n";
}

int main() {
    srand(time(NULL));
    int n,m,s,t;
    //    cout << "Enter the number of vertices and the desired degree(sparse graph) or probability(dense graph)" << endl;
    //    cin >> n >> m;
    n = 5000;
    vector< vector<int> > matG(n, vector<int> (n,0));
    vector< vector<node> > G(n);
#if 0 
    m = 6;
    randGraphSparse(matG, n, m);
#endif
#if 1 
    m = 20;
    randGraphDense(matG, n, m);
#endif
    s = rand() % n;
    t = rand() % n;
    fixGraph(matG, s, t);
    convGraphRep(matG, G);
    analyze(G, s, t);

    return 0;
}



