//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 105;

long long dp[MAX];

/// 107 114

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int l = 50;
    dp[0] = 1;
    for (int i = 1; i <= l; i ++) {
        dp[i] = dp[i - 1];
        for (int j = 3; j <= l; j ++) {
            if (j + 1 > i) break;
            dp[i] += dp[i - j - 1];
        }
        if (i > 2) dp[i] += 1;
    }
    cout << dp[l] << endl;
    
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
