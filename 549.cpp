//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/18/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 100000001;

int N = MAX - 1;
int lp[MAX], f[MAX];

int get(int n, int k) {
    int s = 0;
    while (n % k == 0) {
        s ++;
        n /= k;
    }
    return s;
}
int naive(int N) {
    int x = 1;
    for (int i = 1; i <= N; i ++) {
        x = x * i % N;
        if (x == 0) return i;
    }
    return -1;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) lp[i] = i;
    for (int i = 2; i * i < MAX; i ++) {
        if (lp[i] != i) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long result = 0;
    for (int i = 2; i <= N; i ++) {
        int need = get(i, lp[i]);
        int k = lp[i];
        int j = i;
        while (j % lp[i] == 0) j /= lp[i];
        while (1) {
            need -= get(k, lp[i]);
            if (need < 1) break;
            k += lp[i];
        }
        f[i] = max(k, f[j]);
        result += f[i];
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
