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

const int MAX = 101;

long long N = 100000000000000000LL - 1;

long long fib[MAX];
map<long long, long long> dp;

int getID(long long N) {
    int id = 0;
    for (int i = 1; i < MAX; i ++) {
        if (fib[i] >= N) {
            id = i;
            break;
        }
    }
    return id;
}
long long get(long long N) {
    //cout << N << endl;
    if (dp.count(N)) return dp[N];
    if (N < 1) return 0;
    else if(N == 1) return 1;
    int id = getID(N);
    if (fib[id] == N) return dp[N] = get(N - 1) + 1;
    else return dp[N] = get(fib[id - 1]) + N - fib[id - 1] + get(N - fib[id - 1]);
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < MAX; i ++) fib[i] = fib[i - 2] + fib[i - 1];
    
    cout << get(N) << endl;
    
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
