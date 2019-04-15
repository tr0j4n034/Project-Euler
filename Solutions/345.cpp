//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/6/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 20000000;

int N;

int a[15][15];
int dp[15][1 << 15];

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    //cin >> N;
    N = 15;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i ++) {
        dp[0][1 << i] = a[0][i];
    }
    for (int i = 1; i < N; i ++) {
        for (int j = 0; j < (1 << N); j ++) {
            for (int k = 0; k < N; k ++) {
                if (j & (1 << k)) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j ^ (1 << k)] + a[i][k]);
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < (1 << N); i ++) {
        result = max(result, dp[N - 1][i]);
    }
    cout << result << endl;
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
