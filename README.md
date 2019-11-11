## Network Routing Protocol to find the Maximum Bandwidth path between any two nodes

### Introduction:
Dijkstra’s Shortest Path and Kruskal’s MST algorithms are well known and extensively studied. In this project, the algorithms are used to implement a network routing protocol which finds the maximum Bandwidth path between any 2 nodes in the network. The algorithms studied in class are implemented in C++ resulting in a deeper understanding of the concepts.

### Implementation:
The graphs are implemented using C++ STL as a vector of vectors. First, a random graph is generated in the Adjacency Matrix form and then converted to the Adjacency list form to allow constant time access to neighbouring vertices. The performance of the algorithms on these graphs is analyzed.

### Dijkstra’s Shortest Path Algorithm
The algorithm uses a greedy approach to find the maximum bandwidth path. At every iteration, the fringe node with the highest bandwidth is added to the tree.

### Array Implementation
An array is used to store the best known bandwidth to any given node from s. At every iteration, selecting the fringe node with max bandwidth can be done in O(n) time where n is the number of vertices in the graph. So, each vertex changes from fringe → in_tree in O(n) time and since we have n vertices, this takes O(n2) time considering the entire execution. Every edge is considered at most twice, followed by an O(1) operation to update the status and bandwidth of the vertices. Considering the entire execution, this takes O(m) time where m is the number of edges in the graph. Since m = O(n2), the entire algorithm requires O(n2).

### Using a Heap to store fringes
At every iteration, we need to extract the fringe node with the highest bandwidth. This can be done in O(log n) time using a heap. So, each vertex changes from fringe → in_tree in O(log n) time and considering the entire execution, this takes O(nlog n) time. Every edge is considered at most twice, followed by O(log n) insertion and deletion operations to update the status and bandwidth of the vertices. Considering the entire execution, this takes O(mlog n) time.
So, the entire algorithm requires O((m+n)log n) time.

### Kruskal’s Algorithm
We first find the MST( Maximum Spanning Tree) for the entire graph and then use DFS to find a path from s to t in the MST. It can be proved that the path from s to t in the MST is also the maximum Bandwidth Path.
The algorithm first sorts all the edges in decreasing order using heap sort which requires O(mlogm) time. For every edge, the algorithm checks if the edge connects 2 different “pieces” and adds the edge to the MST if it does. So, for every edge, we require at most 2 find operations and 1 union operation each of which require log n time. Considering all edges, this step can be done in O(mlog n) time. So, we require O(mlog n) time to find the MST since log m = O(log n).
Then, finding the path from s to t takes O(m+n) time using DFS.
