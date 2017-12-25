#include "maxHeap.h"
#include <iostream>
#include <assert.h>
using namespace std;

/* The heap stores the elements in the form of an array, so H[0] is the largest element.*/
/* For the elment at index i, the parent has an index, (i-1)/2(int divsion) and index of the left child is 2i+1 while index of
 * the right child is 2i++2 */

void heap::swap (int i, int j) {
    vertexLoc[H[i].vertex] = j;
    vertexLoc[H[j].vertex] = i;
    fringeNode temp = H[i];
    H[i] = H[j];
    H[j] = temp;
}

void heap::siftUp(int i) {
    /* Compare the value with its parent, swap if larger */
    while ((i > 0) && (H[i] > H[(i-1)/2])) {
        swap((i-1)/2, i);
        i = (i-1)/2;
    }
}

void heap::siftDown(int i) {
    /* If parent is not the larger than its children, swap with the larger child */
    int maxIndex, l, r;
    maxIndex = i;

    l = 2*i + 1;
    if ((l < H.size()) && (H[l] > H[maxIndex])) {
        maxIndex = l;
    }

    r = 2*i + 2;
    if ((r < H.size()) && (H[r] > H[maxIndex])) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        swap(i, maxIndex);
        siftDown(maxIndex);
    }
}

fringeNode heap::maxVal() {
    /*Return the maximum element (0th index)*/
    return H.front();
}

bool heap::empty() {
    return (H.size() == 0);
}

int heap::get_vertexLoc(int vertex) {
    return vertexLoc[vertex];
}

void heap::insert(fringeNode a) {
    H.push_back(a);
    vertexLoc[a.vertex] = H.size() - 1;
    siftUp(H.size() - 1);
}

void heap::del(int h) {
    if ((h<0)||(h>=H.size())) {
        cout << "out of bounds, h= " << h << endl;
        assert((h>0)&&(h<H.size()));
    }
    int v = H[h].vertex;
    vertexLoc[v] = -1;
    H[h] = H.back();
    vertexLoc[ H[h].vertex ] = h;
    H.pop_back();
    siftDown(h);
}
