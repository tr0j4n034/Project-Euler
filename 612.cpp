//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/6/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

const int N = 10;
const int M = 18;
const long long MODULO = 1000267129;

long long has[M + 1][1 << N], counts[1 << N];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i <= 9; i ++) {
        has[1][1 << i] ++;
    }
    for (int i = 1; i < M; i ++) {
        for (int j = 1; j < (1 << N); j ++) {
            for (int k = 0; k < 10; k ++) {
                int mask = j | (1 << k);
                has[i + 1][mask] += has[i][j];
            }
        }
    }
    for (int i = 1; i <= M; i ++) {
        for (int j = 0; j < (1 << N); j ++) {
            counts[j] += has[i][j];
        }
    }
    int ways = 0;
    for (int i = 0; i < 1024; i ++) {
        for (int j = i; j < 1024; j ++) {
            if (i & j) {
                if (i == j) {
                    if (counts[i] & 1) {
                        ways = (ways + 1LL * ((counts[i] - 1) / 2) % MODULO * (counts[i] % MODULO) % MODULO) % MODULO;
                    }
                    else {
                        ways = (ways + 1LL * (counts[i] / 2) % MODULO * ((counts[i] - 1) % MODULO)) % MODULO;
                    }
                }
                else ways = (ways + 1LL * (counts[i] % MODULO) * (counts[j] % MODULO) % MODULO) % MODULO;
            }
        }
    }
    cout << ways << endl;
    
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

