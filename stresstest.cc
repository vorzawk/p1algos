#include "randGraph.h"
#include "graph.h"
#include "maxBW.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n,m, bw1, bw2,i=0;
    cout << "Enter the number of vertices and the desired degree(sparse graph) or probability(dense graph)" << endl;
    //   cin >> n >> m;
    while(i<200) {
        n = rand()%10+1;
        m = rand()%10+20;
        cout << "n= " <<n << " m= " << m << endl;
        vector< vector<node> > G(n);
        //    randGraphSparse(G, n, m);
        randGraphDense(G, n, m);
        bw1 = dijkstraNoHeap(G, 0, n-1);

        bw2 = dijkstra(G, 0, n-1);
        i++;
    }
    cout << "Bandwidth from no heap impl: " << bw1 << ", heap impl: " << bw2 << endl;
    return 0;
}



