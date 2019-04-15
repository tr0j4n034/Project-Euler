//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/17/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

const int MAX = 30001;

map<long long, int> f;

int check(long long N) {
    long long M = N, r = 0;
    while (N > 0) {
        r = 10 * r + N % 10;
        N /= 10;
    }
    return M == r ? 1 : 0;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < 1000; i ++) {
        for (int j = 2; j < MAX; j ++) {
            long long now = 1LL * i * i * i + 1LL * j * j;
            if (check(now)) f[now] ++;
        }
    }
    long long sum = 0;
    for (auto i : f) {
        if (i.second == 4) cout << i.first << endl;
        if (i.second == 4) sum += i.first;
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
