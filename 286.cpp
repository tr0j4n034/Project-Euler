//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/13/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 51;
const int N = 20;

long double dp[S][S];

long double get(long double q) {
    for (int i = 0; i < S; i ++) {
        for (int j = 0; j < S; j ++) {
            dp[i][j] = 0.;
        }
    }
    dp[0][0] = 1.;
    for (int i = 1; i < S; i ++) {
        for (int j = 0; j <= i; j ++) {
            dp[i][j] = dp[i - 1][j] * (1. * i / q);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * (1. - 1. * i / q);
        }
    }
    return dp[S - 1][N];
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long double low = 50. + 1.e-9, high = 54;
    for (int i = 0; i < 50; i ++) {
        long double middle = (low + high) / 2.;
        if (get(middle) > 0.02) {
            low = middle;
        }
        else {
            high = middle;
        }
    }
    cout.precision(10);
    cout << fixed << low << endl;
    cout << fixed << get(low) << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

