//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/25/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 50000;
const int N = 24;
const int MODULO = 1000000000;

int p[S];
int fib[N + 1];
long long dp[S];

int main() {
    fib[1] = 1;
    for (int i = 2; i <= N; i ++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cerr << "last = " << fib[N] << endl;
    
    for (int i = 2; i < S; i ++) {
        if (p[i]) {
            continue;
        }
        for (int j = i + i; j < S; j += i) {
            p[j] = 1;
        }
    }
    dp[0] = 1;
    for (int i = 2; i < S; i ++) {
        if (p[i]) {
            continue;
        }
        for (int j = i; j < S; j ++) {
            dp[j] += dp[j - i] * i;
            dp[j] %= MODULO;
        }
    }
    long long result = 0;
    for (int i = 2; i <= N; i ++) {
        result += dp[fib[i]];
        result %= MODULO;
    }
    cout << result << endl;
    
    return 0;
}

