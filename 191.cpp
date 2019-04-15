//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 105;

int N = 30;
long long dp[MAX][3][2]; // length, absent days, late count

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    dp[1][1][0] = 1;
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    
    for (int i = 2; i <= N; i ++) {
        for (int j = 0; j < 3; j ++) {
            for (int k = 0; k < 2; k ++) {
                for (int q = 0; q < 3; q ++) {
                    for (int l = 0; l < 2; l ++) {
                        if (k < l) continue;
                        if (j > 0 && j != q + 1) continue;
                        if (k != l && j != 0) continue;
                        cout << i << " vs absent = " << j << " latecount = " << k << " <--- " << i - 1 << ", " << q << " " << l << endl;
                        dp[i][j][k] += dp[i - 1][q][l];
                    }
                }
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 2; j ++) {
            result += dp[N][i][j];
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

