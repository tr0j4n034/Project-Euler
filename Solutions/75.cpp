//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/07/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 1500001;

// https://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples

int lp[MAX];
int ways[MAX];

void go(long long product, int id, vector<pair<int, int>> &v, int &r) {
    if (r % 2) return;
    if (id >= (int)v.size()) {
        if (((1LL * r * r) / 2) % product == 0) {
            long long s = product;
            long long t = (1LL * r * r) / 2 / s;
            long long x = r + s;
            long long y = r + t;
            long long z = r + s + t;
            if ( x <= y && x + y + z < MAX) {
                ways[x + y + z] ++;
            }
        }
        return;
    }
    long long p = 1;
    for (int i = 0; i <= v[id].second; i ++) {
        go(product * p, id + 1, v, r);
        p *= v[id].first;
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    for (int i = 2; i < MAX; i ++) {
        vector<pair<int, int>> v;
        int j = i;
        while (j > 1) {
            int d = lp[j];
            v.push_back(make_pair(d, 0));
            while (j % d == 0) {
                j /= d;
                v.back().second ++;
            }
            v.back().second <<= 1;
        }
        go(1, 0, v, i);
    }
    int s = 0;
    for (int i = 1; i < MAX; i ++) {
        if (ways[i] == 1) {
            if (i < 100) cerr << i << endl;
            s ++;
        }
    }
    cout << ways[120] << endl;
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
