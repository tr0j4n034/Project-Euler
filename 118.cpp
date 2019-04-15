//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/12/18.
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
#include <utility>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

const int MAX = 12005;

map<int, int> cache;

int isPrime(int N) {
    if (cache.count(N)) return cache[N];
    if (N < 2) return 0;
    for (int i = 2; i * i <= N; i ++) {
        if (N % i == 0) return cache[N] = 0;
    }
    return cache[N] = 1;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    vector<int> v(9);
    iota(v.begin(), v.end(), 1);
    set<set<int>> s;
    do {
        for (int i = 0; i < (1 << 8); i ++) {
            set<int> current;
            int x = 0;
            int good = 1;
            for (int j = 0; j < 8; j ++) {
                x = 10 * x + v[j];
                if (i & (1 << j)) {
                    if (!isPrime(x)) {
                        good = 0;
                        break;
                    }
                    current.insert(x);
                    x = 0;
                }
            }
            x = 10 * x + v[8];
            if (!isPrime(x)) good = 0;
            else current.insert(x);
            if (good) {
                s.insert(current);
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    
    cout << (int)s.size() << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
