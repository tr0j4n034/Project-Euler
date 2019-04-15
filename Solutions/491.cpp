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

const int N = 20;

long long dp[N + 1][1 << 10][1 << 10][11];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 10; i ++) {
        dp[1][1 << i][0][i] = 1;
    }
    for (int i = 1, v = -1; i < N; i ++, v *= -1) {
        for (int j = 0; j < (1 << 10); j ++) {
            for (int k = 0; k < (1 << 10); k ++) {
                if ((j & k) != k) continue;
                for (int q = 0; q <= 10; q ++) {
                    for (int l = 0; l < 10; l ++) {
                        if (k & (1 << l)) continue;
                        if (j & (1 << l)) {
                            dp[i + 1][j][k | (1 << l)][(q + l * v + 110) % 11] += dp[i][j][k][q];
                        }
                        else {
                            dp[i + 1][j | (1 << l)][k][(q + l * v + 110) % 11] += dp[i][j][k][q];
                        }
                    }
                }
            }
        }
    }
    long long result = dp[N][(1 << 10) - 1][(1 << 10) - 1][0];
    
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
