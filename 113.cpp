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

long long dp[2][MAX][10];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 10; i ++) {
        dp[0][1][i] = 1;
        dp[1][1][i] = 1;
    }
    int l = 100;
    for (int i = 2; i <= l; i ++) {
        for (int j = 0; j <= 9; j ++) {
            for (int k = 0; k <= j; k ++) {
                dp[0][i][j] += dp[0][i - 1][k];
            }
            for (int k = j; k <= 9; k ++) {
                dp[1][i][j] += dp[1][i - 1][k];
            }
        }
    }
    long long result = 0;
    for (int i = 1; i <= l; i ++) {
        for (int j = 0; j < 10; j ++) {
            result += dp[0][i][j] + dp[1][i][j];
        }
    }
    result -= 9 * l;
    
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

