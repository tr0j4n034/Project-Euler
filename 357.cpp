//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/11/18.
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
#include <bitset>
#include <cassert>

using namespace std;

const int MAX = 100000002;

bool p[MAX + 1], f[MAX + 1];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) {
            if (p[i + j / i]) f[j] = 1;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long sum = 0;
    for (int i = 1; i < MAX - 1; i ++) {
        if (!f[i]) {
            sum += i;
        }
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
