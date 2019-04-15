//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/17/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int S = 100;

long double dp[S][S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int N = 15;
    dp[0][0] = 1.;
    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j <= i; j ++) {
            dp[i][j] = dp[i - 1][j] * i / (i + 1);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] / (i + 1);
        }
    }
    long double p = 0.;
    for (int i = 1; i <= N; i ++) {
        if (i + i > N) p += dp[N][i];
    }
    cout.precision(10);
    cout << fixed << p << endl;
    
    long double result = 1. / p;
    cout << fixed << (int)result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

