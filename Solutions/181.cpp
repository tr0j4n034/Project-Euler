//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/13/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int B = 60;
const int W = 40;

long long dp[B + 1][W + 1][B + 1][W + 1];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= B; i ++) {
        for (int j = 0; j <= W; j ++) {
            if (i == 0 && j == 0) continue;
            for (int k = 0; k <= i; k ++) {
                for (int q = 0; q <= j; q ++) {
                    if (k == 0 && q == 0) continue;
                    for (int l = 0; l < k; l ++) {
                        for (int m = 0; m <= j; m ++) {
                            dp[i][j][k][q] += dp[i - k][j - q][l][m];
                        }
                    }
                    for (int m = 0; m <= q; m ++) {
                        dp[i][j][k][q] += dp[i - k][j - q][k][m];
                    }
                }
            }
        }
    }
    long long result = 0;
    for (int i = 0; i <= B; i ++) {
        for (int j = 0; j <= W; j ++) {
            result += dp[B][W][i][j];
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
