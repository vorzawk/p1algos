#include "maxBW.h"
#include <iostream>
using namespace std;

void printPath(vector<int>& prev, int t) {
    if(prev[t] == -1) {
        cout << t;
        return;
    }
    else {
        printPath(prev, prev[t]);
    }
    cout << "->" << t ;
    return;
}

