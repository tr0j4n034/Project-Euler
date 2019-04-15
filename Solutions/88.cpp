//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/24/18.
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
#include <ctime>
#include <cassert>

using namespace std;

const int MAX = 12000 + 1;
const int UP = MAX << 2;

long long dp[MAX];
map<pair<int, int>, long long> m;

void update(long long &a, long long b) {
    if (a > b) a = b;
}
void go(long long product, long long sum, int steps, int last) {
    //if (m.count(make_pair(product, sum))) return;
    //m[make_pair(product, sum)] = 1;
    //if (steps + product - sum >= MAX) return;
    if (steps >= MAX) return;
    if (last > UP) return;
    //cout << "p = " << product << ", s = " << sum << ", steps = " << steps << " vs " << last << endl;
    if (product >= sum && steps + product - sum < MAX) {
        update(dp[steps + product - sum], product);
    }
    if (product > sum + MAX) return;
    long long p = product, s = sum;
    int ss = steps;
    for (int i = 0; ; i ++) {
        if (p - s > MAX) break;
        go(p, s, ss, last + 1);
        p *= last + 1;
        s += last + 1;
        ++ss;
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        dp[i] = 1LL << 60;
    }
    for (int i = 2; i < MAX; i ++) {
        go(i, i, 1, i - 1);
    }
    set<long long> s;
    for (int i = 2; i < MAX; i ++) {
        if (i < 103) cerr << i << " --> " << dp[i] << endl;
        s.insert(dp[i]);
        assert(dp[i] != (1LL << 60));
    }
    long long sum = 0;
    for (auto i : s) sum += i;
    
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
