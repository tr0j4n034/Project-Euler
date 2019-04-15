//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/14/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 10000005;
const int MODULO = 1000000;
const int N = 1000000 - 1;
const int ID = 524287;

int s[MAX];
int parent[MAX], size[MAX];

int getParent(int a) {
    return a == parent[a] ? a : parent[a] = getParent(parent[a]);
}
bool Union(int a, int b) {
    int root1 = getParent(a);
    int root2 = getParent(b);
    if (root1 == root2) return false;
    if (size[root1] < size[root2]) {
        swap(root1, root2);
    }
    size[root1] += size[root2];
    parent[root2] = root1;
    return true;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        if (i <= 55) {
            s[i] = (100003 - 200003LL * i % MODULO
                    + 300007LL * i % MODULO * i % MODULO * i % MODULO + MODULO * 10) % MODULO;
        }
        else {
            s[i] = (s[i - 24] + s[i - 55]) % MODULO;
        }
    }
    for (int i = 0; i <= N; i ++) {
        size[i] = 1;
        parent[i] = i;
    }
    int dials = 0;
    for (int i = 1; i + 1 < MAX; i += 2) {
        int a = s[i];
        int b = s[i + 1];
        if (i < 6) {
            cout << "a, b = " << a << " " << b << endl;
        }
        if (a == b) continue;
        dials ++;
        Union(a, b);
        if (size[getParent(ID)] >= (N + 1) / 100 * 99) {
            cout << dials << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    cout << size[ID] << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
