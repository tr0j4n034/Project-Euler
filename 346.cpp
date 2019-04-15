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
#include <map>
#include <utility>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX = 100000002;
const long long TOP = 1000000000000LL;
//const long long TOP = 1000;

long long get(int n, int b) {
    long long now = 0;
    for (int i = 1; i <= n; i ++) {
        if (1. * now * b > 1. * TOP) {
            now = TOP + 1;
            break;
        }
        now = now * b + 1;
    }
    return now;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    map<long long, int> m;
    for (int i = 3; i < 50; i ++) {
        for (int j = 2; j < 123456789; j ++) {
            long long now = get(i, j);
            if (now >= TOP) break;
            m[now] ++;
        }
    }
    long long sum = 0;
    sum += 1;
    for (auto i : m) {
        if (i.second > 0 && i.first < 50) {
            cout << i.first << endl;
        }
        if (i.second > 0) sum += i.first;
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
