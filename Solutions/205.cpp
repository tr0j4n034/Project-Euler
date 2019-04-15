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

using namespace std;

const int MAX = 700000005;

long double dp[10][50], dp2[10][50];

int main() {
    dp[0][0] = 1;
    dp2[0][0] = 1;
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 36; j ++) {
            for (int k = 1; k <= 4; k ++) {
                if (k <= j) {
                    dp[i][j] += dp[i - 1][j - k] * (1. / 4.);
                }
            }
        }
    }
    for (int i = 1; i <= 6; i ++) {
        for (int j = 1; j <= 36; j ++) {
            for (int k = 1; k <= 6; k ++) {
                if (k <= j) {
                    dp2[i][j] += dp2[i - 1][j - k] * (1. / 6.);
                }
            }
        }
    }
    long double result = 0.;
    for (int i = 1; i <= 36; i ++) {
        for (int j = 1; j < i; j ++) {
            result += dp[9][i] * dp2[6][j];
        }
    }
    cout.precision(7);
    cout << fixed << result << endl;
    
    return 0;
}
