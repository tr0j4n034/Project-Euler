//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/16/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 200001;

int legendre(int N, int M) {
    int sum = 0;
    for (long long i = M; i <= N; i *= M) {
        sum += N / i;
    }
    return sum;
}

int f[6][S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 0; i < S; i ++) {
        f[2][i] = legendre(i, 2);
        f[5][i] = legendre(i, 5);
    }
    auto getCount = [](int N, int K, int M) {
        return f[M][N] - f[M][K] - f[M][N - K];
    };
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int N = 200000;
    long long ways = 0;
    for (int i = 0; i <= N; i ++) {
        int has[6] = {0};
        has[2] = getCount(N, i, 2);
        has[5] = getCount(N, i, 5);
        if (has[2] > 11 && has[5] > 11) {
            ways += N - i;
            continue;
        }
        for (int j = 0; j <= N - i; j ++) {
            if (has[2] + getCount(N - i, j, 2) > 11 && has[5] + getCount(N - i, j, 5) > 11) {
                ways ++;
            }
        }
    }
    cout << ways << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

