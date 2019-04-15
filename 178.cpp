//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/13/18.
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

long long dp[41][1 << 10][10];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 10; i ++) dp[1][1 << i][i] = 1;
    for (int i = 2; i <= 40; i ++) {
        for (int j = 0; j < (1 << 10); j ++) {
            for (int k = 0; k < 10; k ++) {
                if (j & (1 << k)) {
                    if (k > 0) dp[i][j][k] += dp[i - 1][j][k - 1] + dp[i - 1][j ^ (1 << k)][k - 1];
                    if (k < 9) dp[i][j][k] += dp[i - 1][j][k + 1] + dp[i - 1][j ^ (1 << k)][k + 1];
                }
            }
        }
    }
    
    long long result = 0;
    for (int i = 1; i <= 40; i ++) {
        for (int j = 0; j < 10; j ++) {
            result += dp[i][(1 << 10) - 1][j];
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
