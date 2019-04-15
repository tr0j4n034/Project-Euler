//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/8/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

const int MAX = 105;

long long dp[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    dp[0] = 1;
    int l = 2, n = 50;
    
    for (int i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1];
        if (i >= l) dp[i] += dp[i - l];
    }
    long long r1 = dp[n] - 1;
    
    
    dp[0] = 1;
    l = 3, n = 50;
    
    for (int i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1];
        if (i >= l) dp[i] += dp[i - l];
    }
    long long r2 = dp[n] - 1;
    
    dp[0] = 1;
    l = 4, n = 50;
    
    for (int i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1];
        if (i >= l) dp[i] += dp[i - l];
    }
    long long r3 = dp[n] - 1;
    
    cout << r1 + r2 + r3 << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

