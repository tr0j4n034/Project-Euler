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
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 205;

int N, M;
long long dp[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
   
    M = 50;
    N = 168;
    dp[0] = 1;
    for (int i = 1; i <= N; i ++) {
        dp[i] = dp[i - 1];
        if (i >= M) dp[i] += 1;
        for (int j = M; i - j - 1 >= 0; j ++) {
            dp[i] += dp[i - j - 1];
        }
    }
    cout << dp[N] << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
