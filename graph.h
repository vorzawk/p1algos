/* graph.h file includes the class definition for a node in the adjaency list representation */
/* Include Guard to avoid the same file from getting inluded twice. this is becasue include is a copy operation and
 * including a header twice will result in double declarations, definitions and stuff*/
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class node {// stl pair could have been used instead
    public:
    int vertex;
    int edgeWeight;
    node(int v, int e): vertex(v), edgeWeight(e) {}
};

class edge {
    public:
    int firstVertex;
    int secondVertex;
    int bandwidth;
    edge(int v1, int v2, int bw): firstVertex(v1), secondVertex(v2), bandwidth(bw) {}
    friend bool operator< (const edge& a, const edge& b) {
        return (a.bandwidth < b.bandwidth);
    }
    friend bool operator> (const edge& a, const edge& b) {
        return (a.bandwidth > b.bandwidth);
    }

};

#endif
