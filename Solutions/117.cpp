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
    int n = 50;
    
    for (int i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1];
        if (i >= 2) dp[i] += dp[i - 2];
        if (i >= 3) dp[i] += dp[i - 3];
        if (i >= 4) dp[i] += dp[i - 4];
    }
    cout << dp[n] << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

