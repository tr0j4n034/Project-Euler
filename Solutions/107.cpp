//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 105;

int N;
int parent[MAX];
vector<pair<int, pair<int, int> > > edges;

int Find(int x) {
    cout << "in x = " << x << endl;
    return x == parent[x] ? x : parent[x] = Find(parent[x]);
    cout << "out x = " << x << endl;
    return x;
}
bool Union(int x, int y) {
    int r1 = Find(x);
    int r2 = Find(y);
    if (r1 == r2) return false;
    parent[r1] = r2;
    return true;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    freopen("network.txt", "r", stdin);
    
    N = 40;
    for (int i = 1; i <= N; i ++) parent[i] = i;
    int all = 0;
    for (int i = 1; i <= N; i ++) {
        string s;
        getline(cin, s);
        s += ",";
        int x = 0, id = 1;
        for (auto j : s) {
            if (j == ',') {
                if (x != 0) edges.push_back(make_pair(x, make_pair(i, id)));
                if (x != 0 && id > i) {
                    cout << i << " " << id << " --> " << x << endl;
                    all += x;
                }
                id ++;
                x = 0;
            }
            else if (j != '-') {
                x = 10 * x + j - '0';
            }
        }
    }
    cout << "here" << endl;
    
    sort(edges.begin(), edges.end());
    int mst = 0;
    for (auto i : edges) {
        int l = i.first;
        int a = i.second.first;
        int b = i.second.second;
        cout << "now asking: " << a << " " << b << endl;
        if (Union(a, b)) mst += l;
    }
    cout << mst << endl;
    cout << all - mst << endl;
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
