#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <vector>
using std::vector;

class fringeNode {
    public:
    int vertex;
    int bandwidth;
    fringeNode(int v, int bw):vertex(v), bandwidth(bw) {}
    friend bool operator< (const fringeNode& a, const fringeNode& b) {
        return (a.bandwidth < b.bandwidth);
    }
    friend bool operator> (const fringeNode& a, const fringeNode& b) {
        return (a.bandwidth > b.bandwidth);
    }

};

class heap {
    private:
    vector<fringeNode> H;
    vector<int> vertexLoc;
    void swap(int i, int j);
    void siftUp(int i);
    void siftDown(int i);
    public:
    heap(int n): vertexLoc(n,-1) {}
    fringeNode maxVal();
    bool empty();
    int get_vertexLoc(int vertex);
    void insert(fringeNode a);
    void del(int h);
};
#endif

