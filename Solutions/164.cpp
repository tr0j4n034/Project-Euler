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

const int MAX = 11111;

long long dp[30][10][10][10];

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (int k = 0; k < 10; k ++) {
                if (i + j + k > 9) continue;
                dp[3][i][j][k] ++;
            }
        }
    }
    for (int i = 4; i <= 20; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (int k = 0; k < 10; k ++) {
                for (int q = 0; q < 10; q ++) {
                    if (j + k + q > 9) continue;
                    for (int l = 0; l < 10; l ++) {
                        if (l + j + k > 9) continue;
                        dp[i][j][k][q] += dp[i - 1][l][j][k];
                    }
                }
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (int k = 0; k < 10; k ++) {
                result += dp[20][i][j][k];
            }
        }
    }
    cout << result << endl;
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
